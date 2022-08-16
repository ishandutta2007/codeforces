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

	void clear() {
		m = 0, edges.clear();
		for (int u = 0; u < n; u++) {
			adj[u].clear();
		}
	}
};

std::vector<int> euler_circuit(const graph &g) {
	int start;
	for (start = 0; start < g.n; start++) {
		if (!g.adj[start].empty()) break;
	}

	std::vector<int> deg(g.n), ind(g.n);
	for (int i = 0; i < g.n; i++) {
		deg[i] = ind[i] = g.adj[i].size();
	}

	std::vector<int> st;
	st.push_back(start);

	std::vector<int> circuit;
	circuit.reserve(g.m + 1);

	std::vector<bool> mark(g.m);
	while (!st.empty()) {
		int u = st.back();
		if (!deg[u]) {
			circuit.push_back(u);
			st.pop_back();
		} else {
			while (mark[g.adj[u][--ind[u]]]);
			int i = g.adj[u][ind[u]];
			mark[i] = true;
			int v = u ^ g.edges[i].u ^ g.edges[i].v;
			deg[u]--, deg[v]--;
			st.push_back(v);
		}
	}
	return circuit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}

	graph g(1 << 20);
	for (int k = 20; k >= 0; k--) {
		const int pw = 1 << k;

		g.clear();
		for (int i = 0; i < n; i++) {
			g.add_edge(a[i] & (pw - 1), b[i] & (pw - 1));
		}

		bool no_circuit = false;
		for (int i = 0; i < (1 << k); i++) {
			if (g.adj[i].size() % 2 != 0) {
				no_circuit = true;
			}
		}

		auto circuit = euler_circuit(g);
		if (no_circuit || circuit.size() != n + 1) {
			continue;
		}

		multimap<pair<int, int>, int> mp;
		for (int i = 0; i < n; i++) {
			mp.emplace(make_pair(a[i] & (pw - 1), b[i] & (pw - 1)), i);
		}

		cout << k << '\n';
		for (int i = 1; i < n + 1; i++) {
			int u = circuit[i - 1], v = circuit[i];
			auto it = mp.find(make_pair(u, v));
			if (it != mp.end()) {
				cout << 2 * it->second + 1 << ' ' << 2 * it->second + 2 << ' ';
				mp.erase(it);
			} else {
				it = mp.find(make_pair(v, u));
				cout << 2 * it->second + 2 << ' ' << 2 * it->second + 1 << ' ';
				mp.erase(it);
			}
		}
		cout << '\n';
		break;
	}
	return 0;
}