#include<iostream>

using namespace std;

char a[200][200];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) {
        if (a[i][j] == '#' && a[i + 1][j] == '#' && a[i + 1][j - 1] == '#' && a[i + 1][j + 1] == '#' && a[i + 2][j] == '#') {
            a[i][j] = a[i + 1][j] = a[i + 1][j - 1] = a[i + 1][j + 1] = a[i + 2][j] = '.';
        }
    }
    bool have = false;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (a[i][j] == '#') have = true;
    if (have) cout << "NO" << endl; else cout << "YES" << endl;
    return 0;
}