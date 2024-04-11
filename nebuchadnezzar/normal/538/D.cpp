#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 55;

int n;
string s;
int field[MAXN][MAXN];
int ans[MAXN * 2][MAXN * 2];
int res[MAXN][MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'o') {
                field[i][j] = 1;
            }
            if (s[j] == 'x') {
                field[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            ans[i][j] = 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] != 1) {
                continue;
            }
            for (int i2 = 0; i2 < n; ++i2) {
                for (int j2 = 0; j2 < n; ++j2) {
                    if (field[i2][j2] == 0) {
                        ans[i2 - i + n - 1][j2 - j + n - 1] = 0;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] != 1) {
                continue;
            }
            for (int i2 = 0; i2 < 2 * n - 1; ++i2) {
                for (int j2 = 0; j2 < 2 * n - 1; ++j2) {
                    int ni = i + i2 - n + 1;
                    int nj = j + j2 - n + 1;
                    if (0 <= ni && ni < n && 0 <= nj && nj < n && ans[i2][j2]) {
                        res[ni][nj] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //cout << res[i][j];
            if (field[i][j] == 2 && !res[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
        //cout << endl;
    }


    cout << "YES\n";
    ans[n - 1][n - 1] = 2;
    string qwe = ".xo";
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            cout << qwe[ans[i][j]];
        }
        cout << endl;
    }

    return 0;
}