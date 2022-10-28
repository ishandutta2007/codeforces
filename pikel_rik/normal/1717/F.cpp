#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct flow_graph {
    struct edge {
        int u, v;
        T c, f;

        edge(int u, int v, T c, T f) : u(u), v(v), c(c), f(f) {}
    };

    int n, m;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;

    flow_graph() : n(), m() {}

    flow_graph(int n, int m = 0) : n(n), m(), adj(n) {
        edges.reserve(2 * m);
    }

    template <bool undirected = false>
    void add_edge(int u, int v, T c) {
        edges.emplace_back(u, v, c, 0);
        adj[u].push_back(m++);
        if constexpr (undirected) {
            edges.emplace_back(v, u, c, 0);
        } else {
            edges.emplace_back(v, u, 0, 0);
        }
        adj[v].push_back(m++);
    }
};

template<typename T>
T max_flow(flow_graph<T> &g, int s, int t) {
    std::vector<int> lvl(g.n);

    auto bfs = [&](void) -> void {
        std::fill(lvl.begin(), lvl.end(), -1);
        std::queue<int> q;
        q.push(s);
        lvl[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i: g.adj[x]) {
                const auto &e = g.edges[i];
                if (lvl[e.v] == -1 && e.c - e.f > 0) {
                    lvl[e.v] = 1 + lvl[x];
                    q.push(e.v);
                }
            }
        }
    };

    std::vector<int> p(g.n), ptr(g.n);

    auto dfs = [&](int x, const auto &dfs) -> bool {
        if (x == t) return true;
        for (; ptr[x] < g.adj[x].size(); ptr[x]++) {
            const auto &e = g.edges[g.adj[x][ptr[x]]];
            if (lvl[x] + 1 == lvl[e.v] && e.c - e.f > 0) {
                p[e.v] = g.adj[x][ptr[x]];
                if (dfs(e.v, dfs)) {
                    return true;
                }
            }
        }
        return false;
    };

    T max_flow = 0;
    while (bfs(), lvl[t] != -1) {
        while (dfs(s, dfs)) {
            T path_flow = std::numeric_limits<T>::max();
            for (int x = t; x != s; x = g.edges[p[x]].u) {
                path_flow = std::min(path_flow, g.edges[p[x]].c - g.edges[p[x]].f);
            }
            max_flow += path_flow;
            for (int x = t; x != s; x = g.edges[p[x]].u) {
                int i = p[x];
                g.edges[i].f += path_flow;
                g.edges[i ^ 1].f -= path_flow;
            }
        }
        std::fill(ptr.begin(), ptr.end(), 0);
    }
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    constexpr int inf = (int) 1e9;

    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    for (auto &x : s) cin >> x;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    struct edge { int u, v; };
    vector<edge> e(m);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        auto &[u, v] = e[i];
        cin >> u >> v, --u, --v;
        g[u].push_back(i);
        g[v].push_back(i);
    }

    for (int u = 0; u < n; u++) {
        if (s[u] == 1) {
            if (abs(a[u]) % 2 != g[u].size() % 2 || abs(a[u]) > g[u].size()) {
                return cout << "NO\n", 0;
            }
            a[u] = (a[u] + g[u].size()) / 2;
        }
    }

    flow_graph<int> fg(m + n + 3);
    int src = m + n, dest = m + n + 1, extra = m + n + 2;

    for (int i = 0; i < m; i++) {
        fg.add_edge(src, i, 1);
        fg.add_edge(i, m + e[i].u, 1);
        fg.add_edge(i, m + e[i].v, 1);
    }

    for (int u = 0; u < n; u++) {
        if (s[u] == 1) {
            fg.add_edge(m + u, dest, a[u]);
        } else {
            fg.add_edge(m + u, extra, inf);
        }
    }

    int k = m - accumulate(a.begin(), a.end(), 0);
    if (k < 0) {
        return cout << "NO\n", 0;
    }

    fg.add_edge(extra, dest, k);

    int flow = max_flow(fg, src, dest);
    if (flow != m) {
        return cout << "NO\n", 0;
    }

    cout << "YES\n";
    for (int i = 0; i < m; i++) {
        const auto &fe = fg.edges[6 * i + 2];
        const auto &be = fg.edges[6 * i + 4];
        if (be.f == 1) {
            cout << e[i].u + 1 << ' ' << e[i].v + 1 << '\n';
        } else {
            cout << e[i].v + 1 << ' ' << e[i].u + 1 << '\n';
        }
    }
    return 0;
}