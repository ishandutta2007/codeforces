#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m, k;
unordered_set<int> adj[N];
int deg[N];
int used[N];

bool check(int u) {
    for (int v : adj[u]) {
        for (int w : adj[u]) {
            if (v == w) continue;
            if (!adj[v].count(w)) return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            deg[i] = 0;
            used[i] = 0;
        }

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
            deg[u]++;
            deg[v]++;
        }
        if (1ll * k * (k - 1) > 2ll * m) {
            cout << -1 << '\n';
            continue;
        }

        if (k == 1) {
            cout << 2 << '\n';
            cout << 1 << '\n';
            continue;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (deg[i] < k) {
                q.push(i);
                used[i] = 1;
            }
        }
        int f = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (deg[u] == k - 1) {
                if (check(u)) {
                    f = 1;
                    cout << 2 << '\n';
                    for (auto v : adj[u]) cout << v << ' ';
                        cout << u << '\n';
                    break;
                }
            }
            while (!adj[u].empty()) {
                int v = *adj[u].begin();
                adj[u].erase(v);
                adj[v].erase(u);
                deg[u]--;
                deg[v]--;
                if (deg[v] < k && !used[v]) {
                    q.push(v);
                    used[v] = 1;
                }
            }
        }
        if (f) continue;
        vector<int> ls;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) ls.push_back(i);
        }
        if (ls.empty()) cout << -1 << '\n';
        else {
            cout << 1 << ' ' << ls.size() << '\n';
            for (int u : ls) cout << u << ' ';
                cout << '\n';
        }
    }   
    return 0;
}