#include <bits/stdc++.h>
using namespace std;

struct graph {
	struct edge {
		int u, v;
		edge(int u, int v): u(u), v(v) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	graph(): n(), m() {}
	graph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(m);
	}

	int add_edge(int u, int v) {
		adj[u].push_back(m);
		adj[v].push_back(m);
		edges.emplace_back(u, v);
		return m++;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto is_bipartite = [&](const graph &g) -> bool {
		vector<int> c(g.n, -1);
		auto dfs = [&](int u, const auto &self) -> void {
			for (int i : g.adj[u]) {
				int v = g.edges[i].u ^ g.edges[i].v ^ u;
				if (c[v] == -1) {
					c[v] = c[u] ^ 1;
					self(v, self);
				}
			}
		};

		for (int i = 0; i < g.n; i++) {
			if (c[i] == -1) {
				c[i] = 0;
				dfs(i, dfs);
			}
		}

		bool f = true;
		for (const auto &e : g.edges) {
			f &= c[e.u] != c[e.v];
		}
		return f;
	};

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<string> a(n), b(n);
		for (auto &s : a) cin >> s;
		for (auto &s : b) cin >> s;

		vector<vector<bool>> adj(n, vector<bool>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = a[i][j] != b[i][j];
			}
		}

		graph g(4 * n); //i = row, i + n = col, i + 2 * n = row dum, i + 3 * n = col dun

		for (int i = 0; i < n; i++) {
			g.add_edge(i, i + 2 * n);
			g.add_edge(i + n, i + 3 * n);
			for (int j = 0; j < n; j++) {
				if (adj[i][j]) {
					g.add_edge(i, j + n);
				} else {
					g.add_edge(i + 2 * n, j + n);
					g.add_edge(j + 3 * n, i);
				}
			}
		}

		cout << (is_bipartite(g) ? "YES" : "NO") << '\n';
	}
	return 0;
}