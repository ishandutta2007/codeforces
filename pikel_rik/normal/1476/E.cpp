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

std::vector<int> topological_sort(const digraph &g) {
	std::vector<int> q, deg(g.n);
	q.reserve(g.n);

	for (auto&[u, v] : g.edges) {
		deg[v]++;
	}

	std::vector<bool> visited(g.n);
	for (int i = 0; i < g.n; i++) {
		if (deg[i] == 0) {
			visited[i] = true;
			q.push_back(i);
		}
	}

	for (int i = 0; i < int(q.size()); i++) {
		int x = q[i];
		for (int j : g.adj[x]) {
			const auto &e = g.edges[j];
			deg[e.v]--;
			if (deg[e.v] == 0) {
				visited[e.v] = true;
				q.push_back(e.v);
			}
		}
	}

	if (q.size() != g.n)
		q = {-1};
	return q;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<string> p(n), s(m);
	vector<int> mt(m);

	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		mp[p[i]] = i;
	}

	digraph g(n);
	for (int i = 0; i < m; i++) {
		cin >> s[i] >> mt[i], --mt[i];
		bool matched = false;
		for (int mask = 0; mask < (1 << k); mask++) {
			string temp = s[i];
			for (int j = 0; j < k; j++) {
				if (mask & (1 << j)) {
					temp[j] = '_';
				}
			}
			if (p[mt[i]] == temp) {
				matched = true;
			} else {
				auto it = mp.find(temp);
				if (it != mp.end()) {
					g.add_edge(mt[i], it->second);
				}
			}
		}
		if (!matched) {
			return cout << "NO\n", 0;
		}
	}

	auto order = topological_sort(g);
	if (order.front() == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		for (auto i : order) cout << i + 1 << ' ';
		cout << '\n';
	}
	return 0;
}