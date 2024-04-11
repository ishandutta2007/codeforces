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
			t[i] = f(t[i], val);
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

	vector<int> a(n), p(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> p[i];

	int m;
	cin >> m;

	vector<int> b(m);
	for (int i = 0; i < m; i++) cin >> b[i];

	constexpr long long inf = (long long) 1e15;
	segment_tree<long long> st(vector<long long>(m + 1, inf), m + 1, inf, [&](long long x, long long y) {
		return x < y ? x : y;
	});

	st.update(0, 0);

	int seen = 0;
	for (int i = 0; i < n; i++) {
		int j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if (j == m) {
			st.update(0, seen, p[i]);
		} else if (b[j] != a[i]) {
			if (p[i] < 0) {
				st.update(0, seen, p[i]);
			} else {
				st.update(0, j, p[i]);
			}
		} else {
			long long mn = st.query(j, j);
			if (p[i] < 0) {
				st.update(0, seen, p[i]);
			} else {
				st.update(0, j, p[i]);
			}
			st.update(j + 1, mn);
			if (j == seen) {
				seen += 1;
			}
		}
	}

	long long ans = st.query(m, m);
	if (ans < inf) {
		cout << "YES\n";
		cout << ans << '\n';
	} else {
		cout << "NO\n";
	}
	return 0;
}