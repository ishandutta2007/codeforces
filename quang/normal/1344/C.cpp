#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, m;
int used[N];
vector<vector<int>> adj, revAdj;
int deg[N];
vector<int> minAdj, minRevAdj;

void dfs(int u, const vector<vector<int>> adj) {
    used[u] = 1;
    for (int v : adj[u]) {
        if (used[v]) continue;
        dfs(v, adj);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    revAdj.resize(n + 1, vector<int>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        deg[i] = revAdj[i].size();
        if (!deg[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        used[u] = 1;
        q.pop();
        for (int v : adj[u]) {
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    minAdj.resize(n + 1, 1e9);
    minRevAdj.resize(n + 1, 1e9);

    auto solve = [&](vector<vector<int>> &adj, vector<int> &minAdj) {
        fill(deg + 1, deg + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (auto u : adj[i]) {
                deg[u]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            minAdj[i] = i;
            if (!deg[i]) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                minAdj[v] = min(minAdj[v], minAdj[u]);
                deg[v]--;
                if (!deg[v]) q.push(v);
            }
        }
    };

    solve(adj, minAdj);
    solve(revAdj, minRevAdj);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (minAdj[i] >= i && minRevAdj[i] >= i) res++;
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        if (minAdj[i] >= i && minRevAdj[i] >= i) cout << 'A';
        else cout << 'E';   
    }
    cout << '\n';
    return 0;
}