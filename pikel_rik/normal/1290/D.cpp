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

	int n, k;
	cin >> n >> k;

	auto taste = [&](int c) -> char {
		cout << "? " << c + 1 << endl;
		char yes;
		cin >> yes;
		return yes;
	};

	auto reset = [&](void) -> void {
		cout << "R" << endl;
	};

	if (k == 1) {
		vector<int> bad(n);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				taste(i);
				bad[j] |= (taste(j) == 'Y');
			}
		}
		int d = n - count(bad.begin(), bad.end(), true);
		return cout << "! " << d << endl, 0;
	}

	if (k == n) {
		int d = 0;
		for (int i = 0; i < n; i++) {
			d += taste(i) == 'N';
		}
		return cout << "! " << d << endl, 0;
	}

	k /= 2;

	vector<int> bad(n);
	for (int jump = 1; jump < n / k; jump++) {
		for (int i = 0; i < jump; i++) {
			if (i + jump >= n / k) {
				break;
			}
			for (int j = i; j < n / k; j += jump) {
				for (int ii = j * k; ii < (j + 1) * k; ii++) {
					bad[ii] |= taste(ii) == 'Y';
				}
			}
			reset();
		}
	}
	int d = n - count(bad.begin(), bad.end(), true);
	cout << "! " << d << endl;
	return 0;
}