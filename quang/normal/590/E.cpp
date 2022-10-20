#include <bits/stdc++.h>

using namespace std;

const int SZ = 10000010;
const int N = 760;

int n;
string s[N];
bool edge[N][N];

struct AC {
    int nxt[2][SZ];
    int id[SZ];
    int cnt;
    int link[SZ];
    int dp[SZ];

    AC() {
        cnt = 0;
        memset(nxt, -1, sizeof nxt);
        memset(link, -1, sizeof link);
        memset(id, -1, sizeof id);
    }

    void add(const string &u, int now) {
        int cur = 0;
        for (char v : u) {
            int val = v - 'a';
            if (nxt[val][cur] == -1) nxt[val][cur] = ++cnt;
            cur = nxt[val][cur];
        }
        id[cur] = now;
    }

    void build() {
        memset(dp, -1, sizeof dp);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (link[u] != -1) {
                if (id[u] != -1) dp[u] = id[u];
                else dp[u] = dp[link[u]];
            }
            for (int i = 0; i < 2; i++) {
                int v = link[u] == -1 ? 0 : nxt[i][link[u]];
                if (nxt[i][u] == -1) nxt[i][u] = v;
                else {
                    link[nxt[i][u]] = v;
                    q.push(nxt[i][u]);
                }
            }
        }
    }   

    void go(int u) {
        int cur = 0;
        for (char v : s[u]) {
            int val = v - 'a';
            cur = nxt[val][cur];
            if (dp[cur] != -1) {
                edge[dp[cur]][u] = 1;
            }
        }
        if (dp[link[cur]] != -1) {
            edge[dp[link[cur]]][u] = 1;
        }
    }
} ac;

const int INF = 1e9;
const int V = 3 * N * N;

struct DinicFlow {
    vector<int> adj[N * 2];
    int to[V], c[V], f[V], h[N * 2];
    int n, s, t;
    int cnt;
    int cur[N * 2];

    DinicFlow(int n, int s, int t) : n(n), s(s), t(t) {
        cnt = 0;
    }

    void addEdge(int u, int v, int _c) {
        to[cnt] = v, c[cnt] = _c, f[cnt] = 0;
        adj[u].push_back(cnt++);
        to[cnt] = u, c[cnt] = 0, f[cnt] = 0;
        adj[v].push_back(cnt++);
    }

    bool bfs() {
        fill(h, h + n, -1);
        h[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                int v = to[id];
                if (h[v] == -1 && f[id] < c[id]) {
                    h[v] = h[u] + 1;
                    q.push(v);
                }
            }
        }
        return h[t] != -1;
    }

    int dfs(int u, int res) {
        if (u == t) return res;
        for (int &i = cur[u]; i < adj[u].size(); i++) {
            int id = adj[u][i];
            int v = to[id];
            if (h[v] == h[u] + 1 && f[id] < c[id]) {
                int foo = dfs(v, min(res, c[id] - f[id]));
                if (foo) {
                    f[id] += foo;
                    f[id ^ 1] -= foo;
                    return foo;
                }
            }
        }
        return 0;
    }

    int maxFlow() {
        int res = 0;
        while (bfs()) {
            for (int i = 0; i < n; i++) {
                cur[i] = 0;
            }
            while (1) {
                int foo = dfs(s, INF);
                if (!foo) break;
                res += foo;
            }
        }
        return res;
    }

    vector<int> getVcList(int sz) {
        int ver = bfs();
        assert(!ver);
        vector<int> res;
        for (int i = 1; i <= sz; i++) {
            if (h[i] == -1) res.push_back(i);
            if (h[i + sz] != -1) res.push_back(i);
        }
        return res;
    }
};

int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        ac.add(s[i], i);
    }
    ac.build();
    for (int i = 1; i <= n; i++) {
        ac.go(i);
        edge[i][i] = 0;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][k] && edge[k][j]) edge[i][j] = 1;
            }
        }
    }
    DinicFlow f(n * 2 + 2, 0, n * 2 + 1);
    for (int i = 1; i <= n; i++) {
        f.addEdge(f.s, i, 1);
        f.addEdge(i + n, f.t, 1);
        for (int j = 1; j <= n; j++) {
            if (edge[i][j]) {
                f.addEdge(i, j + n, 1);
            }
        }
    }
    cout << n - f.maxFlow() << endl;
    vector<int> vcList = f.getVcList(n);
    fill(res + 1, res + n + 1, 1);
    for (int u : vcList) res[u] = 0;
    for (int i = 1; i <= n; i++) if (res[i]) cout << i << ' ';
    cout << endl;
    return 0;
}