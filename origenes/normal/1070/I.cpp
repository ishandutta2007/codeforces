#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge {
    int from, to, cap, flow;
    Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
};

const int N = 2 * 600 + 10;
const int INF = int(1e9);

struct Dinic {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    bool vis[N];
    int d[N];
    int cur[N];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[to].push_back(m - 1);
        G[from].push_back(m - 2);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        d[s] = 0;
        vis[s] = true;
        Q.push(s);
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

int n, m, k;
Dinic solver;
vector<int> out[N];
vector<int> vec;
int ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) out[i].clear();
        solver.init(n + m + 5);

        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            out[x].push_back(i);
            out[y].push_back(i);
        }

        bool ok = true;
        vec.clear();
        for (int i = 1; i <= n; i++) {
            if (out[i].size() > 2 * k) {
                cout << 0;
                for (int j = 2; j <= m; j++) cout << ' ' << 0;
                cout << '\n';
                ok = false;
                break;
            } else if (out[i].size() > k) {
                vec.push_back(i);
            }
        }

        if (!ok) continue;
        int tot = 0;
        for (int u : vec) {
            tot += 2 * (out[u].size() - k);
            solver.AddEdge(0, u, 2 * (out[u].size() - k));
            for (int v : out[u]) {
                solver.AddEdge(u, v + n, 1);
            }
        }


        for (int i = 1; i <= m; i++) solver.AddEdge(i + n, n + m + 1, 1);
        //cout << solver.Maxflow(0, n + m + 1) << endl;
        if (solver.Maxflow(0, n + m + 1) < tot) {
            cout << 0;
            for (int i = 2; i <= m; i++) cout << ' ' << 0;
            cout << '\n';
        } else {
            vector<int> ed[N];
            for (int i = 0; i < solver.m; i += 2) {
                int u = solver.edges[i].from, v = solver.edges[i].to, f = solver.edges[i].flow;
                if (u >= 1 && u <= n && v >= n + 1 && v <= n + m && f) ed[u].push_back(v - n);
            }
            int color = 1;
            memset(ans, 0, sizeof(ans));
            for (int u : vec) {
                for (int i = 0; i < ed[u].size(); i += 2) ans[ed[u][i]] = ans[ed[u][i + 1]] = color++;
            }
            for (int i = 1; i <= m; i++)
                if (!ans[i]) ans[i] = color++;
            cout << ans[1];
            for (int i = 2; i <= m; i++) cout << ' ' << ans[i];
            cout << '\n';
        }
    }
    return 0;
}