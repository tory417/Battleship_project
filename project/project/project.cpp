#include <iostream>
#include <ctime>
using namespace std;
const int n = 10;
int ship_comp = 1;
int ship_player = 1;//переменная будет нумеровать каждый корабль, чтобы потом отслеживать уровень затопленности кораблей
int comp_life[n] = { 0 };
int player_life[n] = { 0 };
void showFleet(int array[n][n]) {
    cout << "\t";
    char col = 'a';
    for (int i = 0; i < n; i++) {
        cout << col++ << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < n; j++) {
            if (array[i][j] == 0) cout << "-" << "\t";
            else cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void showPlayer(int array[n][n], int buffer[n][n]) {
    cout << "\t";
    char col = 'a';
    for (int i = 0; i < n; i++) {
        cout << col++ << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < n; j++) {
            if (buffer[i][j] == 1) {
                if (array[i][j] == -1) cout << "X" << "\t";
                else if (array[i][j] == 0) cout << "-" << "\t";
            }
            else {
                if (array[i][j] > 0) cout << array[i][j] << "\t";
                else cout << " " << "\t";
            }
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
}

void showComp(int array[n][n], int buffer[n][n]) {
    cout << "\t";
    char col = 'a';
    for (int i = 0; i < n; i++) {
        cout << col++ << "\t";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t";
        for (int j = 0; j < n; j++) {
            if (buffer[i][j] == 1) {
                if (array[i][j] == 0) cout << "_" << "\t";
                else if (array[i][j] == -1) cout << "X" << "\t"; //отображается Х - подбитая часть корабля
                //else cout << array[i][j] << "\t";
            }
            else cout << "." << "\t";
        }
        cout << endl;
        cout << endl;
    }
    cout << endl;
}

int transformSymb(char x) {
    if (x == 'a') return 0;
    if (x == 'b') return 1;
    if (x == 'c') return 2;
    if (x == 'd') return 3;
    if (x == 'e') return 4;
    if (x == 'f') return 5;
    if (x == 'g') return 6;
    if (x == 'h') return 7;
    if (x == 'i') return 8;
    if (x == 'j') return 9;
}

bool check(int field[n][n]) {
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] >= 1) {
                flag=true; //еще есть живые корабли
                break;
            }
        }
    }
    return flag;
}

