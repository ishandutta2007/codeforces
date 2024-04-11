#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct graph {
    struct edge {
        int u, v; T w;
        edge(int u, int v, T w): u(u), v(v), w(w) {}
    };

    int n, m;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;

    graph(): n(), m() {}
    graph(int n, int m = 0): n(n), m(), adj(n) {
    	edges.reserve(m);
    }

    int add_edge(int u, int v, T w) {
        adj[u].emplace_back(m);
        adj[v].emplace_back(m);
        edges.emplace_back(u, v, w);
        return m++;
    }
};

struct digraph {
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    std::vector<edge> edges;
    std::vector<std::vector<int>> adj;

    digraph(): n(), m() {}
    digraph(int n, int m = 0): n(n), m(), adj(n) {
    	edges.reserve(m);
    }

    int add_edge(int u, int v) {
		edges.emplace_back(u, v);
        adj[u].push_back(m);
        return m++;
    }

    digraph transpose() const {
        digraph rev(n);
        for (auto&[u, v] : edges) {
			rev.add_edge(v, u);
        }
        return rev;
    }
};

template <typename T>
std::vector<std::vector<T>> floyd_warshall(const graph<T> &g) {
	static constexpr T inf = std::numeric_limits<T>::max();
	std::vector<std::vector<T>> d(g.n, vector<T>(g.n, inf));
	for (int i = 0; i < g.n; i++) {
		d[i][i] = 0;
	}
	for (auto&[u, v, w] : g.edges) {
		d[u][v] = min(d[u][v], w);
		d[v][u] = min(d[v][u], w);
	}
	for (int k = 0; k < g.n; k++) {
		for (int i = 0; i < g.n; i++) {
			for (int j = 0; j < g.n; j++) {
				if (d[i][k] != inf && d[k][j] != inf) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	graph<int> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g.add_edge(--u, --v, w);
	}

	auto dist = floyd_warshall(g);

	vector<vector<int>> in_edges(n, vector<int>(n));

	for (int s = 0; s < n; s++) {
		for (int t = 0; t < n; t++) {
			if (s == t) continue;
			for (int i : g.adj[t]) {
				int x = g.edges[i].u ^ g.edges[i].v ^ t;
				if (dist[s][x] + g.edges[i].w == dist[s][t]) {
					in_edges[s][t]++;
				}
			}
		}
	}

	for (int s = 0; s < n; s++) {
		for (int t = s + 1; t < n; t++) {
			int c = 0;
			for (int i = 0; i < n; i++) {
				if (dist[s][i] + dist[i][t] == dist[s][t]) {
					c += in_edges[s][i];
				}
			}
			cout << c << ' ';
		}
	}
	cout << '\n';
	return 0;
}