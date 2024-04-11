#include <bits/stdc++.h>

using namespace std;

const int N = 610;
const int V = 5e3;
const int INF = 1e9;

int n, m, k;
int deg[N], res[N];
pair<int, int> a[N];

struct Flow {
    int to[V], f[V], c[V], h[V], cur[V];
    vector<int> adj[V];
    int n, s, t;
    int cnt;
    Flow(int n, int s, int t) {
        cnt = 0;
        this->n = n;
        this->s = s;
        this->t = t;
    }

    void addEdge(int u, int v, int _c) {
        // cerr << u << " " << v << " " << _c << endl;
        to[cnt] = v, f[cnt] = 0, c[cnt] = _c;
        adj[u].push_back(cnt++);
        to[cnt] = u, f[cnt] = 0, c[cnt] = 0;
        adj[v].push_back(cnt++);
    }

    bool bfs() {
        for (int i = 0; i < n; i++) {
            h[i] = -1;
        }
        h[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                int v = to[id];
                if (f[id] < c[id] && h[v] == -1) {
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
            int id =  adj[u][i];
            int v = to[id];
            if (f[id] < c[id] && h[v] == h[u] + 1) {
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
        while(bfs()) {
            for (int i = 0; i < n; i++) cur[i] = 0;

            while (1) {
                int foo = dfs(s, INF);
                if (foo) res += foo;
                else break;
            }
        }
        return res;
    }

    void trace(int sz) {
        int now = 0;
        for (int i = 1; i <= sz; i++) {
            vector<int> u;
            for (int id : adj[i]) {
                if (f[id] == 0 || c[id] == 0) continue;
                u.push_back(to[id] - sz);
            }
            assert(u.size() % 2 == 0);
            for (int i = 0; i + 1 < u.size(); i += 2) {
                int x = u[i];
                int y = u[i + 1];
                res[x] = res[y] = ++now;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (res[i] == -1) res[i] = ++now;
        }
    }
};

void init() {
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        res[i] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> m >> k;
        init();
        for (int i = 1; i <= m; i++) {
            cin >> a[i].first >> a[i].second;
            deg[a[i].first]++;
            deg[a[i].second]++;
        }
        Flow f(n + m + 2, 0, n + m + 1);
        int tot = 0;
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (k * 2 < deg[i]) {
                flag = 1;
                break;
            }
            int foo = max(deg[i] - k, 0);
            tot += foo * 2;
            f.addEdge(f.s, i, foo * 2);
        }
        if (flag) {
            for (int i = 1; i <= m; i++) cout << 0 << ' ';
            cout << '\n';
            continue;  
        }
        for (int i = 1; i <= m; i++) {
            f.addEdge(i + n, f.t, 1);
            f.addEdge(a[i].first, i + n, 1);
            f.addEdge(a[i].second, i + n, 1);
        }
        int now = f.maxFlow();
        if (now == tot) {
            f.trace(n);
            for (int i = 1; i <= m; i++) cout << res[i] << ' ';
            cout << '\n';
        } else {
            for (int i = 1; i <= m; i++) cout << 0 << ' ';
            cout << '\n';
        }
    }
    return 0;
}