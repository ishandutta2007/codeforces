#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
vector<int> g[MAXN];
int p[MAXN], d[MAXN];

void dfs(int v) {
    for (auto u : g[v]) {
        if (u == p[v]) continue;
        d[u] = d[v] + 1;
        p[u] = v;
        dfs(u);
    }
}

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        p[0] = -1;
        d[0] = 0;
        dfs(0);
        set<array<int, 2>> st;
        for (int i = 0; i < n; ++i) {
            if (d[i] >= 3) {
                st.insert({d[i], i});
            }
        }
        while (!st.empty()) {
            auto it = st.end();
            it--;
            int v = (*it)[1];
            int u = p[v];
            st.erase({d[u], u});
            p[u] = 0;
            for (auto v : g[u]) {
                if (p[v] == u) {
                    st.erase({d[v], v});
                }
            }
        }
        fill(d, d + n, 0);
        for (int v = 1; v < n; ++v) {
            d[p[v]]++;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int v = 0; v < n; ++v) {
            if (p[v] != 0) continue;
            if (d[v] > 0) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        if (cnt2 == 0) {
            cout << n - 2 * cnt1 << "\n";
        } else {
            cout << n - 2 * cnt1 - 1 << "\n";
        }
    }
    return 0;
}