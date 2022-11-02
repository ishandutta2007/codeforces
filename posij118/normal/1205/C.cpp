#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool a[n][n];
    a[0][0] = 1;
    a[n - 1][n - 1] = 0;
    a[1][0] = 0;
    a[0][1] = 0;

    for(int i = 2; i<=2*n - 4; i+=2){
        for(int j = max(0, i - n + 1); j<=min(n - 1, i); j++){
            int x = j;
            int y = i - j;
            bool ans;

            if(x - 2 >= 0){
                cout << "? " << x - 1 << " " << y + 1 << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x - 2][y] ^ (!ans);
            }

            else if(y - 2 >= 0){
                cout << "? " << x + 1 << " " << y - 1 << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x][y - 2] ^ (!ans);
            }

            else{
                cout << "? " << x  << " " << y << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x - 1][y - 1] ^ (!ans);
            }
        }
    }

    for(int i = 3; i<=2*n - 3; i+=2){
        for(int j = max(0, i - n + 1); j<=i/2; j++){
            int x = j;
            int y = i - j;
            bool ans;

            if(x - 2 >= 0){
                cout << "? " << x - 1 << " " << y + 1 << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x - 2][y] ^ (!ans);
            }

            else if(x - 1 >= 0 && y - 1 >= 0){
                cout << "? " << x  << " " << y << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x - 1][y - 1] ^ (!ans);
            }

            else if(y - 2 >= 0){
                cout << "? " << x + 1 << " " << y - 1 << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x][y - 2] ^ (!ans);
            }
        }
    }

    for(int i = 3; i<=2*n - 3; i+=2){
        for(int j = i/2 + 1; j<=min(i, n - 1); j++){
            int x = j;
            int y = i - j;
            bool ans;

            if(y - 2 >= 0){
                cout << "? " << x + 1 << " " << y - 1 << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x][y - 2] ^ (!ans);
            }

            else if(x - 1 >= 0 && y - 1 >= 0){
                cout << "? " << x  << " " << y << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x - 1][y - 1] ^ (!ans);
            }

            else if(x - 2 >= 0){
                cout << "? " << x - 1 << " " << y + 1 << " " << x + 1 << " " << y + 1 << endl;
                fflush(stdout);
                cin >> ans;
                a[x][y] = a[x - 2][y] ^ (!ans);
            }
        }
    }
    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */


    for(int i = 0; i<=2*n - 6; i+=2){
        int ans;
        int x[5], y[5];
        for(int j = 0; j<5; j++){
            x[j] = max(0, i + j - n + 1);
            y[j] = i + j - x[j];
        }

        if(a[x[0]][y[0]] ^ a[x[4]][y[4]]){
            if(a[x[1]][y[1]] != a[x[3]][y[3]]){
                if(a[x[0]][y[0]] != a[x[2]][y[2]]){
                    cout << "? " << x[0] + 1 << " " << y[0] + 1 << " " << x[3] + 1 << " " << y[3] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[0][1] = 1 ^ ans ^ a[x[0]][y[0]] ^ a[x[3]][y[3]];
                }

                else{
                    cout << "? " << x[1] + 1 << " " << y[1] + 1 << " " << x[4] + 1 << " " << y[4] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[0][1] = 1 ^ ans ^ a[x[1]][y[1]] ^ a[x[4]][y[4]];
                }
            }

            else{
                if(a[x[0]][y[0]] == a[x[2]][y[2]]){
                    cout << "? " << x[0] + 1 << " " << y[0] + 1 << " " << x[3] + 1 << " " << y[3] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[0][1] = 1 ^ ans ^ a[x[0]][y[0]] ^ a[x[3]][y[3]];
                }

                else{
                    cout << "? " << x[1] + 1 << " " << y[1] + 1 << " " << x[4] + 1 << " " << y[4] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[0][1] = 1 ^ ans ^ a[x[1]][y[1]] ^ a[x[4]][y[4]];
                }
            }
            break;
        }
    }

    for(int i = 0; i<=2*n - 6; i+=2){
        int ans;
        int x[5], y[5];
        for(int j = 0; j<5; j++){
            y[j] = max(0, i + j - n + 1);
            x[j] = i + j - y[j];
        }

        if(a[x[0]][y[0]] ^ a[x[4]][y[4]]){
            if(a[x[1]][y[1]] != a[x[3]][y[3]]){
                if(a[x[0]][y[0]] != a[x[2]][y[2]]){
                    cout << "? " << x[0] + 1 << " " << y[0] + 1 << " " << x[3] + 1 << " " << y[3] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[1][0] = 1 ^ ans ^ a[x[0]][y[0]] ^ a[x[3]][y[3]];
                }

                else{
                    cout << "? " << x[1] + 1 << " " << y[1] + 1 << " " << x[4] + 1 << " " << y[4] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[1][0] = 1 ^ ans ^ a[x[1]][y[1]] ^ a[x[4]][y[4]];
                }
            }

            else{
                if(a[x[0]][y[0]] == a[x[2]][y[2]]){
                    cout << "? " << x[0] + 1 << " " << y[0] + 1 << " " << x[3] + 1 << " " << y[3] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[1][0] = 1 ^ ans ^ a[x[0]][y[0]] ^ a[x[3]][y[3]];
                }

                else{
                    cout << "? " << x[1] + 1 << " " << y[1] + 1 << " " << x[4] + 1 << " " << y[4] + 1 << endl;
                    fflush(stdout);
                    cin >> ans;
                    a[1][0] = 1 ^ ans ^ a[x[1]][y[1]] ^ a[x[4]][y[4]];
                }
            }
            break;
        }
    }

    cout << "!" << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(i + j == 1 || (i + j) % 2 == 0){
                cout << a[i][j];
            }

            else if(i < j) cout << (a[i][j] ^ a[0][1]);
            else cout << (a[i][j] ^ a[1][0]);
        }
        cout << endl;
    }
}