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
		digraph rev(n, m);
		for (auto&[u, v] : edges) {
			rev.add_edge(v, u);
		}
		return rev;
	}
};

std::vector<std::vector<int>> find_sccs(const digraph &g) {
	int timer = 0;
	std::vector<int> tin(g.n, -1), low(g.n);

	std::vector<int> all, path;
	all.reserve(g.n), path.reserve(g.n);

	std::vector<std::vector<int>> sccs;
	auto dfs = [&](int u, const auto &self) -> void {
		low[u] = tin[u] = timer++;
		all.push_back(u), path.push_back(u);
		for (int i : g.adj[u]) {
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
		path.pop_back();
	};

	for (int u = 0; u < g.n; u++) {
		if (tin[u] == -1) {
			dfs(u, dfs);
		}
	}
	std::reverse(sccs.begin(), sccs.end());
	return sccs;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		digraph g(n, m);
		for (int i = 0, u, v; i < m; i++) {
			cin >> u >> v;
			g.add_edge(--u, --v);
		}

		auto sccs = find_sccs(g);

		vector<int> scc_id(n), ans(n);
		for (int i = 0; i < (int) sccs.size(); i++) {
			for (int u : sccs[i]) {
				scc_id[u] = i;
			}
		}

		auto first_dfs = [&](int x, const auto &self) -> void {
			ans[x] = 1;
			for (int i : g.adj[x]) {
				if (!ans[g.edges[i].v]) {
					self(g.edges[i].v, self);
				}
			}
		};

		first_dfs(0, first_dfs);

		auto second_dfs = [&](int x, const auto &self) -> void {
			ans[x] = -1;
			for (int i : g.adj[x]) {
				if (ans[g.edges[i].v] != -1) {
					self(g.edges[i].v, self);
				}
			}
		};

		for (int u = 0; u < n; u++) {
			bool cycle = sccs[scc_id[u]].size() > 1;
			for (int i : g.adj[u]) {
				cycle |= g.edges[i].v == u;
			}
			if (ans[u] == 1 && cycle) {
				second_dfs(u, second_dfs);
			}
		}

		vector<bool> visited(n);

		auto fourth_dfs = [&](int u, const auto &self) -> void {
			ans[u] = 2;
			for (int i : g.adj[u]) {
				if (ans[g.edges[i].v] == 1) {
					self(g.edges[i].v, self);
				}
			}
		};

		auto third_dfs = [&](int u, const auto &self) -> void {
			visited[u] = true;
			for (int i : g.adj[u]) {
				int v = g.edges[i].v;
				if (ans[v] == 1) {
					if (!visited[v]) {
						self(v, self);
					} else {
						fourth_dfs(v, fourth_dfs);
					}
				}
			}
		};

		if (ans[0] == 1) {
			third_dfs(0, third_dfs);
		}

		for (int u = 0; u < n; u++) {
			cout << ans[u] << ' ';
		}
		cout << '\n';
	}
	return 0;
}