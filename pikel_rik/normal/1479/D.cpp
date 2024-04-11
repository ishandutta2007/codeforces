#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	struct node {
		T val;
		int l, r;
		node(T val) : val(val) {}
		node(T val, int l, int r) : val(val), l(l), r(r) {}
	};

	std::vector<node> t;

	template <typename...args>
	int new_node(args...A) {
		int id = (int) t.size();
		t.emplace_back(A...);
		return id;
	}

	int n;
	std::vector<int> ver;
	T e;
	F f;

	segment_tree() : ver(), n(), e(), f() {}

	template<typename U>
	segment_tree(const U &arr, int n, T e, F f): n(n), e(e), f(f) {
		ver.push_back(build(arr, 0, n - 1));
	}

	template<typename U>
	int build(const U &arr, int l, int r) {
		if (l == r)
			return new_node(T(arr[l]));
		int mid = (l + r) >> 1;
		int vl = build(arr, l, mid);
		int vr = build(arr, mid + 1, r);
		return new_node(f(t[vl].val, t[vr].val), vl, vr);
	}

	template<typename U>
	int update(int idx, U val, int k) {
		ver.push_back(update_helper(idx, val, k, 0, n - 1));
		return ver.back();
	}

	template<typename U>
	int update_helper(int idx, U val, int i, int l, int r) {
		if (l == r)
			return new_node(t[i].val ^ val);
		int mid = (l + r) >> 1;
		if (idx <= mid) {
			int vl = update_helper(idx, val, t[i].l, l, mid);
			return new_node(f(t[vl].val, t[t[i].r].val), vl, t[i].r);
		} else {
			int vr = update_helper(idx, val, t[i].r, mid + 1, r);
			return new_node(f(t[t[i].l].val, t[vr].val), t[i].l, vr);
		}
	}

	int ql, qr, lca;
	uint64_t lca_val;

	int find_odd(int l, int r, int i, int j) {
		ql = l, qr = r;
		return find_odd_helper(i, j, 0, n - 1);
	}

	int find_odd_helper(int i, int j, int l, int r) {
		if (r < ql || qr < l || (t[i].val ^ t[j].val) == (l <= lca && lca <= r ? lca_val : 0))
			return -1;
		if (l == r)
			return l + 1;
		int mid = (l + r) >> 1;
		int x = find_odd_helper(t[i].l, t[j].l, l, mid);
		return x != -1 ? x : find_odd_helper(t[i].r, t[j].r, mid + 1, r);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	vector<uint64_t> h(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i], --a[i];
		h[i] = rng();
	}

	vector<vector<int>> g(n);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v, --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	segment_tree<uint64_t> st(vector<int>(n), n, 0, [&](const uint64_t &x, const uint64_t &y) {
		return x ^ y;
	});

	int timer = 0;
	vector<int> tin(n), tout(n), ver(n);
	vector<vector<int>> up(n, vector<int>(20, -1));

	auto dfs = [&](int x, int p, const auto &self) -> void {
		tin[x] = timer++, up[x][0] = p;
		for (int i = 1; i < 20 && up[x][i - 1] != -1; i++) {
			up[x][i] = up[up[x][i - 1]][i - 1];
		}
		if (p == -1) {
			ver[x] = st.update(a[x], h[a[x]], st.ver.back());
		} else {
			ver[x] = st.update(a[x], h[a[x]], ver[p]);
		}
		for (int i : g[x]) {
			if (i != p) {
				self(i, x, self);
			}
		}
		tout[x] = timer++;
	};

	dfs(0, -1, dfs);

	auto f = [&](int u, int v) -> bool {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};

	auto lca = [&](int u, int v) -> int {
		if (f(u, v))
			return u;
		if (f(v, u))
			return v;
		for (int i = 19; i >= 0; i--) {
			if (up[u][i] != -1 && !f(up[u][i], v)) {
				u = up[u][i];
			}
		}
		return up[u][0];
	};

	while (q--) {
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		--u, --v, --l, --r;

		int p = lca(u, v);
		st.lca = a[p], st.lca_val = h[a[p]];
		cout << st.find_odd(l, r, ver[u], ver[v]) << '\n';
	}
	return 0;
}