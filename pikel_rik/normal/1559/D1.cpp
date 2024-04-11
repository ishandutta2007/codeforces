#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p, r;

	union_find() : n(), c() {}
	union_find(int n) : n(n), c(n), p(n), r(n, 1) {
		std::iota(p.begin(), p.end(), 0);
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
		if (l1 == l2) {
			return false;
		}
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

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	union_find uf_a(n), uf_b(n);
	for (int i = 0, u, v; i < m1; i++) {
		cin >> u >> v;
		uf_a.merge(--u, --v);
	}

	for (int i = 0, u, v; i < m2; i++) {
		cin >> u >> v;
		uf_b.merge(--u, --v);
	}

	vector<pair<int, int>> ans;
	for (int u = 0; u < n; u++) {
		for (int v = 0; v < n; v++) {
			if (uf_a.find(u) != uf_a.find(v) && uf_b.find(u) != uf_b.find(v)) {
				uf_a.merge(u, v);
				uf_b.merge(u, v);
				ans.emplace_back(u, v);
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto &[u, v] : ans) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
	return 0;
}