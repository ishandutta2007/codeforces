#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

template<typename T>
struct SegmentTree {
	using F = function<T(const T&, const T&)>;

	int n;
	vector<T> t;
	T e;
	F f;
	SegmentTree() : n(), e(), f() {}

	template<typename U>
	SegmentTree(const U &arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
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
		updateHelper(idx, val, 1, 0, n - 1);
	}

	template<typename U>
	void updateHelper(int idx, U val, int i, int l, int r) {
		if (l == r) {
			t[i] = T(val);
			return;
		}
		int mid = (l + r) >> 1;
		if (idx <= mid)
			updateHelper(idx, val, i << 1, l, mid);
		else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

		t[i] = f(t[i << 1], t[i << 1 | 1]);
	}

	T query(int ql, int qr) {
		return queryHelper(ql, qr, 1, 0, n - 1);
	}

	T queryHelper(int ql, int qr, int i, int l, int r) {
		if (ql > r or qr < l)
			return e;
		if (ql <= l and r <= qr)
			return t[i];
		int mid = (l + r) >> 1;
		T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

struct node {
	ll ans;
	int len, l, r;
	node() {}
	node(bool x): ans(x), len(1), l(x), r(x) {}
};

ll f(ll x) {
	return (x * x + x) / 2;
}

node combine(const node &x, const node &y) {
	node res;
	res.ans = x.ans + y.ans;
	res.len = x.len + y.len;
	res.ans -= f(x.r) + f(y.l);
	res.ans += f(x.r + y.l);
	res.l = (x.l == x.len ? x.l + y.l : x.l);
	res.r = (y.r == y.len ? x.r + y.r : y.r);
	return res;
}

int n, m, a[N];
bool b[20][N];
SegmentTree<node> st[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < n; i++) {
			if (a[i] & (1 << j)) {
				b[j][i] = true;
			}
		}
		st[j] = SegmentTree<node>(b[j], n, node(), combine);
	}

	while (m--) {
		int i, v;
		cin >> i >> v; --i;

		ll ans = 0;
		for (int j = 0; j < 20; j++) {
			if ((a[i] ^ v) & (1 << j)) {
				st[j].update(i, bool(v & (1 << j)));
			}
			ans += st[j].t[1].ans << j;
		}
		a[i] = v;
		cout << ans << '\n';
	}
	return 0;
}