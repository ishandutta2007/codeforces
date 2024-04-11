#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {

    void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> d(n, vector<int>(n, n + 1));
        vector<vector<long>> a(n, vector<long>(n, LLONG_MAX));
        for (int i = 0; i < m; i++) {
            int x, y;
            long w;
            cin >> x >> y >> w;
            x--;
            y--;
            a[x][y] = min(a[x][y], w);
            a[y][x] = a[x][y];
            d[x][y] = d[y][x] = 1;
        }
        for (int i = 0; i < n; i++) d[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        long res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == LLONG_MAX) continue;
                int dd = d[i][0] + d[j][n - 1];
                for (int k = 0; k < n; k++) {
                    dd = min(dd, d[i][k] + 1 + d[k][0] + d[k][n - 1]);
                }
                res = min(res, a[i][j] * (dd + 1));
            }
        }
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}