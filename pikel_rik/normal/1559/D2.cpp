#include <bits/stdc++.h>
using namespace std;

struct union_find {
	int n, c;
	std::vector<int> p;
	std::vector<std::vector<int>> v;

	union_find(): n(), c() {}
	union_find(int n): n(n), c(n), p(n), v(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i, v[i] = {i};
		}
	}

	int count() const noexcept {
		return c;
	}

	int find(int x) {
		return p[x];
	}

	bool is_same(int x, int y) {
		return p[x] == p[y];
	}

	bool merge(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 == s2) {
			return false;
		}
		if (v[s2].size() > v[s1].size()) {
			std::swap(s1, s2);
		}
		for (int i : v[s2]) {
			v[s1].push_back(i);
			p[i] = s1;
		}
		v[s2].clear();
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

	if (uf_a.count() > uf_b.count()) {
		swap(uf_a, uf_b);
	}

	vector<pair<int, int>> ans;

	vector<int> left_out;
	auto combine = [&](int u, int v) -> int {
		if (u == -1) {
			return v;
		} else if (v == -1) {
			return u;
		}

		map<int, int> mp_u, mp_v;
		for (auto x : uf_a.v[u]) {
			mp_u[uf_b.p[x]] = x;
		}
		for (auto x : uf_a.v[v]) {
			mp_v[uf_b.p[x]] = x;
		}

		pair<int, int> match(-1, -1);
		for (auto x : mp_u) {
			for (auto y : mp_v) {
				if (x.first != y.first) {
					match.first = x.second;
					match.second = y.second;
				}
				if (match.first != -1) {
					break;
				}
			}
			if (match.first != -1) {
				break;
			}
		}

		if (match.first == -1) {
			left_out.push_back(v);
			return u;
		} else {
			uf_a.merge(match.first, match.second);
			uf_b.merge(match.first, match.second);
			ans.push_back(match);
			return uf_a.p[u];
		}
	};

	sort(left_out.begin(), left_out.end(), [&](int u, int v) {
		return uf_b.p[u] < uf_b.p[v];
	});

	vector<int> tree(2 * n);
	for (int u = 0; u < n; u++) {
		if (uf_a.p[u] == u) {
			tree[u + n] = u;
		} else {
			tree[u + n] = -1;
		}
	}

	for (int i = n - 1; i > 0; i--) {
		tree[i] = combine(tree[i << 1], tree[i << 1 | 1]);
	}

	for (int i = 1; i < (int) left_out.size(); i++) {
		int u = left_out[i - 1], v = left_out[i];
		if (uf_b.p[u] != uf_b.p[v]) {
			uf_a.merge(u, v);
			uf_b.merge(u, v);
			ans.emplace_back(u, v);
		}
	}

	left_out.erase(remove_if(left_out.begin(), left_out.end(), [&](int u) {
		return uf_a.p[u] != u;
	}), left_out.end());

	map<int, int> mp;
	for (auto x : uf_a.v[tree[1]]) {
		mp[uf_b.p[x]] = x;
	}

	for (int u : left_out) {
		for (auto it = mp.begin(); it != mp.end(); it++) {
			if (uf_b.p[u] != it->first) {
				uf_a.merge(u, it->second);
				uf_b.merge(u, it->second);
				ans.emplace_back(u, it->second);
				mp.erase(it);
				break;
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto &[u, v] : ans) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
	return 0;
}