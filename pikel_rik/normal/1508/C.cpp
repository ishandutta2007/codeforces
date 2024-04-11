#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct graph {
	struct edge {
		int u, v; T w;
		edge(int u, int v, T w): u(u), v(v), w(w) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	graph(): n(), m() {}
	graph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(m);
	}

	int add_edge(int u, int v, T w) {
		adj[u].emplace_back(m);
		adj[v].emplace_back(m);
		edges.emplace_back(u, v, w);
		return m++;
	}
};

struct union_find {
	int n, c;
	std::vector<int> p, r;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	bool merge(int x, int y) {
		int l1 = find(x);
		int l2 = find(y);
		if (l1 == l2)
			return false;
		if (r[l1] >= r[l2]) {
			r[l1] += r[l2];
			p[l2] = l1;
		} else {
			p[l1] = l2;
			r[l2] += r[l1];
		}
		c -= 1;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	graph<int> g(n);
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		g.add_edge(--u, --v, w);
	}

	union_find uf(n);

	list<int> l;
	for (int x = 0; x < n; x++) {
		l.push_back(x);
	}

	vector<bool> visited(n), bad(n);

	for (int x = 0; x < n; x++) {
		if (visited[x]) {
			continue;
		}
		queue<int> q;
		q.push(x);
		visited[x] = true;

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int i : g.adj[u]) {
				int v = u ^ g.edges[i].u ^ g.edges[i].v;
				bad[v] = true;
			}

			for (auto it = l.begin(); it != l.end();) {
				if (!bad[*it]) {
					if (!visited[*it]) {
						uf.merge(u, *it);
						q.push(*it);
						visited[*it] = true;
					}
					it = l.erase(it);
				} else {
					it++;
				}
			}

			for (int i : g.adj[u]) {
				int v = u ^ g.edges[i].u ^ g.edges[i].v;
				bad[v] = false;
			}
		}
	}

	long long edges = ((long long)n * n - n) / 2 - m;
	if (edges < n) {
		int xor_sum = 0;
		for (const auto &e : g.edges) {
			xor_sum ^= e.w;
		}

		vector<int> ind(m);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return g.edges[i].w < g.edges[j].w;
		});

		vector<graph<int>::edge> other;
		for (int u = 0; u < n; u++) {
			for (int i : g.adj[u]) {
				int v = u ^ g.edges[i].u ^ g.edges[i].v;
				bad[v] = true;
			}

			for (int v = 0; v < u; v++) {
				if (!bad[v]) {
					other.emplace_back(v, u, 0);
				}
			}

			for (int i : g.adj[u]) {
				int v = u ^ g.edges[i].u ^ g.edges[i].v;
				bad[v] = false;
			}
		}

		long long ans = LLONG_MAX;
		for (auto &victim : other) {
			victim.w = xor_sum;

			uf = union_find(n);
			for (const auto &e : other) {
				if (e.w == 0) {
					uf.merge(e.u, e.v);
				}
			}

			bool victim_taken = false;
			long long cur_ans = 0;

			for (int i : ind) {
				const auto &e = g.edges[i];
				if (!victim_taken && victim.w <= e.w) {
					victim_taken = true;
					if (uf.merge(victim.u, victim.v)) {
						cur_ans += victim.w;
					}
				}
				if (uf.merge(e.u, e.v)) {
					cur_ans += e.w;
				}
			}

			ans = min(ans, cur_ans);
			victim.w = 0;
		}
		cout << ans << '\n';
	} else {
		long long ans = 0;

		vector<int> ind(m);
		iota(ind.begin(), ind.end(), 0);
		sort(ind.begin(), ind.end(), [&](int i, int j) {
			return g.edges[i].w < g.edges[j].w;
		});

		for (int i : ind) {
			const auto &e = g.edges[i];
			if (uf.merge(e.u, e.v)) {
				ans += e.w;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}