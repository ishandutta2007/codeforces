#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n, m;
char s[N][N];

template <typename flow_t = int>
struct DinicFlow {
    static const int INF = numeric_limits<flow_t>::max() / 2; // 1e9
 
    int n, s, t;
    vector<vector<int>> adj;
    vector<int> d, cur;
    vector<int> to;
    vector<flow_t> c, f;
 
    DinicFlow(int n, int s, int t) : n(n), s(s), t(t) {
        adj.assign(n, vector<int>());
        d.assign(n, -1);
        cur.assign(n, 0);
    }
 
    int addEdge(int u, int v, flow_t _c) {
        adj[u].push_back(to.size()); 
        to.push_back(v); f.push_back(0); c.push_back(_c);
        adj[v].push_back(to.size());
        to.push_back(u); f.push_back(0); c.push_back(0);
        return (int)to.size() - 2;
    }
 
    bool bfs(flow_t lim) {
        fill(d.begin(), d.end(), -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto edgeId : adj[u]) {
                int v = to[edgeId];
                if (d[v] == -1 && lim <= c[edgeId] - f[edgeId]) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] != -1;
    }
 
    flow_t dfs(int u, flow_t res) {
        if (u == t) return res;
        for (int &i = cur[u]; i < adj[u].size(); i++) {
            int edgeId = adj[u][i];
            int v = to[edgeId];
            if (d[v] == d[u] + 1 && res <= c[edgeId] - f[edgeId]) {
                flow_t foo = dfs(v, res);
                if (foo) {
                    f[edgeId] += foo;
                    f[edgeId ^ 1] -= foo;
                    return foo;
                }
            }
        }
        return 0;
    }
 
    flow_t maxFlow() {
        flow_t res = 0;
        flow_t lim = (flow_t)1 << int(round(log2(INF)));
        while (lim >= 1) {
            if (!bfs(lim)) {
                lim >>= 1;
                continue;
            }
            fill(cur.begin(), cur.end(), 0);
            flow_t aug = 0;
            while (aug = dfs(s, lim)) res += aug;
        }
        return res;
    }
};

inline int encode(int u, int v) {
    return (u - 1) * m + v;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    DinicFlow<> f(n * m + 2, 0, n * m + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                if (s[i][j - 1] == '#') f.addEdge(encode(i, j), encode(i, j - 1), 1);
                else f.addEdge(encode(i, j), f.t, 1);
                if (s[i - 1][j] == '#') f.addEdge(encode(i - 1, j), encode(i, j), 1);
                else f.addEdge(f.s, encode(i, j), 1);
            }
        }
    }
    cout << f.maxFlow() << endl;
    return 0;
}