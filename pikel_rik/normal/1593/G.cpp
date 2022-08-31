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

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = (int) s.length();

		struct node {
			int starting;
			int length;

			node() : starting(-1), length() { }

			node(char c) {
				starting = (c == '[') || (c == ']');
				length = 1;
			}
		};

		segment_tree<node> st(vector<char>(s.begin(), s.end()), n, node(), [&](const node &x, const node &y) {
			if (x.starting == -1 || x.length == 0) {
				return y;
			} else if (y.starting == -1 || y.length == 0) {
				return x;
			}
			node result;
			int x_ending = (x.length % 2 == 0 ? 1 - x.starting : x.starting);
			if (x_ending == y.starting) {
				if (x.length >= y.length) {
					result.starting = x.starting;
				} else {
					result.starting = (x.length % 2 == 0 ? y.starting : 1 - y.starting);
				}
				result.length = max(x.length, y.length) - min(x.length, y.length);
			} else {
				result.starting = x.starting;
				result.length = x.length + y.length;
			}
			return result;
		});

		int q;
		cin >> q;

		while (q--) {
			int l, r;
			cin >> l >> r, --l, --r;

			node result = st.query(l, r);
			if (result.starting == 1) {
				cout << (result.length + 1) / 2 << '\n';
			} else {
				cout << result.length / 2 << '\n';
			}
		}
	}
	return 0;
}