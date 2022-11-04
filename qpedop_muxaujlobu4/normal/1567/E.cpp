#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e9 + 100;
const int mod = 1000000007;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 200048, maxT = 600100, A = 179, K = 170;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	et %= mod;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "NO\n";
	exit(0);
}
int t[2][maxN << 2], p[2][maxN << 2];
ll tr[maxN << 2];
int sz = 1;
void add(int v, ll vl) {
	for (v |= sz; v; v >>= 1) {
		tr[v] += vl;
	}
}
ll get(int l, int r) {
	ll res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1)res += tr[l++];
		if (r % 2 == 0)res += tr[r--];
	}
	return res;
}
void push(int is, int v) {
	if (p[is][v] == 0)
		return;
	t[is][v] = p[is][v];
	if (v < sz) {
		p[is][2 * v] = p[is][2 * v + 1] = p[is][v];
	}
	p[is][v] = 0;
}
void sett(int is, int ql, int qr, int vl, int tl = 0, int tr = sz - 1, int v = 1) {
	push(is, v);
	if (ql <= tl && tr <= qr) {
		p[is][v] = vl;
		push(is, v);
		return;
	}
	int m = (tl + tr) / 2;
	if (ql <= m) {
		sett(is, ql, qr, vl, tl, m, 2 * v);
	}
	else push(is, 2 * v);
	if (qr > m) {
		sett(is, ql, qr, vl, m + 1, tr, 2 * v + 1);
	}
	else push(is, 2 * v + 1);
}
int get(int is, int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	push(is, v);
	if (tl >= ql && qr >= tr) {
		return t[is][v];
	}
	int m = (tr + tl) / 2;
	if (ql <= m)
		return get(is, ql, qr, tl, m, 2 * v);
	return get(is, ql, qr, m + 1, tr, 2 * v + 1);
}
int n, q;
vector<int>a;
ll fun(ll len) {
	return len * (len + 1) / 2;
}
void uni(int i) {
	int r = get(0, i, i);
	int l = get(1, i - 1, i - 1);
	add(l, fun(r - l + 1));
	add(l, -fun(i - l));
	add(i, -fun(r - i + 1));
	sett(0, l, r, r);
	sett(1, l, r, l);
}
void cut(int i) {
	int r = get(0, i, i);
	int l = get(1, i, i);
	add(l, -fun(r - l + 1));
	add(l, fun(i - l));
	add(i, fun(r - i + 1));
	sett(0, l, i - 1, i - 1);
	sett(1, i, r, i);
}
ll compute(int l, int r) {
	int tmp = get(0, l, l);
	if (tmp >= r) {
		return fun(r - l + 1);
	}
	ll res = fun(tmp - l + 1);
	l = tmp + 1;
	tmp = get(1, r, r);
	if (tmp <= l) {
		return res + fun(r - l + 1);
	}
	res += fun(r - tmp + 1);
	r = tmp - 1;
	res += get(l, r);
	return res;
}
void solve() {
	cin >> n >> q;
	a.assign(n + 2, 0);
	while (sz < n + 2)
		sz <<= 1;
	a.back() = -1;
	a[0] = INF;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sett(0, i, i, i);
		sett(1, i, i, i);
		add(i, 1);
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= a[i - 1]) {
			uni(i);
		}
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			if (a[x] >= a[x - 1]) {
				cut(x);
			}
			if (a[x + 1] >= a[x]) {
				cut(x + 1);
			}
			a[x] = y;
			if (a[x] >= a[x - 1]) {
				uni(x);
			}
			if (a[x + 1] >= a[x]) {
				uni(x + 1);
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << compute(l, r) << "\n";
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}