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

    int addEdge(int u, int v) {
		edges.emplace_back(u, v);
        adj[u].push_back(m++);
        return m - 1;
    }

    int addVertex() {
    	n++;
    	adj.emplace_back();
    	return n - 1;
    }

    size_t size() {
    	return n;
    }

    Digraph transpose() const {
        Digraph rev(n);
        for (auto&[u, v] : edges) {
            rev.addEdge(v, u);
        }
        return rev;
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	Digraph g(m);
	for (int i = 0; i < n; i++) {
		map<int, vector<int>> mp;
		for (int j = 0; j < m; j++) {
			if (a[i][j] != -1) {
				mp[a[i][j]].emplace_back(j);
			}
		}

		for (auto it = mp.begin(); it != mp.end(); it++) {
			auto nxt = next(it);
			if (nxt != mp.end()) {
				int id = g.addVertex();
				for (int x : it->second) {
					g.addEdge(id, x);
				}
				for (int x : nxt->second) {
					g.addEdge(x, id);
				}
			}
		}
	}

	bool cycle = false;
	vector<int> order;
	vector<bool> visited(g.size()), active(g.size());

	function<void(int)> dfs = [&](int x) {
		visited[x] = true;
		active[x] = true;
		for (int i : g.adj[x]) {
			const auto &e = g.edges[i];
			if (active[e.v]) {
				cycle = true;
			} else if (!visited[e.v]) {
				dfs(e.v);
			}
		}
		active[x] = false;
		order.push_back(x);
	};

	for (int i = 0; i < g.size(); i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}

	if (cycle) {
		cout << "-1\n";
	} else {
		for (int i : order) {
			if (i < m) {
				cout << i + 1 << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}