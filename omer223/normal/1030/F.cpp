#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))
#define rep(i, k, n) foru(i, k, n)
#define sz(a) a.size()

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

const ll mod = 1e9 + 7;

template<class T>
struct segmentree {
private:
	vector<T> seg, original;
	int n;
	T action(const T& lhs, const T& rhs) {
		return lhs + rhs; //CHECK
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = original[l];
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	T queryUtil(int i, int cl, int cr, int l, int r) {
		if (l > r)return 0; //CHECK
		else if (l == cl && r == cr)return seg[i];
		else {
			int mid = (cl + cr) / 2;
			T a = queryUtil(2 * i, cl, mid, l, min(mid, r)),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r);
			return action(a, b);
		}
	}
	T query2Util(int i, int cl, int cr, int l, int r, T lbnd) {
		return 0;
	}
	void updateUtil(int i, int l, int r, int pos, T val) {
		if (l == r)seg[i] = val;
		else {
			int mid = (l + r) / 2;
			if (pos <= mid)updateUtil(2 * i, l, mid, pos, val);
			else updateUtil(2 * i + 1, mid + 1, r, pos, val);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
public:
	segmentree(int size) {
		n = size;
		seg.resize(4 * n);
		fill(seg.begin(), seg.end(), 0);
	}
	segmentree(vector<T> orig) {
		original = orig;
		n = orig.size();
		seg.resize(4 * n);
		build(1, 0, n - 1);
	}
	T query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r);
	}
	T queryUntil(int l, int r, T lbnd) {
		return query2Util(1, 0, n - 1, l, r, lbnd);
	}
	void update(int i, T val) {
		updateUtil(1, 0, n - 1, i, val);
	}
};

template<class T>
struct segmod {
private:
	vector<T> seg, original;
	int n;
	T action(const T& lhs, const T& rhs) {
		return (lhs + rhs) % mod; //CHECK
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = original[l];
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	T queryUtil(int i, int cl, int cr, int l, int r) {
		if (l > r)return 0; //CHECK
		else if (l == cl && r == cr)return seg[i];
		else {
			int mid = (cl + cr) / 2;
			T a = queryUtil(2 * i, cl, mid, l, min(mid, r)),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r);
			return action(a, b);
		}
	}
	void updateUtil(int i, int l, int r, int pos, T val) {
		if (l == r)seg[i] = val;
		else {
			int mid = (l + r) / 2;
			if (pos <= mid)updateUtil(2 * i, l, mid, pos, val);
			else updateUtil(2 * i + 1, mid + 1, r, pos, val);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
public:
	segmod(int size) {
		n = size;
		seg.resize(4 * n);
		fill(seg.begin(), seg.end(), 0);
	}
	segmod(vector<T> orig) {
		original = orig;
		n = orig.size();
		seg.resize(4 * n);
		build(1, 0, n - 1);
	}
	T query(int l, int r) {
		return queryUtil(1, 0, n - 1, l, r);
	}
	void update(int i, T val) {
		updateUtil(1, 0, n - 1, i, val);
	}
};


int n, q;

segmentree<ll>* sw;
segmod<ll>* swmod, * saw, * sinc;
vector<ll> a, w;

void upd(int idx, int val) {
	sw->update(idx, val);
	swmod->update(idx, val);
	saw->update(idx, (a[idx] * val) % mod);
	sinc->update(idx, ((ll)idx * val) % mod);
}

ll calcSum(int l, int r, ll myl) {
	if (l > r)return 0;
	ll sumrange = swmod->query(l, r);
	ll tot = (myl * sumrange) % mod;
	tot = (tot - saw->query(l, r)) % mod;
	if (tot < 0)tot += mod;
	ll incsum = sinc->query(l, r);
	tot = (tot + incsum - sumrange * l) % mod;
	if (tot < 0)tot += mod;
	return tot;
}

int calcUntil(int x, int y, ll lbnd) {
	int l = x, r = y, bst = -1, mid;
	while (l <= r) {
		mid = (l + r + 1) / 2;
		if (sw->query(x, mid) >= lbnd) {
			bst = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return bst;
}

int main() {
	fast;
	cin >> n >> q;
	a.resize(n);
	w.resize(n);
	foru(i, 0, n) cin >> a[i];
	foru(i, 0, n)cin >> w[i];
	sw = new segmentree<ll>(w);
	swmod = new segmod<ll>(w);
	vector<ll> aw(n);
	foru(i, 0, n)aw[i] = (a[i] * w[i]) % mod;
	saw = new segmod<ll>(aw);
	foru(i, 0, n)aw[i] = (w[i] * i) % mod;
	sinc = new segmod<ll>(aw);
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (x > 0) {
			x--; y--;
			ll sum = sw->query(x, y);
			int idx = calcUntil(x, y, (sum + 1) / 2) , offset = idx - x;
			ll myl = (a[idx] - (idx - x));
			ll curans = calcSum(x, idx, myl);
			ll minusrest = calcSum(idx + 1, y, myl);
			minusrest = (minusrest + swmod->query(idx + 1, y) * (offset + 1)) % mod;
			curans = (curans - minusrest + mod) % mod;
			cout << curans << '\n';
		}
		else {
			x = -x;
			x--;
			upd(x, y);
		}
	}
	return 0;
}