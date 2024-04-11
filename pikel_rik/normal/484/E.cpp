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
	segment_tree(const U &arr, int n, T e, F f): n(n), e(e), f(f) {
		ver.push_back(build(arr, 0, n - 1));
	}

	template<typename U>
	int build(const U &arr, int l, int r) {
		if (l == r)
			return new_node(T(arr[l]));
		int mid = (l + r) >> 1;
		int vl = build(arr, l, mid);
		int vr = build(arr, mid + 1, r);
		return new_node(f(t[vl].val, t[vr].val), vl, vr);
	}

	template<typename U>
	int update(int idx, U val, int k = -1) {
		if (k == -1) k = ver.back();
		ver.push_back(update_helper(idx, val, k, 0, n - 1));
		return ver.back();
	}

	template<typename U>
	int update_helper(int idx, U val, int i, int l, int r) {
		if (l == r)
			return new_node(T(val));
		int mid = (l + r) >> 1;
		if (idx <= mid) {
			int vl = update_helper(idx, val, t[i].l, l, mid);
			return new_node(f(t[vl].val, t[t[i].r].val), vl, t[i].r);
		} else {
			int vr = update_helper(idx, val, t[i].r, mid + 1, r);
			return new_node(f(t[t[i].l].val, t[vr].val), t[i].l, vr);
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

struct seg_node {
	int length;
	int left, best, right;
	seg_node() : length(), left(), best(), right() { }
	seg_node(int x) : length(1), left(x), best(x), right(x) { }
};

seg_node combine(const seg_node &x, const seg_node &y) {
	seg_node res;
	res.length = x.length + y.length;
	res.left = x.left, res.right = y.right;
	res.best = max({x.best, y.best, x.right + y.left});
	if (x.best == x.length)
		res.left = x.length + y.left;
	if (y.best == y.length)
		res.right = x.right + y.length;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	segment_tree<seg_node> st(vector<int>(n), n, seg_node(), combine);

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return a[i] > a[j];
	});

	vector<int> ver(n);
	for (int i = 0; i < n; i++) {
		ver[i] = st.update(ind[i], 1);
	}

	int m;
	cin >> m;

	while (m--) {
		int l, r, w;
		cin >> l >> r >> w, --l, --r;

		int lo = 0, hi = n - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			seg_node res = st.query(l, r, ver[mid]);
			if (res.best >= w) {
				hi = mid;
			} else lo = mid + 1;
		}
		cout << a[ind[lo]] << '\n';
	}
	return 0;
}