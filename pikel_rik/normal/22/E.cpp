#line 1 "main.cpp"
#include <bits/stdc++.h>
using namespace std;

#line 2 "graphs\\scc.hpp"

#line 2 "graphs\\graph.hpp"

#line 4 "graphs\\graph.hpp"

struct graph {
    struct edge {
        int u, v;

        edge(int u, int v) : u(u), v(v) {}
    };

    int n, m;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;

    graph() : n(), m() {}

    graph(int n, int m = 0) : n(n), m(), adj(n) {
        edges.reserve(m);
    }

    int add_edge(int u, int v) {
        adj[u].push_back(m);
        adj[v].push_back(m);
        edges.emplace_back(u, v);
        return m++;
    }
};

struct digraph {
    struct edge {
        int u, v;

        edge(int u, int v) : u(u), v(v) {}
    };

    int n, m;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;

    digraph() : n(), m() {}

    digraph(int n, int m = 0) : n(n), m(), adj(n) {
        edges.reserve(m);
    }

    int add_edge(int u, int v) {
        edges.emplace_back(u, v);
        adj[u].push_back(m);
        return m++;
    }

    digraph transpose() const {
        digraph rev(n, m);
        for (auto&[u, v]: edges) {
            rev.add_edge(v, u);
        }
        return rev;
    }
};
#line 5 "graphs\\scc.hpp"

std::vector<std::vector<int>> find_sccs(const digraph &g) {
    int timer = 0;
    std::vector<int> tin(g.n, -1), low(g.n);

    std::vector<int> all;
    all.reserve(g.n);

    std::vector<std::vector<int>> sccs;
    auto dfs = [&](int u, const auto &self) -> void {
        low[u] = tin[u] = timer++;
        all.push_back(u);
        for (int i: g.adj[u]) {
            int v = g.edges[i].v;
            if (tin[v] == -1) {
                self(v, self);
            }
            low[u] = std::min(low[u], low[v]);
        }
        if (low[u] == tin[u]) {
            int sz = std::find(all.rbegin(), all.rend(), u) - all.rbegin();
            sccs.emplace_back(sz + 1);
            for (int i = 0; i < sz; i++) {
                low[all.back()] = g.n;
                sccs.back()[i] = all.back();
                all.pop_back();
            }
            all.pop_back();
            sccs.back().back() = u, low[u] = g.n;
        }
    };

    for (int u = 0; u < g.n; u++) {
        if (tin[u] == -1) {
            dfs(u, dfs);
        }
    }
    std::reverse(sccs.begin(), sccs.end());
    return sccs;
}
#line 5 "main.cpp"

int main() {
    int n;
    cin >> n;

    digraph g(n);
    for (int u = 0, v; u < n; u++) {
        cin >> v, g.add_edge(u, --v);
    }

    auto sccs = find_sccs(g);
    int sz = (int) sccs.size();

    if (sz == 1) {
        return cout << 0 << '\n', 0;
    }

    vector<int> id(n);
    for (int i = 0; i < sz; i++) {
        for (int u : sccs[i]) {
            id[u] = i;
        }
    }

    digraph cg(sz);
    for (auto [u, v] : g.edges) {
        if (id[u] != id[v]) {
            cg.add_edge(id[u], id[v]);
        }
    }

    digraph cg_rev = cg.transpose();

    vector<int> order;
    for (int u = 0; u < sz; u++) {
        if (cg.adj[u].size() == 0) {
            auto dfs = [&](int u, int p, auto &&self) -> void {
                if (cg_rev.adj[u].size() == 0) {
                    order.push_back(u);
                }
                for (int i : cg_rev.adj[u]) {
                    const auto &e = cg_rev.edges[i];
                    int v = e.u ^ e.v ^ u;
                    if (v != p) {
                        self(v, u, self);
                    }
                }
            };

            dfs(u, -1, dfs);

            if (cg_rev.adj[u].size() != 0) {
                order.push_back(u);
            }
        }
    }

    vector<digraph::edge> ans;
    for (int i = 1; i < (int) order.size(); i++) {
        int u = order[i - 1], v = order[i];
        if (cg.adj[v].size() == 0 && cg_rev.adj[v].size() != 0) {
        } else {
            ans.emplace_back(u, v);
        }
    }

    ans.emplace_back(order.back(), order.front());

    cout << ans.size() << '\n';
    for (auto [u, v] : ans) {
        cout << sccs[u][0] + 1 << ' ' << sccs[v][0] + 1 << '\n';
    }
    return 0;
}