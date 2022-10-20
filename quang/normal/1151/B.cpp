#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m;
int a[N][N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        res[i] = 1;
        cur ^= a[i][1];
    }
    if (cur != 0) {
        cout << "TAK\n";
        for (int i = 1; i <= n; i++) cout << res[i] << ' ';
        cout << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (a[i][j] != a[i][1]) {
                res[i] = j;
                cout << "TAK\n";
                for (int i = 1; i <= n; i++) cout << res[i] << ' ';
                cout << endl;
                return 0;
            }
        }
    }
    cout << "NIE" << endl;
    return 0;
}