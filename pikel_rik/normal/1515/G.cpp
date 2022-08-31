#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct digraph {
	struct edge {
		int u, v; T w;
		edge(int u, int v, T w): u(u), v(v), w(w) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	digraph(): n(), m() {}
	digraph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(m);
	}

	int add_edge(int u, int v, T w) {
		edges.emplace_back(u, v, w);
		adj[u].emplace_back(m);
		return m++;
	}

	digraph transpose() const {
		digraph rev(n);
		for (auto&[u, v, w] : edges) {
			rev.add_edge(v, u, w);
		}
		return rev;
	}
};

std::vector<std::vector<int>> get_sccs(const digraph<int> &g) {
	digraph<int> gr = g.transpose();
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

	digraph<int> g(n, m);
	for (int i = 0, a, b, l; i < m; i++) {
		cin >> a >> b >> l;
		g.add_edge(--a, --b, l);
	}

	auto sccs = get_sccs(g);

	vector<int> leader(n);
	vector<bool> in_scc(n), visited(n);
	vector<long long> d(n), gcd(n);

	for (auto &scc : sccs) {
		for (auto &x : scc) {
			in_scc[x] = true;
			leader[x] = scc.front();
		}

		auto dfs = [&](int x, const auto &self) -> void {
			visited[x] = true;
			for (int i : g.adj[x]) {
				const auto &e = g.edges[i];
				if (!in_scc[e.v]) {
					continue;
				}
				if (!visited[e.v]) {
					d[e.v] = d[e.u] + e.w;
					self(e.v, self);
				} else {
					gcd[scc.front()] = __gcd(gcd[scc.front()], d[e.u] - d[e.v] + e.w);
				}
			}
		};

		dfs(scc.front(), dfs);
		for (auto &x : scc) {
			in_scc[x] = false;
		}
	}

	int q;
	cin >> q;

	for (int i = 0, v, s, t; i < q; i++) {
		cin >> v >> s >> t, --v;
		int d1 = __gcd(s, t), d2 = __gcd(gcd[leader[v]], (long long)t);
		cout << (d1 % d2 == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}