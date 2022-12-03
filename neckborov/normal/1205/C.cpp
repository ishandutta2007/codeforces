#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 51;

int a[N][N], b[N][N];
int dp[N][N][N][N], dp1[N][N][N][N];
int kek;

void print(int n) {
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                cout << a[i][j] - 1;
            } else {
                cout << ((a[i][j] - 1) ^ kek);
            }
        }
        cout << endl;
    }
    exit(0);
}

int ask(int x1, int y1, int x2, int y2) {
    cout << "? ";
    cout << x1 << ' ' << y1 << ' ';
    cout << x2 << ' ' << y2 << endl;
    int r;
    cin >> r;
    return r;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    a[1][1] = 2;
    a[n][n] = 1;
    a[1][2] = 1;
    a[2][3] = (ask(1, 2, 2, 3) ? 1 : 2);
    a[2][1] = (ask(2, 1, 2, 3) ? a[2][3] : 3 - a[2][3]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                continue;
            }
            if (j >= 2 && a[i][j - 2]) {
                a[i][j] = (ask(i, j - 2, i, j) ? a[i][j - 2] : 3 - a[i][j - 2]);
                continue;
            }
            if (i >= 2 && a[i - 2][j]) {
                a[i][j] = (ask(i - 2, j, i, j) ? a[i - 2][j] : 3 - a[i - 2][j]);
                continue;
            }
            if (a[i - 1][j - 1]) {
                a[i][j] = (ask(i - 1, j - 1, i, j) ? a[i - 1][j - 1] : 3 - a[i - 1][j - 1]);
                continue;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) & 1) {
                b[i][j] = 3 - a[i][j];
            } else {
                b[i][j] = a[i][j];
            }
        }
    }
    vector<int> dx = { 0, 1 };
    vector<int> dy = { 1, 0 };
    for (int q = 0; q <= n - 1; q++) {
        for (int w = 0; w <= n - 1; w++) {
            for (int i = 1; i <= n - q; i++) {
                for (int j = 1; j <= n - w; j++) {
                    int x = i + q; 
                    int y = j + w;
                    if (x == i && y == j) {
                        dp[i][j][x][y] = dp1[i][j][x][y] = 1;
                        continue;
                    }
                    if ((x == i + 1 && y == j) || (x == i && y == j + 1)) {
                        dp[i][j][x][y] = (a[i][j] == a[x][y]);
                        dp1[i][j][x][y] = (b[i][j] == b[x][y]);
                        continue;
                    }
                    for (int t1 = 0; t1 < 2; t1++) {
                        for (int t2 = 0; t2 < 2; t2++) {
                            dp[i][j][x][y] |= (a[i][j] == a[x][y]) && dp[i + dx[t1]][j + dy[t1]][x - dx[t2]][y - dy[t2]];
                            dp1[i][j][x][y] |= (b[i][j] == b[x][y]) && dp1[i + dx[t1]][j + dy[t1]][x - dx[t2]][y - dy[t2]];
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = i; x <= n; x++) {
                for (int y = j; y <= n; y++) {
                    if ((x - i + y - j + 1) & 1 || x - i + y - j <= 1) {
                        continue;
                    }
                    if (dp[i][j][x][y]) {
                        kek = 1 - ask(i, j, x, y);
                        print(n);
                    }
                    if (dp1[i][j][x][y]) {
                        kek = ask(i, j, x, y);
                        print(n);
                    }
                }
            }
        }
    }
    return 0;
}