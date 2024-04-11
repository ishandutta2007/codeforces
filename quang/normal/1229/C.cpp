#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector<int> adj[N];
int deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        adj[u].push_back(v);
        deg[u]++, deg[v]++;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += 1ll * adj[i].size() * (deg[i] - adj[i].size());
    }
    cout << res << '\n';
    int q;
    cin >> q;
    while (q--) {
        int u;
        cin >> u;
        res -= 1ll * adj[u].size() * (deg[u] - adj[u].size());
        for (int v : adj[u]) {
            res -= 1ll * adj[v].size() * (deg[v] - adj[v].size());
            adj[v].push_back(u);
            res += 1ll * adj[v].size() * (deg[v] - adj[v].size());
        }
        adj[u].clear();
        cout << res << '\n';
    }
    return 0;
}