#include <bits/stdc++.h>
using namespace std;

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

	struct edge {
		int u, v;
	};

	int n, m, x;
	cin >> n >> m >> x;

	vector<long long> a(n);
	for (auto &y : a) cin >> y;

	if (accumulate(a.begin(), a.end(), 0ll) < (long long)(n - 1) * x) {
		cout << "NO\n";
		return 0;
	}

	union_find uf(n);
	vector<edge> e(m);
	vector<vector<int>> g(n);

	for (int i = 0; i < m; i++) {
		cin >> e[i].u >> e[i].v;
		if (uf.merge(--e[i].u, --e[i].v)) {
			g[e[i].u].push_back(i);
			g[e[i].v].push_back(i);
		}
	}

	vector<int> deg(n), p(n, -1), p_edge(n, -1);
	auto dfs = [&](int u, const auto &self) -> void {
		deg[u] = g[u].size() - (p[u] != -1);
		for (int i : g[u]) {
			int v = u ^ e[i].u ^ e[i].v;
			if (v != p[u]) {
				p[v] = u, p_edge[v] = i;
				self(v, self);
			}
		}
	};

	dfs(0, dfs);

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ans, leaves;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (p[u] == -1) {
			continue;
		}

		int v = p[u];
		if (a[v] + a[u] >= x) {
			a[v] = a[v] + a[u] - x;
			ans.push_back(p_edge[u]);
		} else {
			leaves.push_back(p_edge[u]);
		}

		deg[v] -= 1;
		if (deg[v] == 0) {
			q.push(v);
		}
	}

	ans.insert(ans.end(), leaves.rbegin(), leaves.rend());

	cout << "YES\n";
	for (int i : ans) cout << i + 1 << '\n';
	return 0;
}