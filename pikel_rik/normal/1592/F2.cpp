#include <bits/stdc++.h>
using namespace std;

struct bipartite_graph {
	struct edge {
		int u, v;
		edge(int u, int v) : u(u), v(v) {}
	};

	int l, r, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	std::vector<int> pl, pr;
	std::vector<bool> visited;

	bipartite_graph() : l(), r(), m() {}

	bipartite_graph(int l, int r, int m = 0) : l(l), r(r), m(), adj(l), pl(l, -1), pr(r, -1), visited(l) {
		edges.reserve(m);
	}

	int add_edge(int u, int v) {
		adj[u].push_back(v);
		edges.emplace_back(u, v);
		return m++;
	}

	bool dfs(int u) {
		visited[u] = true;
		for (int v : adj[u]) {
			if (pr[v] == -1) {
				pl[u] = v;
				pr[v] = u;
				return true;
			}
		}
		for (int v : adj[u]) {
			if (!visited[pr[v]] && dfs(pr[v])) {
				pl[u] = v;
				pr[v] = u;
				return true;
			}
		}
		return false;
	}

	int matching() {
		int ans = 0;
		while (true) {
			std::fill(visited.begin(), visited.end(), false);
			int add = 0;
			for (int u = 0; u < l; u++) {
				if (pl[u] == -1) {
					add += dfs(u);
				}
			}
			if (!add) {
				break;
			}
			ans += add;
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<string> grid(n);
	for (auto &row : grid) cin >> row;

	vector<vector<int>> parity(n, vector<int>(m));

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			parity[i][j] = (grid[i][j] == 'B');
			if (i + 1 < n) {
				parity[i][j] ^= (grid[i + 1][j] == 'B');
			}
			if (j + 1 < m) {
				parity[i][j] ^= (grid[i][j + 1] == 'B');
			}
			if (i + 1 < n && j + 1 < m) {
				parity[i][j] ^= (grid[i + 1][j + 1] == 'B');
			}
			sum += parity[i][j];
		}
	}

	bipartite_graph g(n, m);
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j + 1 < m; j++) {
			if (parity[i][j] && parity[n - 1][j] && parity[i][m - 1]) {
				g.add_edge(i, j);
			}
		}
	}

	int times = g.matching();

	sum -= parity[n - 1][m - 1];

	parity[n - 1][m - 1] ^= times % 2;

	sum -= times;
	sum += parity[n - 1][m - 1];

	cout << sum << '\n';
	return 0;
}