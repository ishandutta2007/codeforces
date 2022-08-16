#include <bits/stdc++.h>
using namespace std;

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

std::vector<std::vector<int>> get_sccs(const digraph &g) {
	digraph gr = g.transpose();
	int timer = 0;
	std::vector<int> f(g.n), visited(g.n), l(g.n);

	auto dfs_rev = [&](int x, const auto &dfs_rev) -> void {
		visited[x] = true;
		for (int i : gr.adj[x]) {
			const auto &e = gr.edges[i];
			if (!visited[e.v]) {
				dfs_rev(e.v, dfs_rev);
			}
		}
		f[timer++] = x;
	};

	for (int i = 0; i < g.n; i++) {
		if (!visited[i]) {
			dfs_rev(i, dfs_rev);
		}
	}

	std::vector<int> cur_scc;
	auto dfs = [&](int x, const auto &dfs) -> void {
		visited[x] = true;
		cur_scc.push_back(x);
		for (int i : g.adj[x]) {
			const auto &e = g.edges[i];
			if (!visited[e.v]) {
				dfs(e.v, dfs);
			}
		}
	};

	std::fill(visited.begin(), visited.end(), false);
	std::vector<std::vector<int>> sccs;
	for (int i = g.n - 1; i >= 0; i--) {
		if (!visited[f[i]]) {
			cur_scc.clear();
			dfs(f[i], dfs);
			sccs.push_back(cur_scc);
		}
	}
	std::reverse(sccs.begin(), sccs.end());
	return sccs;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	digraph g(n, m);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		g.add_edge(u, v);
	}

	auto sccs = get_sccs(g);
	vector<int> d(n), ans(m, 1);
	vector<bool> in_scc(n), visited(n);

	for (auto &scc : sccs) {
		for (auto &v : scc) {
			in_scc[v] = true;
		}

		auto dfs = [&](int u, const auto &self) -> void {
			visited[u] = true;
			for (int i : g.adj[u]) {
				int v = g.edges[i].v;
				if (!in_scc[v]) {
					continue;
				}
				if (!visited[v]) {
					d[v] = 1 + d[u];
					self(v, self);
				} else if (d[v] < d[u]) {
					ans[i] = 2;
				}
			}
		};

		dfs(scc.front(), dfs);
		for (auto &v : scc) {
			in_scc[v] = false;
		}
	}

	cout << *max_element(ans.begin(), ans.end()) << '\n';
	for (auto &an : ans) cout << an << ' ';
	cout << '\n';
	return 0;
}