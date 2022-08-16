#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct segment_tree {
	using F = std::function<T(const T&, const T&)>;

	int n;
	std::vector<T> t;
	std::vector<int> lazy;
	T e;
	F f;

	segment_tree() : n(), e(), f() {}

	template<typename U>
	segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n, -1), e(e), f(f) {
		build(arr, 1, 0, n - 1);
	}

	template<typename U>
	void build(const U &arr, int i, int l, int r) {
		if (l == r) {
			t[i] = T(arr[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);
		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	void push(int x, int l, int r) {
		if (lazy[x] != -1) {
			int mid = (l + r) >> 1;
			t[x << 1] = (mid - l + 1) * lazy[x];
			t[x << 1 | 1] = (r - mid) * lazy[x];
			lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
			lazy[x] = -1;
		}
	}

	template<typename U>
	void update(int ql, int qr, U val) {
		update_helper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void update_helper(int ql, int qr, U val, int i, int l, int r) {
		if (r < ql || qr < l)
			return;
		if (ql <= l && r <= qr) {
			t[i] = val * (r - l + 1);
			lazy[i] = val;
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

	int t;
	cin >> t;

	while (t--) {
		int n, q;
		cin >> n >> q;

		string s, f;
		cin >> s >> f;

		vector<int> l(q), r(q);
		for (int i = 0; i < q; i++) {
			cin >> l[i] >> r[i];
			--l[i], --r[i];
		}

		segment_tree<int> st(vector<int>(n), n, 0, [&](auto x, auto y) { return x + y; });
		for (int i = 0; i < n; i++) {
			if (f[i] == '1') {
				st.update(i, i, 1);
			}
		}

		bool ok = true;
		for (int i = q - 1; i >= 0; i--) {
			int c = st.query(l[i], r[i]);
			if (c < r[i] - l[i] + 1 - c) {
				st.update(l[i], r[i], 0);
			} else if (r[i] - l[i] + 1 - c < c) {
				st.update(l[i], r[i], 1);
			} else {
				ok = false;
				break;
			}
		}

		for (int i = 0; i < n; i++) {
			ok &= st.query(i, i) == s[i] - '0';
		}

		cout << (ok ? "YES" : "NO") << '\n';
	}
    return 0;
}