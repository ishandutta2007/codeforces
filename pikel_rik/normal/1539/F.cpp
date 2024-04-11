#include <bits/stdc++.h>
using namespace std;

template<typename T, typename L = T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<L> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() { }

	template<typename U>
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
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

	void push(int x, int l, int r) {
		t[x << 1].mx += lazy[x];
		t[x << 1].mn += lazy[x];
		lazy[x << 1] += lazy[x];
		t[x << 1 | 1].mx += lazy[x];
		t[x << 1 | 1].mn += lazy[x];
		lazy[x << 1 | 1] += lazy[x];
		lazy[x] = 0;
	}

	template<typename U>
	void update(int ql, int qr, const U &val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, const U &val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i].mx += val;
			t[i].mn += val;
			lazy[i] += val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		update_helper(ql, qr, val, i << 1, l, mid);
		update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return query_helper(ql, qr, 1, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (r < ql || qr < l)
			return e;
		if (ql <= l && r <= qr)
			return t[i];
		push(i, l, r);
		int mid = (l + r) >> 1;
		T x = query_helper(ql, qr, i << 1, l, mid), y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

template<typename T>
struct fenwick_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> bit;
	F f;

	fenwick_tree() : n(), f() {}
	fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

	void add(int i, T val) {
		for (++i; i <= n; i += i & -i) {
			bit[i] = f(bit[i], val);
		}
	}

	T query(int i) {
		T ans = 0;
		for (++i; i; i -= i & -i) {
			ans = f(ans, bit[i]);
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	vector<vector<int>> pos(n);
	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);
	}

	struct node {
		int mx, mn;
		node() : mx(INT_MIN), mn(INT_MAX) { }
		node(int x) : mx(x), mn(x) { }
	};

	segment_tree<node, int> st(vector<int>(n + 1), n + 1, node(), [&](const node &x, const node &y) {
		node res;
		res.mx = max(x.mx, y.mx);
		res.mn = min(x.mn, y.mn);
		return res;
	});

	fenwick_tree<int> ft(n);
	for (int i = 0; i < n; i++) {
		st.update(i + 1, n, 1);
		ft.add(i, 1);
	}

	vector<int> ans(n);
	for (auto &v : pos) {
		for (int i : v) {
			int sum = ft.query(i);
			node left = st.query(0, i), right = st.query(i + 1, n);
			tie(left.mx, left.mn) = make_pair(sum - left.mn, sum - left.mx);
			tie(right.mx, right.mn) = make_pair(right.mx - sum, right.mn - sum);

			for (int j : {left.mn + right.mn, left.mx + right.mx}) {
				int abs_val = abs(j);
				if (abs_val % 2 == 0) {
					if (j <= 0) {
						ans[i] = max(ans[i], abs_val / 2 - 1);
					} else {
						ans[i] = max(ans[i], abs_val / 2);
					}
				} else {
					ans[i] = max(ans[i], abs_val / 2);
				}
			}
		}

		for (int i : v) {
			st.update(i + 1, n, -2);
			ft.add(i, -2);
		}

		for (int i : v) {
			int sum = ft.query(i);
			node left = st.query(0, i), right = st.query(i + 1, n);
			tie(left.mx, left.mn) = make_pair(sum - left.mn, sum - left.mx);
			tie(right.mx, right.mn) = make_pair(right.mx - sum, right.mn - sum);

			for (int j : {left.mn + right.mn, left.mx + right.mx}) {
				int abs_val = abs(j);
				if (abs_val % 2 == 0) {
					if (j <= 0) {
						ans[i] = max(ans[i], abs_val / 2 - 1);
					} else {
						ans[i] = max(ans[i], abs_val / 2);
					}
				} else {
					ans[i] = max(ans[i], abs_val / 2);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}