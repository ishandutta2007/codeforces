#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> col(n);
    for (int i = 0; i < n; i++) {
        cin >> col[i];
        if (col[i] == 0) {
            col[i] += 2;
        } else {
            col[i]--;
        }
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp[2];
    dp[0].resize(n);
    dp[1].resize(n);
    int diam = 1;
    function<void(int, int)> dfs = [&](int v, int par) {
        if (g[v].size() == 1 && g[v][0] == par) {
            if (col[v] == 2) {
                dp[0][v] = dp[1][v] = 0;
            } else {
                dp[col[v]][v] = 1;
                dp[col[v] ^ 1][v] = 0;
            }
            return;
        }
        for (int u : g[v]) {
            if (u != par) {
                dfs(u, v);
            }
        }
        if (col[v] == 2) {
            for (int u : g[v]) {
                if (u != par) {
                    dp[0][v] = max(dp[0][v], dp[0][u]);
                    dp[1][v] = max(dp[1][v], dp[1][u]);
                }
            }
            int best = 1e6;
            for (int i = 0; i < 2; i++) {
                int h1 = 0, h2 = 0;
                for (int u : g[v]) {
                    if (u != par) {
                        if (dp[i][u] > h1) {
                            h2 = h1;
                            h1 = dp[i][u];
                        } else if (dp[i][u] > h2) {
                            h2 = dp[i][u];
                        }
                    }
                }
                best = min(best, h1 + h2 + 1);
            }
            diam = max(diam, best);
        } else {
            for (int u : g[v]) {
                if (u == par) continue;
                dp[col[v]][v] = max(dp[col[v]][v], dp[col[v]][u]);
                dp[col[v]][v] = max(dp[col[v]][v], dp[col[v] ^ 1][u] + 1);
                dp[col[v] ^ 1][v] = max(dp[col[v] ^ 1][v], dp[col[v] ^ 1][u]);
            }
            int h1 = 0, h2 = 0;
            for (int u : g[v]) {
                if (u != par) {
                    if (dp[col[v] ^ 1][u] > h1) {
                        h2 = h1;
                        h1 = dp[col[v] ^ 1][u];
                    } else if (dp[col[v] ^ 1][u] > h2) {
                        h2 = dp[col[v] ^ 1][u];
                    }
                }
            }
            diam = max(diam, h1 + h2 + 1);
        }
    };
    dfs(0, -1);
    // for (int i = 0; i < n; i++) {
    //     cerr << dp[0][i] << ' ' << dp[1][i] << endl;
    // }
    cout << diam / 2 + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}