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

	vector<string> a(n);
	for (auto &s : a) cin >> s;

	digraph g(n * m);

	for (int j = 0; j < m; j++) {
		int last0 = -1, last1 = -1;
		for (int i = 0; i < n; i++) {
			if (j > 0 && a[i][j - 1] == '#') {
				if (last0 != -1) {
					g.add_edge(last0 * m + j - 1, i * m + j - 1);
				}
				if (last1 != -1) {
					g.add_edge(last1 * m + j, i * m + j - 1);
				}
			}
			if (a[i][j] == '#') {
				if (last0 != -1) {
					g.add_edge(last0 * m + j - 1, i * m + j);
				}
				if (last1 != -1) {
					g.add_edge(last1 * m + j, i * m + j);
				}
			}
			if (j > 0 && a[i][j - 1] == '#') {
				last0 = i;
			}
			if (a[i][j] == '#') {
				last1 = i;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j > 0 && a[i][j - 1] == '#' && a[i][j] == '#') {
				g.add_edge(i * m + j - 1, i * m + j);
				g.add_edge(i * m + j, i * m + j - 1);
			}
			if (i > 0 && a[i - 1][j] == '#' && a[i][j] == '#') {
				g.add_edge((i - 1) * m + j, i * m + j);
				g.add_edge(i * m + j, (i - 1) * m + j);
			}
		}
	}

	auto sccs = get_sccs(g);

	vector<bool> visited(n * m);
	auto dfs = [&](int x, const auto &self) -> void {
		visited[x] = true;
		for (int i : g.adj[x]) {
			if (!visited[g.edges[i].v]) {
				self(g.edges[i].v, self);
			}
		}
	};

	int ans = 0;
	for (auto &scc : sccs) {
		for (int v : scc) {
			if (a[v / m][v % m] == '#' && !visited[v]) {
				ans += 1;
				dfs(v, dfs);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}