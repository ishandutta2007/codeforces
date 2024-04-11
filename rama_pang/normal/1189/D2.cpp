#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> deg(n);
    vector<tuple<int, int, int>> e;
    vector<vector<int>> g(n);
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;
        deg[u]++;
        deg[v]++;
        e.emplace_back(u, v, k);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (deg[i] == 2) {
            cout << "NO\n";
            return 0;
        }
    }

    function<int(int, int)> dfs = [&](int n, int p) {
        int res = n;
        for (auto i : g[n]) if (i != p) {
            res = dfs(i, n);
            break;
        }
        return res;
    };

    for (auto i : e) {
        int u = get<0>(i), v = get<1>(i), k = get<2>(i);
        vector<int> leafU, leafV;
        for (auto j : g[u]) if (j != v) {
            leafU.emplace_back(dfs(j, u));
        }
        for (auto j : g[v]) if (j != u) {
            leafV.emplace_back(dfs(j, v));
        }
        if (leafU.size() == 0 || leafV.size() == 0) {
            if (leafU.size() == 0 && leafV.size() == 0) {
                ans.emplace_back(u, v, k);
            } else if (leafU.size() == 0) {
                ans.emplace_back(u, leafV[0], k / 2);
                ans.emplace_back(u, leafV[1], k / 2);
                ans.emplace_back(leafV[0], leafV[1], - k / 2);
            } else if (leafV.size() == 0) {
                ans.emplace_back(v, leafU[0], k / 2);
                ans.emplace_back(v, leafU[1], k / 2);
                ans.emplace_back(leafU[0], leafU[1], - k / 2);
            }
        } else {
            ans.emplace_back(leafU[0], leafV[0], k / 2);
            ans.emplace_back(leafU[1], leafV[1], k / 2);

            ans.emplace_back(leafU[0], leafU[1], - k / 2);
            ans.emplace_back(leafV[1], leafV[0], - k / 2);
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << get<0>(i) + 1 << " " << get<1>(i) + 1 << " " << get<2>(i) << "\n";
    }
    return 0;
}