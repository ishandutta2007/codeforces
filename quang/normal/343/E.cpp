#include <bits/stdc++.h>

using namespace std;

struct DinicFlow {
    static const int INF = 1e9;
 
    int n, s, t;
    vector<vector<int>> adj;
    vector<int> d, cur;
    vector<int> to, c, f;
 
    DinicFlow(int n, int s = 0, int t = 0) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
        d.assign(n, -1);
        cur.assign(n, 0);
    }
 
    void addEdge(int u, int v, int _c) {
        adj[u].push_back(to.size());
        to.push_back(v);
        c.push_back(_c);
        f.push_back(0);
        adj[v].push_back(to.size());
        to.push_back(u);
        c.push_back(_c);
        f.push_back(0);
    }
 
    bool bfs() {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto edgeId : adj[u]) {
                int v = to[edgeId];
                if (d[v] == -1 && f[edgeId] < c[edgeId]) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    }
 
    int dfs(int u, int res) {
        if (u == t) return res;
        for (int &i = cur[u]; i < adj[u].size(); i++) {
            int edgeId = adj[u][i];
            int v = to[edgeId];
            if (d[v] == d[u] + 1 && f[edgeId] < c[edgeId]) {
                int foo = dfs(v, min(res, c[edgeId] - f[edgeId]));
                if (foo) {
                    f[edgeId] += foo;
                    f[edgeId ^ 1] -= foo;
                    return foo;
                }
            }
        }
        return 0;
    }
 
    int maxFlow(int s, int t) {
        this->s = s;
        this->t = t;
        fill(f.begin(), f.end(), 0);
        int res = 0;
        while (bfs()) {
            fill(cur.begin(), cur.end(), 0);
            while (1) {
                int foo = dfs(s, INF);
                if (foo) res += foo;
                else break;
            }
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    DinicFlow f(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        f.addEdge(u, v, w);
    }
    map<pair<int, int>, int> edges;
    vector<int> root(n + 1, 1);
    int res = 0;
    for (int i = 2; i <= n; i++) {
        int u = root[i];
        int flow = f.maxFlow(i, u);
        res += flow;

        for (int j = 1; j < i; j++) {
            pair<int, int> foo(u, j);   
            if (foo.first > foo.second) swap(foo.first, foo.second);
            if (edges.find(foo) != edges.end() && f.d[j] != -1) {
                int w = edges[foo];
                edges.erase(foo);
                edges[{j, i}] = w;
            }
        }

        for (int j = i; j <= n; j++) {
            if (root[j] == u && f.d[j] != -1) {
                root[j] = i;
            }
        }

        edges[{u, i}] = flow;
    }

    iota(root.begin(), root.end(), 0);
    vector<pair<int, pair<int, int>>> edgesList;
    for (auto &u : edges) {
        edgesList.push_back({u.second, u.first});
    }
    sort(edgesList.rbegin(), edgesList.rend());

    function<int(int)> getRoot = [&](int u) {
        return root[u] == u ? u : root[u] = getRoot(root[u]);
    };

    vector<list<int>> ls(n + 1, list<int>());
    for (int i = 1; i <= n; i++) ls[i].push_back(i);

    for (auto &edge : edgesList) {
        int u, v, w;
        w = edge.first;
        tie(u, v) = edge.second;
        int uu = getRoot(u);
        int vv = getRoot(v);    
        root[vv] = uu;
        ls[uu].splice(ls[uu].begin(), ls[vv]);
    }

    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        if (!ls[i].empty()) {
            for (auto u : ls[i]) cout << u << ' ';
        }
    }
    cout << endl;
    return 0;
}