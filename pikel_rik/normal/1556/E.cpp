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
			t[i] = T(val);
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

	int n, q;
	cin >> n >> q;

	vector<int> a(n), b(n);
	for (auto &x : a) cin >> x;
	for (auto &x : b) cin >> x;

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = a[i] - b[i];
	}

	vector<long long> pref(c.begin(), c.end());
	partial_sum(pref.begin(), pref.end(), pref.begin());

	struct node {
		long long full, left, right, best;
		node() : full(), left(), right(), best(-1) { }
		node(int x) : full(x), left(x), right(x), best(max(0, x)) { }
	};

	auto combine = [&](const node &x, const node &y) -> node {
		if (x.best == -1) {
			return y;
		} else if (y.best == -1) {
			return x;
		}
		node result;
		result.full = x.full + y.full;
		result.left = max(x.left, x.full + y.left);
		result.right = max(x.right + y.full, y.right);
		result.best = max({result.left, result.right, x.right + y.left, x.best, y.best});
		return result;
	};

	segment_tree<node> mx_st(c, n, node(), combine);
	for (auto &x : c) {
		x = -x;
	}
	segment_tree<node> mn_st(c, n, node(), combine);

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

		long long sum = pref[r] - (l == 0 ? 0 : pref[l - 1]);
		if (sum == 0) {
			long long ans = max(abs(mx_st.query(l, r).best), abs(mn_st.query(l, r).best));
			cout << ans << '\n';
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}