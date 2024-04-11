#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
char a[N][N];
bool used[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            cin >> (a[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            fill(used[i] + 0, used[i] + m + 2, 0);
        }
        if (n == 1 || m == 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    a[i][j] = 'X';
                }
            }
        } else {
            for (int i = 3; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == 'X') {
                        if (a[i - 2][j] == 'X') {
                            a[i - 1][j] = 'X';
                            used[i - 2][j] = used[i - 1][j] = 1;
                        } else {
                            if (a[i - 2][j - 1] == 'X' && a[i - 2][j + 1] == 'X') { //both 
                                a[i - 2][j] = 'X';
                                if (!used[i - 2][j - 1]) {
                                    a[i - 1][j] = 'X';
                                    used[i - 1][j] = 1;
                                }
                                used[i - 2][j - 1] = used[i - 2][j] = used[i - 2][j + 1] = 1;
                            } else if (a[i - 2][j - 1] == 'X') { // left
                                if (!used[i - 2][j - 1]) {
                                    a[i - 2][j] = a[i - 1][j] = 'X';
                                    used[i - 2][j - 1] = used[i - 2][j] = used[i - 1][j] = 1;
                                }
                            } else if (a[i - 2][j + 1] == 'X') {// right
                                a[i - 2][j] = a[i - 1][j] = 'X';
                                used[i - 2][j + 1] = used[i - 2][j] = used[i - 1][j] = 1;
                            }
                        }
                    }
                }

                for (int j = 1; j <= m; j++) {
                    if (a[i - 2][j] == 'X' && !used[i - 2][j]) {
                        a[i - 1][j] = 'X';
                    }
                }
            }
        
            for (int j = 1; j <= m; j++) {
                a[n][j] = 'X';
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << (a[i] + 1) << '\n';
        }
    } 
    return 0;
}