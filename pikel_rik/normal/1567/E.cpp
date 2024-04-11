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

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	auto f = [&](long long x) -> long long {
		return (x * x + x) / 2;
	};

	struct node {
		long long ans;
		int left, right;
		int left_len, right_len, full;
		node() : ans(), left_len(), right_len(), full() { }
		node(int x) : ans(1), left(x), right(x) {
			left_len = right_len = full = 1;
		}
	};

	segment_tree<node> st(a, n, node(), [&](const node &x, const node &y) {
		if (x.full == 0) {
			return y;
		} else if (y.full == 0) {
			return x;
		}

		node result;
		result.ans = x.ans + y.ans;
		result.left = x.left;
		result.right = y.right;
		result.full = x.full + y.full;

		if (x.right <= y.left) {
			int middle_len = x.right_len + y.left_len;
			result.ans -= f(x.right_len) + f(y.left_len);
			result.ans += f(middle_len);
			if (x.left_len == x.full) {
				result.left_len = middle_len;
			} else {
				result.left_len = x.left_len;
			}
			if (y.left_len == y.full) {
				result.right_len = middle_len;
			} else {
				result.right_len = y.right_len;
			}
		} else {
			result.left_len = x.left_len;
			result.right_len = y.right_len;
		}
		return result;
	});

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x, y;
			cin >> x >> y, --x;
			st.update(x, y);
		} else {
			int l, r;
			cin >> l >> r, --l, --r;
			cout << st.query(l, r).ans << '\n';
		}
	}
	return 0;
}