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
		if (lazy[x]) {
			t[x << 1] += lazy[x];
			t[x << 1 | 1] += lazy[x];
			lazy[x << 1] += lazy[x];
			lazy[x << 1 | 1] += lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int idx, const U &val) {
		update_helper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int idx, const U &val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		if (idx <= mid)
			update_helper(idx, val, i << 1, l, mid);
		else update_helper(idx, val, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
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
			t[i] += val;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> p(n), q(n);
	for (int i = 0; i < n; i++) cin >> p[i], --p[i];
	for (int i = 0; i < n; i++) cin >> q[i], --q[i];

	vector<int> t(n), pos(n);
	for (int i = 0; i < n; i++) {
		t[q[i]] = i;
		pos[p[i]] = i;
	}

	segment_tree<int> st(vector<int>(n), n, n + 1, [&](int x, int y) {
		return x < y ? x : y;
	});

	int ans = n - 1;
	st.update(0, pos[ans], -1);
	for (int i = 0; i < n; i++) {
		cout << ans + 1 << ' ';
		st.update(0, q[i], 1);
		while (st.t[1] >= 0) {
			ans -= 1;
			st.update(0, pos[ans], -1);
		}
	}
	cout << '\n';
	return 0;
}