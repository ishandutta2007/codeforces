#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
		build(v, 1, 0, n - 1);
	}

	template<typename U>
	void build(const std::vector<U> &v, int i, int l, int r) {
		if (l == r) {
			t[i] = T(v[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(v, i << 1, l, mid);
		build(v, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	template<typename U>
	void update(int idx, U val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] += T(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (qr < l || r < ql)
			return e;
		if (ql <= l && r <= qr)
			return t[i];
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> g(n);
	for (int i = 0, u, v; i + 1 < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int timer = 0, lg = 32 - __builtin_clz(n);
	vector<int> tin(n), tout(n);
	vector<vector<int>> up(n, vector<int>(lg));

	auto pre_dfs = [&](int u, int p, const auto &self) -> void {
		up[u][0] = p;
		for (int i = 1; i < lg && up[u][i - 1] != -1; i++) {
			up[u][i] = up[up[u][i - 1]][i - 1];
		}
		tin[u] = timer++;
		for (int v : g[u]) {
			if (v != p) {
				self(v, u, self);
			}
		}
		tout[u] = timer++;
	};

	pre_dfs(0, -1, pre_dfs);

	auto is_anc = [&](int u, int v) -> bool {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	auto lca = [&](int u, int v) -> int {
		if (is_anc(u, v))
			return u;
		if (is_anc(v, u))
			return v;
		for (int i = lg - 1; i >= 0; i--) {
			if (up[u][i] != -1 && !is_anc(up[u][i], v)) {
				u = up[u][i];
			}
		}
		return up[u][0];
	};

	auto climb_to = [&](int u, int v) -> int {
		for (int i = lg - 1; i >= 0; i--) {
			if (up[u][i] != -1 && !is_anc(up[u][i], v)) {
				u = up[u][i];
			}
		}
		return u;
	};

	int m;
	cin >> m;

	vector<vector<pair<int, int>>> queries(n);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v, --u, --v;
		queries[lca(u, v)].emplace_back(u, v);
	}

	segment_tree<int> st(vector<int>(timer), timer, 0, [&](int x, int y) {
		return x + y;
	});

	long long ans = 0;
	vector<int> cnt(n);

	auto dfs = [&](int u, int p, const auto &self) -> void {
		int sz = (int) queries[u].size();
		ans += ((long long)sz * sz - sz) / 2;

		map<pair<int, int>, int> mp;
		for (auto [a, b] : queries[u]) {
			ans += st.query(tin[u], tout[u]);
			if (a != u) {
				a = climb_to(a, u);
				ans -= st.query(tin[a], tout[a]);
				ans -= cnt[a]++;
			}
			if (b != u) {
				b = climb_to(b, u);
				ans -= st.query(tin[b], tout[b]);
				ans -= cnt[b]++;
			}
			if (a != u && b != u) {
				if (a > b) swap(a, b);
				ans += mp[make_pair(a, b)]++;
			}
		}
		for (auto [a, b] : queries[u]) {
			st.update(tin[a], 1);
			st.update(tin[b], 1);
		}
		for (int v : g[u]) {
			if (v != p) {
				self(v, u, self);
			}
		}
		for (auto [a, b] : queries[u]) {
			st.update(tin[a], -1);
			st.update(tin[b], -1);
		}
	};

	dfs(0, -1, dfs);
	cout << ans << '\n';
	return 0;
}