void setShips(int array[n][n], int numb_ships, int numb_decks) {
    int x, y, temp_x, temp_y; 
    char symb_y;
    int dir;
    int n_ships = 0;
    bool ship_in_map;
    while (n_ships < numb_ships) {
        ship_in_map = 1;
        cout << "Введите начальную позицию для " << numb_decks << "-палубного корабля:";
        cin >> x;
        cin >> symb_y;
        y = transformSymb(symb_y);
        temp_x = x;
        temp_y = y;
        cout << "Выберите направление для постановки корабля: 1 - вправо, 2 - влево, 3 - вверх, 4 - вниз:";
        cin >> dir;
        switch (dir) {
        case 1: {
            for (int i = 0; i < numb_decks; i++) {
                if ((x-1) < 0 || y < 0 || (x-1) >= n || y >= n || array[x-1][y] >= 1 || array[x-1][y - 1] >= 1 || array[x-1][y + 1] >= 1 || array[x - 2][y] >= 1 || array[x][y] >= 1 || array[x - 2][y - 1] >= 1 || array[x - 2][y + 1] >= 1 || array[x][y - 1] >= 1 || array[x][y + 1] >= 1) {
                    ship_in_map = 0;
                }
                y++;
            }
            break;
        }
        case 2: {
            for (int i = 0; i < numb_decks; i++) {
                if ((x - 1) < 0 || y < 0 || (x - 1) >= n || y >= n || array[x - 1][y] >= 1 || array[x - 1][y - 1] >= 1 || array[x - 1][y + 1] >= 1 || array[x - 2][y] >= 1 || array[x][y] >= 1 || array[x - 2][y - 1] >= 1 || array[x - 2][y + 1] >= 1 || array[x][y - 1] >= 1 || array[x][y + 1] >= 1) {
                    ship_in_map = 0;
                }
                y--;
            }
            break;
        }
        case 3: {
            for (int i = 0; i < numb_decks; i++) {
                if ((x - 1) < 0 || y < 0 || (x - 1) >= n || y >= n || array[x - 1][y] >= 1 || array[x - 1][y - 1] >= 1 || array[x - 1][y + 1] >= 1 || array[x - 2][y] >= 1 || array[x][y] >= 1 || array[x - 2][y - 1] >= 1 || array[x - 2][y + 1] >= 1 || array[x][y - 1] >= 1 || array[x][y + 1] >= 1) {
                    ship_in_map = 0;
                }
                x--;
            }
            break;
        }
        case 4: {
            for (int i = 0; i < numb_decks; i++) {
                if ((x - 1) < 0 || y < 0 || (x - 1) >= n || y >= n || array[x - 1][y] >= 1 || array[x - 1][y - 1] >= 1 || array[x - 1][y + 1] >= 1 || array[x - 2][y] >= 1 || array[x][y] >= 1 || array[x - 2][y - 1] >= 1 || array[x - 2][y + 1] >= 1 || array[x][y - 1] >= 1 || array[x][y + 1] >= 1) {
                    ship_in_map = 0;
                }
                x++;
            }
            break;
        }
        }
        if (ship_in_map == 0) cout << "Здесь невозможно поставить корабль, выберите другую позицию..." << endl;
        if (ship_in_map == 1) {
            x = temp_x;
            y = temp_y;
            switch (dir) {
            case 1: {
                for (int i = 0; i < numb_decks; i++) {
                    array[x - 1][y++] = ship_player;
                }
                break;
            }
            case 2: {
                for (int i = 0; i < numb_decks; i++) {
                    array[x - 1][y--] = ship_player;
                }
                break;
            }
            case 3: {
                for (int i = 0; i < numb_decks; i++) {
                    array[x - 1][y] = ship_player;
                    x--;
                }
                break;
            }
            case 4: {
                for (int i = 0; i < numb_decks; i++) {
                    array[x - 1][y] = ship_player;
                    x++;
                }
                break;
            }
            }
            player_life[ship_player] = numb_decks;
            ship_player++;
            n_ships++;
            showFleet(array);
        }
    }
}
   
void shipGeneration(int array[n][n], int numb_ships, int numb_decks) {
    int x, y;
    int n_ships = 0;
    while (n_ships < numb_ships) {
        x = rand() % n; 
        y = rand() % n;
        int temp_x = x, temp_y = y;
        bool staging = true;
        int dir = 0; 
        dir = rand() % 4; 

        //проверка возможности поставить корабль в ту или иную ячейку
        for (int i = 0; i < numb_decks; i++) {
            if (x < 0 || y < 0 || x >= n || y >= n) {
                staging = false;
                break;
            }

            if (array[x][y] >= 1 || array[x][y - 1] >= 1 || array[x][y + 1] >= 1 || array[x - 1][y] >= 1 || array[x + 1][y] >= 1 || array[x - 1][y - 1] >= 1 || array[x - 1][y + 1] >= 1 || array[x + 1][y - 1] >= 1 || array[x + 1][y + 1] >= 1) {
                staging = false;
                break;
            }

            switch (dir) {
            case 0: {
                y++;
                break;
            }
            case 1: {
                y--;
                break;
            }
            case 2: {
                x++;
                break;
            }
            case 3: {
                x--;
                break;
            }
            }
        }

        if (staging == true) {
            x = temp_x;
            y = temp_y;
            for (int i = 0; i < numb_decks; i++) {//количество повторений зависит от числа палуб корабля 
                array[x][y] = ship_comp;
                switch (dir) {
                case 0: {
                    y++;
                    break;
                }
                case 1: {
                    y--;
                    break;
                }
                case 2: {
                    x++;
                    break;
                }
                case 3: {
                    x--;
                    break;
                }
                }
            }
            comp_life[ship_comp] = numb_decks; //записывает, сколько палуб имеется в данном корабле
            ship_comp++; //увеличиваем нумерацию для следующего корабля
            n_ships++;
        }
    }
}

