#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

struct Digraph {
    struct edge {
        int u, v;
        edge(int u, int v): u(u), v(v) {}
    };

    int n, m;
    vector<edge> edges;
    vector<vector<int>> adj;

    Digraph(): n(), m() {}
    Digraph(int n): n(n), m(), adj(n) {}

    const vector<int>& operator[](int x) const { return adj[x]; }
    vector<int>& operator[](int x) { return adj[x]; }

    void addEdge(int u, int v) {
        adj[u].push_back(m);
        edges.emplace_back(u, v);
        m++;
    }

    Digraph transpose() const {
        Digraph rev(n);
        for (auto &[u, v] : edges) {
            rev.addEdge(v, u);
        }
        return rev;
    }
};

vector<int> SCC(const Digraph &g) {
	Digraph grev = g.transpose();
	int timer = 0;
	vector<int> f(g.n), visited(g.n), l(g.n);

	function<void(int)> dfs = [&](int x) {
		visited[x] = true;
		for (int i : grev[x]) {
			const auto& e = grev.edges[i];
			if (!visited[e.v]) {
				dfs(e.v);
			}
		}
		f[timer++] = x;
	};
	for (int i = 0; i < g.n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	int s;
	dfs = [&](int x) {
		visited[x] = true;
		l[x] = s;
		for (int i : g[x]) {
			const auto& e = g.edges[i];
			if (!visited[e.v]) {
				dfs(e.v);
			}
		}
	};
	fill(visited.begin(), visited.end(), false);
	for (int i = g.n - 1; i >= 0; i--) {
		if (!visited[f[i]]) {
			s = f[i];
			dfs(f[i]);
		}
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	Digraph g(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0, x; j < n; j++) {
			cin >> x;
			if (x) {
				g.addEdge(i, j);
			}
		}
	}

	auto l = SCC(g);

	for (int i = 1; i < n; i++) {
		if (l[i] != l[i - 1]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}