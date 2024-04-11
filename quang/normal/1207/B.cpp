#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, m;
int a[N][N], b[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> res;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]) {
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
                res.push_back({i, j});
            }
        }
    }
    int found = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != b[i][j]) {
                found = 1;
                break;
            }
        }
    }
    if (found) {
        cout << -1 << endl;
    } else {
        cout << res.size() << endl;
        for (auto u : res) {
            cout << u.first << ' ' << u.second << endl;
        }
    }
    return 0;
}