int shooting(int x, int y, int field[n][n], int buffer[n][n], int life[n]) {
    int result = 0;
    if (field[x - 1][y] >= 1) {
        life[field[x - 1][y]]--; // если попадаем по кораблю, то в соответствующей ячейке массива из кораблей уменьшает на 1 количество оставшихся в живых палуб
        if (life[field[x - 1][y]] <= 0) {
            result = 2;
            /*if (field[x - 2][y - 1] == 0) field[x - 2][y - 1] = -2;
            if (field[x - 2][y] == 0) field[x - 2][y] = -2;
            if (field[x - 2][y + 1] == 0) field[x - 2][y + 1] = -2;
            if (field[x][y - 1] == 0) field[x][y - 1] = -2;
            if (field[x][y + 1] == 0) field[x][y + 1] = -2;
            if (field[x][y - 1] == 0) field[x][y - 1] = -2;
            if (field[x][y] == 0) field[x][y] = -2;
            if (field[x][y + 1] == 0) field[x][y + 1] = -2;*/
        }
        else {
            result = 1;
        }
        field[x - 1][y] = -1;//помечаем палубу, в которую попали, чтобы при повторном выстреле в неё же не писал снова Попал, а будет написано уже Мимо
    }
    buffer[x - 1][y] = 1;
    return result;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int comp_field[n][n] = { 0 };
    int player_field[n][n] = { 0 };
    int comp_double[n][n];
    int player_double[n][n];
    srand(time(NULL));

    showFleet(player_field);
    setShips(player_field, 1, 4);
    setShips(player_field, 2, 3);
    setShips(player_field, 3, 2);
    setShips(player_field, 4, 1);

    shipGeneration(comp_field, 1, 4);
    shipGeneration(comp_field, 2, 3);
    shipGeneration(comp_field, 3, 2);
    shipGeneration(comp_field, 4, 1);
    //showFleet(comp_field);

    bool flag = 1, win = 0;
    int x, y;
    char symb_y;
    int result_shot=3;
    while (win!=1) {
        do {
            if (flag == 1) {
                if (result_shot == 2) {
                    bool check_life = check(comp_field);
                    if (check_life == 0) {
                        cout << "Вы победили!" << endl;
                        showComp(comp_field, comp_double);
                        win = 1;
                        break;
                    }
                }
                if(win==0) {
                    cout << "Поле противника:" << endl;
                    showComp(comp_field, comp_double);
                    cout << "Введите координаты для выстрела:";
                    cin >> x;
                    cin >> symb_y;
                    y = transformSymb(symb_y);
                    result_shot = shooting(x, y, comp_field, comp_double, comp_life);
                }
            }
            else {
                if (result_shot == 2) {
                    bool check_life = check(player_field);
                    if (check_life == 0) {
                        cout << "Компьютер выиграл!" << endl;
                        showPlayer(player_field, player_double);
                        win = 1;
                        break;
                    }
                }
                if (win == 0) {
                    cout << "Ваше поле:" << endl;
                    showPlayer(player_field, player_double);
                    cout << "Ходит компьютер: ";
                    if (result_shot == 1) {
                        int dir = rand() % 4;
                        switch (dir) {
                        case 0: {
                            y++;
                            break;
                        }
                        case 1: {
                            y--;
                            break;
                        }
                        case 2: {
                            x++;
                            break;
                        }
                        case 3: {
                            x--;
                            break;
                        }
                        }
                    }
                    else {
                        x = rand() % n + 1;
                        y = rand() % n;
                    }
                    if (y == 0) symb_y = 'a';
                    if (y == 1) symb_y = 'b';
                    if (y == 2) symb_y = 'c';
                    if (y == 3) symb_y = 'd';
                    if (y == 4) symb_y = 'e';
                    if (y == 5) symb_y = 'f';
                    if (y == 6) symb_y = 'g';
                    if (y == 7) symb_y = 'h';
                    if (y == 8) symb_y = 'i';
                    if (y == 9) symb_y = 'j';
                    cout << x << ", " << symb_y << endl;
                    result_shot = shooting(x, y, player_field, player_double, player_life);
                }
            }
            if (result_shot == 1) cout << "Ранил!" << endl;
            else if (result_shot == 2) cout << "Убил!" << endl;
            else cout << "Мимо" << endl;
        } while (result_shot!=0);
        flag = !flag;
    }
}


