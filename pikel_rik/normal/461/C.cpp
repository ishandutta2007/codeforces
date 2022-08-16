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
	segment_tree(const U &arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
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
		if (ql > r or qr < l)
			return e;
		if (ql <= l and r <= qr)
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

	segment_tree<int> st(vector<int>(n, 1), n, 0, [&](auto x, auto y) { return x + y; });

	bool reversed = false;
	int sl = 0, sr = n - 1;

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int p;
			cin >> p;

			int current_width = sr - sl + 1;
			if (p > current_width - p) {
				reversed ^= true;
				p = current_width - p;
			}
			if (!reversed) {
				for (int i = sl + p - 1, j = sl + p; i >= sl; i--, j++) {
					st.update(j, st.query(i, i));
				}
				sl += p;
			} else {
				for (int i = sr - p + 1, j = sr - p; i <= sr; i++, j--) {
					st.update(j, st.query(i, i));
				}
				sr -= p;
			}
		} else {
			int l, r;
			cin >> l >> r, --r;
			if (reversed) {
				l = sr - sl - l, r = sr - sl - r;
				swap(l, r);
			}
			l += sl, r += sl;
			cout << st.query(l, r) << '\n';
		}
	}
	return 0;
}