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

	int n, k, m;
	cin >> n >> k >> m, --k;

	int sz = n + n + m;

	vector<int> init(sz);
	for (int i = 0, j = -1; i < sz; i++, j--) {
		init[i] = j;
	}

	segment_tree<int> st(init, sz, 0, [&](int x, int y) {
		return x < y ? x : y;
	});

	set<pair<int, int>> s;
	while (m--) {
		int x, y;
		cin >> x >> y, --x, --y;

		auto [it, f] = s.insert(make_pair(x, y));
		if (!f) {
			st.update(y + abs(x - k), sz - 1, -1);
			s.erase(it);
		} else {
			st.update(y + abs(x - k), sz - 1, 1);
		}

		int lo = 0, hi = sz - (int) s.size();
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (mid + st.query(mid, mid + (int) s.size() - 1) >= 0) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		cout << max(0, lo + (int) s.size() - n) << '\n';
	}
	return 0;
}