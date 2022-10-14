#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    vector<array<int, 3>> DP(n); // 0 = i was killed before (i, p) is considered, 1 = i was killed by p, 2 = i killed p
    function<void(int, int)> dfs = [&](int n, int p) {
        /*  DP[n][0] = sum for all i before parent edge index, all nodes before i is killed or killed by n * n is killed by i * all nodes after i "killed n"(fake encounter) or is killed
            DP[n][1] = all nodes before i is killed or killed by n * all nodes after i "killed" n (fake encounter) or is killed
            DP[n][2] = sum for all i after parent edge index, all nodes before i is killed or killed by n * n is killed by i * all nodes after i "killed" n or is killed
            DP[n][2] += all nodes are killed by n
        */
        int d = g[n].size(); // parent edge
        for (int i = 0; i < g[n].size(); i++) {
            if (g[n][i] == p) {
                d = i;
            } else {
                dfs(g[n][i], n);
            }
        }

        if (p != -1) {
            g[n].erase(find(begin(g[n]), end(g[n]), p));
        }

        if (g[n].empty()) {
            DP[n][0] = 0;
            DP[n][1] = 1;
            DP[n][2] = 1;
            return;
        }

        vector<int> pref(g[n].size(), 1), suff(g[n].size(), 1);

        for (int i = 0; i < g[n].size(); i++) {
            pref[i] = (1ll * DP[g[n][i]][0] + DP[g[n][i]][1]) % MOD;
            if (i > 0) {
                pref[i] = (1ll * pref[i] * pref[i - 1]) % MOD;
            }
        }

        for (int i = (int) g[n].size() - 1; i >= 0; i--) {
            suff[i] = (1ll * DP[g[n][i]][0] + DP[g[n][i]][2]) % MOD;
            if (i + 1 < g[n].size()) {
                suff[i] = (1ll * suff[i] * suff[i + 1]) % MOD;
            }
        }

        /* n is selected in child's edge */
        for (int i = 0; i < d; i++) {
            int p = (i > 0 ? pref[i - 1] : 1);
            int s = (i + 1 < g[n].size())? suff[i + 1] : 1;
            DP[n][0] = (1ll * DP[n][0] + (1ll * p * s % MOD) * DP[g[n][i]][2] % MOD) % MOD;
        }

        /* n is selected in (n, p) */
        DP[n][1] = (1ll * (d > 0 ? pref[d - 1] : 1) * (d < g[n].size()? suff[d] : 1)) % MOD;

        /* p is selecetd in (n, p) */
        DP[n][2] = pref[(int) g[n].size() - 1];
        for (int i = d; i < g[n].size(); i++) {
            int p = (i > 0)? pref[i - 1] : 1;
            int s = (i + 1 < g[n].size())? suff[i + 1] : 1;
            DP[n][2] = (1ll * DP[n][2] + (1ll * p * s % MOD) * DP[g[n][i]][2] % MOD) % MOD;
        }

    };

    dfs(0, -1);

    cout << (DP[0][0] + DP[0][1]) % MOD << "\n";
    return 0;
}