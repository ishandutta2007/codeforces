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

	int add_vertex() {
		adj.emplace_back();
		return n++;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> a(n);
	for (auto &x : a) cin >> x;

	vector<string> b(n);
	for (auto &x : b) cin >> x;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = '0' + (a[i][j] == b[i][j]);
		}
	}

	string magic;
	cin >> magic;

	graph g(2 * n);
	vector<int> color(2 * n, -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (magic[i] == '1' && magic[j] == '1') {
				if (a[i][j] == '1') {
					int v = g.add_vertex();
					g.add_edge(n + j, v), g.add_edge(i, v);
				} else {
					g.add_edge(n + j, i);
				}
			} else if (magic[i] == '1') {
				if (color[n + j] != -1 && color[n + j] != (a[i][j] == '0')) {
					return cout << "-1\n", 0;
				}
				color[n + j] = a[i][j] == '0';
			} else if (magic[j] == '1') {
				if (color[i] != -1 && color[i] != (a[i][j] == '0')) {
					return cout << "-1\n", 0;
				}
				color[i] = a[i][j] == '0';
			} else if (a[i][j] == '0') {
				return cout << "-1\n", 0;
			}
		}
	}

	color.resize(g.n, -1);

	auto bfs = [&](queue<int> &q) -> void {
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int i : g.adj[u]) {
				int v = g.edges[i].u ^ g.edges[i].v ^ u;
				if (color[v] == -1) {
					color[v] = color[u] ^ 1;
					q.push(v);
				}
			}
		}
	};

	queue<int> q;
	for (int i = 0; i < g.n; i++) {
		if (color[i] != -1) {
			q.push(i);
		}
	}

	bfs(q);

	for (int i = 0; i < g.n; i++) {
		if (color[i] == -1) {
			q.push(i), color[i] = 0;
			bfs(q);
		}
	}

	for (const auto &e : g.edges) {
		if (color[e.u] == color[e.v]) {
			return cout << "-1\n", 0;
		}
	}

	vector<string> ans;
	for (int i = 0; i < n; i++) {
		if (color[i] == 1) {
			ans.push_back("row " + to_string(i));
		}
		if (color[n + i] == 1) {
			ans.push_back("col " + to_string(i));
		}
	}

	cout << (int) ans.size() << '\n';
	for (auto &s : ans) cout << s << '\n';
	return 0;
}