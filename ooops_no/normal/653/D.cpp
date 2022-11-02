#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int INF = 1e9;

struct MaxFlow {
    struct Edge {
        int f, c, u;
    };
    int n, s, t;
    vector<Edge> edges;
    vector<vector<int>> e;
    vector<int> pos;
    vector<int> d;

    void add_edge(int v, int u, int c) {
        e[v].push_back(edges.size());
        edges.push_back({0, c, u});
        e[u].push_back(edges.size());
        edges.push_back({0, 0, v});
    }

    bool bfs() {
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : e[v]) {
                int u = edges[i].u;
                if (edges[i].f < edges[i].c && d[v] + 1 < d[u]) {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
        return d[t] < INF;
    }

    int dfs(int v, int f = INF) {
        if (v == t) return f;
        for (; pos[v] < e[v].size(); ++pos[v]) {
            int i = e[v][pos[v]];
            auto &E = edges[i];
            if (E.f < E.c && d[v] + 1 == d[E.u]) {
                int delta = dfs(E.u, min(f, E.c - E.f));
                if (delta > 0) {
                    E.f += delta;
                    edges[i ^ 1].f -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }

    int max_flow() {
        int res = 0;
        while (bfs()) {
            fill(pos.begin(), pos.end(), 0);
            while (true) {
                int f = dfs(s);
                if (f == 0) break;
                res += f;
            }
        }
        return res;
    }

    MaxFlow(int n_, int s_, int t_) : n(n_), s(s_), t(t_) {
        edges = {};
        e = vector<vector<int>>(n);
        d = vector<int>(n);
        pos = vector<int>(n, 0);
    }
};

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, pair<int,int>>> u(m);
    for (int i = 0; i < m; i++){
        cin >> u[i].first >> u[i].second.first >> u[i].second.second;
        u[i].first--, u[i].second.first--;
    }
    ld l = 0, r = INF + 1;
    for (int i = 0; i < 300; i++){
        ld mid = (r + l) / 2;
        MaxFlow F(n, 0, n - 1);
        for (int i = 0; i < m; i++){
            F.add_edge(u[i].first, u[i].second.first, (int)((ld)u[i].second.second / mid));
        }
        if (F.max_flow() >= x){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << setprecision(30) << fixed << (ld)l * (ld)x << endl;
    return 0;
}