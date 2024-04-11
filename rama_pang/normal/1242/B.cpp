#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<map<int, int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    bitset<1000005> bit;
    for (int i = 0; i < n; i++) {
        bit[i] = 1;
    }
    int cc = 0;
    function<void(int)> dfs = [&](int n) {
        bit[n] = 0;
        for (int i = bit._Find_first(); i < bit.size(); i = bit._Find_next(i)) {
            if (g[n].count(i) == 0) {
                dfs(i);
            }
        }
    };
    
    for (int i = 0; i < n; i++) {
        if (bit[i]) {
            cc++;
            dfs(i);
        }
    }

    cout << (cc - 1) << "\n";
    return 0;
}