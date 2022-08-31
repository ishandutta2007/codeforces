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
	segment_tree(const std::vector<U> &v, int n, T e, F f): n(n), e(e), f(f) {
		ver.push_back(build(v, 0, n - 1));
	}

	template<typename U>
	int build(const std::vector<U> &v, int l, int r) {
		if (l == r)
			return new_node(T(v[l]));
		int mid = (l + r) >> 1;
		int il = build(v, l, mid);
		int ir = build(v, mid + 1, r);
		return new_node(f(t[il].val, t[ir].val), il, ir);
	}

	template<typename U>
	int update(int idx, const U &val, int k = -1) {
		if (k == -1) k = ver.back();
		ver.push_back(update_helper(idx, val, k, 0, n - 1));
		return ver.back();
	}

	template<typename U>
	int update_helper(int idx, const U &val, int i, int l, int r) {
		if (l == r)
			return new_node(T(val));
		int mid = (l + r) >> 1;
		if (idx <= mid) {
			int il = update_helper(idx, val, t[i].l, l, mid);
			return new_node(f(t[il].val, t[t[i].r].val), il, t[i].r);
		} else {
			int ir = update_helper(idx, val, t[i].r, mid + 1, r);
			return new_node(f(t[t[i].l].val, t[ir].val), t[i].l, ir);
		}
	}

	T query(int ql, int qr, int k = -1) {
		if (k == -1) k = ver.back();
		return query_helper(ql, qr, k, 0, n - 1);
	}

	T query_helper(int ql, int qr, int i, int l, int r) {
		if (r < ql || qr < l)
			return e;
		if (ql <= l && r <= qr)
			return t[i].val;
		int mid = (l + r) >> 1;
		return f(query_helper(ql, qr, t[i].l, l, mid), query_helper(ql, qr, t[i].r, mid + 1, r));
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	for (auto &x : a) cin >> x, --x;

	vector<vector<int>> pos(n);
	for (int i = 0; i < n; i++) {
		pos[a[i]].push_back(i);
	}

	segment_tree<int> st(vector<int>(n), n, 0, [&](int x, int y) {
		return x + y;
	});

	vector<int> vers(n);
	for (int i = 0; i < n; i++) {
		vers[i] = st.ver.back();
		for (int j : pos[i]) {
			vers[i] = st.update(j, 1);
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

		int len = r - l + 1, allowed = (r - l + 1 + 1) / 2;

		int lo = 0, hi = n - 1, minus = 0;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			int query = st.query(l, r, vers[mid]) - minus;
			if (query > allowed) {
				hi = mid;
				len = query;
			} else if (len - query > allowed) {
				lo = mid + 1;
				len -= query;
				minus += query;
			} else {
				lo = -1;
				break;
			}
		}

		if (lo == -1) {
			cout << 1 << '\n';
		} else {
			cout << 2 * len - (r - l + 1) << '\n';
		}
	}
	return 0;
}