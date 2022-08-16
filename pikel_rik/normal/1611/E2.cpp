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

struct LCA {
	int timer, lg;
	std::vector<int> tin, tout, lvl;
	std::vector<std::vector<int>> up;

	LCA(const graph &g, int root = 0) : timer(0), tin(g.n), tout(g.n), lvl(g.n) {
		lg = 32 - __builtin_clz(g.n);
		up.assign(g.n, std::vector<int>(lg, -1));

		auto dfs = [&](int u, const auto &self) -> void {
			tin[u] = timer++;
			for (int i = 1; i < lg && up[u][i - 1] != -1; i++) {
				up[u][i] = up[up[u][i - 1]][i - 1];
			}
			for (int i : g.adj[u]) {
				int v = g.edges[i].u ^ g.edges[i].v ^ u;
				if (v != up[u][0]) {
					lvl[v] = lvl[u] + 1;
					up[v][0] = u;
					self(v, self);
				}
			}
			tout[u] = timer++;
		};

		if (root == 0) {
			for (int u = 0; u < g.n; u++) {
				if (up[u][0] == -1) {
					dfs(u, dfs);
				}
			}
		} else {
			dfs(root, dfs);
		}
	}

	inline bool is_anc(int u, int v) {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	int lca(int u, int v) {
		if (is_anc(u, v))
			return u;
		if (is_anc(v, u))
			return v;
		for (int i = lg - 1; i >= 0; i--) {
			if (up[u][i] != -1 && !is_anc(up[u][i], v)) {
				u = up[u][i];
			}
		}
		return up[u][0];
	}

	int kth_ancestor(int u, int k) {
		for (int i = 0; i < lg; i++) {
			if (k >> i & 1) {
				assert(up[u][i] != -1);
				u = up[u][i];
			}
		}
		return u;
	}

	int dist(int u, int v) {
		return lvl[u] + lvl[v] - 2 * lvl[lca(u, v)];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> x(k);
		for (int i = 0; i < k; i++) {
			cin >> x[i], --x[i];
		}

		graph g(n, n - 1);
		for (int i = 0, u, v; i < n - 1; i++) {
			cin >> u >> v;
			g.add_edge(--u, --v);
		}

		LCA lca(g);

		sort(x.begin(), x.end(), [&](int u, int v) {
			return lca.lvl[u] < lca.lvl[v];
		});

		vector<bool> not_allowed(n);
		auto mark = [&](int u, auto &&self) -> void {
			not_allowed[u] = true;
			for (int i : g.adj[u]) {
				int v = g.edges[i].u ^ g.edges[i].v ^ u;
				if (v != lca.up[u][0] && !not_allowed[v]) {
					self(v, self);
				}
			}
		};

		int min_friends = 0;
		for (int u : x) {
			int dist = lca.lvl[u];
			u = lca.kth_ancestor(u, dist / 2);
			if (!not_allowed[u]) {
				mark(u, mark);
				min_friends += 1;
			}
		}

		bool winnable = false;
		for (int u = 1; u < n; u++) {
			if (g.adj[u].size() == 1 && !not_allowed[u]) {
				winnable = true;
				break;
			}
		}

		if (winnable) {
			cout << "-1\n";
		} else {
			cout << min_friends << '\n';
		}
	}
	return 0;
}