#include <iostream>

using namespace std;

int n;
string s[55];
int c[200][200];
int d[55][55];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != 'o') continue;
            for (int a = -n+1; a <= n-1; a++) {
                for (int b = -n+1; b <= n-1; b++) {
                    bool ok = false;
                    if (i+a < 0 || i+a >= n) ok = true;
                    if (j+b < 0 || j+b >= n) ok = true;
                    if (!ok && s[i+a][j+b] != '.') ok = true;
                    if (!ok) c[a+n][b+n] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != 'o') continue;
            for (int a = -n+1; a <= n-1; a++) {
                for (int b = -n+1; b <= n-1; b++) {
                    if (i+a < 0 || i+a >= n) continue;
                    if (j+b < 0 || j+b >= n) continue;
                    if (c[a+n][b+n]) continue;
                    d[i+a][j+b] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'x' && d[i][j] == 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int a = -n+1; a <= n-1; a++) {
        for (int b = -n+1; b <= n-1; b++) {
            if (a == 0 && b == 0) cout << "o";
            else if (c[a+n][b+n]) cout << ".";
            else cout << "x";
        }
        cout << "\n";
    }
}