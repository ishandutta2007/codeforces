#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

template<typename T>
struct SegmentTree {
	using F = function<T(const T&, const T&)>;

	int n;
	vector<T> t;
	vector<int> lazy;
	T e;
	F f;
	SegmentTree() : n(), e(), f() {}

	template<typename U>
	SegmentTree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
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
		if (lazy[x]) {
			int mid = (l + r) >> 1;
			t[x << 1].mx = t[x << 1].mn = lazy[x];
			t[x << 1].sum = (ll)(mid - l + 1) * lazy[x];
			t[x << 1 | 1].mx = t[x << 1 | 1].mn = lazy[x];
			t[x << 1 | 1].sum = (ll)(r - mid) * lazy[x];
			lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
			lazy[x] = 0;
		}
	}

	template<typename U>
	void update(int ql, int qr, U val) {
		updateHelper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void updateHelper(int ql, int qr, U val, int i, int l, int r) {
		if (r < ql || qr < l || t[i].mn >= val)
			return;
		if (ql <= l && r <= qr && t[i].mx <= val) {
			t[i].mx = t[i].mn = val;
			t[i].sum = (ll)(r - l + 1) * val;
			lazy[i] = val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		updateHelper(ql, qr, val, i << 1, l, mid);
		updateHelper(ql, qr, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	pair<int, int> query(int ql, int val) {
		return queryHelper(ql, val, 1, 0, n - 1);
	}

	pair<int, int> queryHelper(int ql, int val, int i, int l, int r) {
		if (r < ql || t[i].mn > val)
			return make_pair(0, val);
		if (ql <= l && t[i].sum <= val)
			return make_pair(r - l + 1, val - t[i].sum);
		push(i, l, r);
		int mid = (l + r) >> 1;
		pair<int, int> x = queryHelper(ql, val, i << 1, l, mid);
		pair<int, int> y = queryHelper(ql, x.second, i << 1 | 1, mid + 1, r);
		return make_pair(x.first + y.first, y.second);
	}
};

struct node {
	int mn, mx;
	ll sum;
	node() {}
	node(int x) : mn(x), mx(x), sum(x) {}
};

node combine(const node &a, const node &b) {
	node res;
	res.mn = b.mn;
	res.mx = a.mx;
	res.sum = a.sum + b.sum;
	return res;
}

int n, q, a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];

	SegmentTree<node> st(a, n, node(), combine);

	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;

		if (t == 1) {
			st.update(0, --x, y);
		} else {
			cout << st.query(--x, y).first << '\n';
		}
	}
	return 0;
}