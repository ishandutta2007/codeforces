#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

struct Flow {
    static const int V = 1e5;
    int n, s, t, cnt;
    vector<int> adj[V];
    int to[V], c[V], f[V], h[V], cur[V];

    Flow(int n, int s, int t) : n(n), s(s), t(t) {
        cnt = 0;
    }

    void addEdge(int u, int v, int _c) {
        to[cnt] = v, c[cnt] = _c, f[cnt] = 0;
        adj[u].push_back(cnt++);
        to[cnt] = u, c[cnt] = 0, f[cnt] = 0;
        adj[v].push_back(cnt++);
    }

    bool bfs() {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            h[i] = -1;
        }
        h[s] = 0;
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
};

const int N = 55;

int x[N], xx[N], y[N], yy[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (!m) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> valX, valY;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i] >> xx[i] >> yy[i];
        valX.push_back(x[i]);
        valX.push_back(xx[i] + 1);
        valY.push_back(y[i]);
        valY.push_back(yy[i] + 1);
    }
    
    sort(valX.begin(), valX.end());
    valX.resize(unique(valX.begin(), valX.end()) - valX.begin());
    sort(valY.begin(), valY.end());
    valY.resize(unique(valY.begin(), valY.end()) - valY.begin());

    int szX = valX.size() - 1;
    int szY = valY.size() - 1;
    Flow f(2 + szX + szY + m, 0, 1 + szX + szY + m);
    for (int i = 0; i < szX; i++) {
        f.addEdge(f.s, i + 1, valX[i + 1] - valX[i]);
    }
    for (int i = 0; i < szY; i++) {
        f.addEdge(i + 1 + szX, f.t, valY[i + 1] - valY[i]);
    }
    for (int i = 1; i <= m; i++) {
        int curId = szX + szY + i;
        for (int j = 0; j < szX; j++) {
            if (valX[j] >= x[i] && valX[j] <= xx[i]) {
                f.addEdge(j + 1, curId, INF);
            }
        }
        for (int j = 0; j < szY; j++) {
            if (valY[j] >= y[i] && valY[j] <= yy[i]) {
                f.addEdge(curId, j + 1 + szX, INF);
            }
        }
    }
    cout << f.maxFlow() << endl;
    return 0;
}