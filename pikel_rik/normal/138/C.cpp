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
	vector<T> t, lazy;
	T e;
	F f;
	SegmentTree() : n(), e(), f() {}

	template<typename U>
	SegmentTree(const U &arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n, 1), e(e), f(f) {
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
		t[x << 1] *= lazy[x];
		t[x << 1 | 1] *= lazy[x];
		lazy[x << 1] *= lazy[x];
		lazy[x << 1 | 1] *= lazy[x];
		lazy[x] = 1;
	}

	template<typename U>
	void update(int ql, int qr, U val) {
		updateHelper(ql, qr, val, 1, 0, n - 1);
	}

	template<typename U>
	void updateHelper(int ql, int qr, U val, int i, int l, int r) {
		if (ql > r or qr < l)
			return;
		if (ql <= l and r <= qr) {
			t[i] *= val;
			lazy[i] *= val;
			return;
		}
		push(i, l, r);
		int mid = (l + r) >> 1;
		updateHelper(ql, qr, val, i << 1, l, mid);
		updateHelper(ql, qr, val, i << 1 | 1, mid + 1, r);

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
		push(i, l, r);
		int mid = (l + r) >> 1;
		T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
		return f(x, y);
	}
};

int n, m, a[N], h[N], lp[N], rp[N], b[N], z[N];
pair<int, int> l[N], r[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<int> temp;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> h[i] >> lp[i] >> rp[i];
		l[i].first = a[i] - h[i];
		l[i].second = a[i] - 1;
		r[i].first = a[i] + 1;
		r[i].second = a[i] + h[i];
		temp.push_back(l[i].first);
		temp.push_back(l[i].second);
		temp.push_back(r[i].first);
		temp.push_back(r[i].second);
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i] >> z[i];
		temp.push_back(b[i]);
	}

	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	for (int i = 0; i < n; i++) {
		l[i].first = lower_bound(temp.begin(), temp.end(), l[i].first) - temp.begin();
		l[i].second = lower_bound(temp.begin(), temp.end(), l[i].second) - temp.begin();
		r[i].first = lower_bound(temp.begin(), temp.end(), r[i].first) - temp.begin();
		r[i].second = lower_bound(temp.begin(), temp.end(), r[i].second) - temp.begin();
	}

	SegmentTree<ld> st(vector<ld>(temp.size(), 1), temp.size(), 0, [&] (ld x, ld y) {
		return x + y;
	});

	for (int i = 0; i < n; i++) {
		ld p = 1 - lp[i] / ld(100);
		st.update(l[i].first, l[i].second, p);
		p = 1 - rp[i] / ld(100);
		st.update(r[i].first, r[i].second, p);
	}

	ld ans = 0;
	for (int i = 0; i < m; i++) {
		b[i] = lower_bound(temp.begin(), temp.end(), b[i]) - temp.begin();
		ans += st.query(b[i], b[i]) * z[i];
	}
	cout << fixed << setprecision(12);
	cout << ans << '\n';
	return 0;
}