#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka
struct test {
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(n, -1));
        vector<int> c(m);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v >> c[i];
            u--; v--;
            a[u][v] = a[v][u] = i;
        }
        vector<vector<int>> w;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i][j] == -1) continue;
                for (int k = j + 1; k < n; k++) {
                    if (a[i][k] == -1 || a[j][k] == -1) continue;
                    vector<int> r(m + 1);
                    r[a[i][j]] = r[a[i][k]] = r[a[j][k]] = 1;
                    w.push_back(r);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (c[i] != -1) {
                vector<int> r(m + 1);
                r[i] = 1;
                r[m] = c[i] - 1;
                w.push_back(r);
            }
        }
        int s = w.size();
        vector<bool> z(s);
        vector<int> r(m, -1);

        for (int i = 0; i < m; i++) {
            int k = -1;
            for (int j = 0; j < s; j++) {
                if (!z[j] && w[j][i] != 0) {
                    k = j;
                    break;
                }
            }
            if (k != -1) {
                r[i] = k;
                z[k] = true;
                int x = w[k][i];
                for (int t = 0; t <= m; t++) {
                    w[k][t] = (w[k][t] * x) % 3;
                }
                for (int j = 0; j < s; j++) {
                    if (j == k) continue;
                    int x = w[j][i];
                    if (x != 0) {
                        for (int t = 0; t <= m; t++) {
                            w[j][t] = (w[j][t] + w[k][t] * (3 - x)) % 3;
                        }
                    }
                }
            }
        }
//        for (int i = 0; i < s; i++) {
//            for (int x : w[i]) cout << x << " "; cout << "\n";
//        }

        vector<int> v(m);
        for (int i = 0; i < m; i++) {
            int k = r[i];
            if (k != -1) {
                v[i] = w[k][m];
            }
        }
        bool ok = true;
        for (int i = 0; i < s; i++) {
            int ss = 0;
            for (int j = 0; j < m; j++) {
                ss += v[j] * w[i][j];
                ss %= 3;
            }
            if (ss != w[i][m]) ok = false;
        }
        if (ok) {
            for (int i = 0; i < m; i++) {
                cout << v[i] + 1 << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
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