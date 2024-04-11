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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 1 << 20, maxT = 300010, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1\n";
	exit(0);
}
const int k = 500;
ll t1[maxN];
int sz = 1 << 19;
void add1(int ql, int qr, ll val, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		t1[v] += val;
		return;
	}
	int m = (tr + tl) / 2;
	if (ql <= m)
		add1(ql, qr, val, tl, m, 2 * v);
	if (qr > m)
		add1(ql, qr, val, m + 1, tr, 2 * v + 1);
}
ll get1(int v) {
	v |= sz;
	ll r = 0;
	while (v) {
		r += t1[v];
		v >>= 1;
	}
	return r;
}
ll t2[maxN];
ll get2(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr)
		return t2[v];
	int m = (tr + tl) / 2;
	ll r = 0;
	if (ql <= m)
		r += get2(ql, qr, tl, m, 2 * v);
	if (qr > m)
		r += get2(ql, qr, m + 1, tr, 2 * v + 1);
	return r;
}
void add2(int v, ll vl) {
	v |= sz;
	while (v) {
		t2[v] += vl;
		v >>= 1;
	}
}
ll sum_all_values = 0, ans = 0, cnt_big_mod = 0;
ll cnt_small_mod[k];
ll cnt_chi[k][k];
void add_value(ll v) {
	for (int i = 1; i < k; ++i) {
		ans += v % i * cnt_small_mod[i];
		++cnt_chi[i][v % i];
	}
	ans += cnt_big_mod * v + get1(v);
	sum_all_values += v;
	add2(v, 1);
}
void add_modulo(ll v) {
	if (v < k) {
		++cnt_small_mod[v];
		for (int i = 0; i < v; ++i) {
			ans += cnt_chi[v][i] * i;
		}
		return;
	}
	ans += sum_all_values;
	++cnt_big_mod;
	for (int i = v; i < maxT; i += v) {
		ans -= (ll)i  * get2(i, min(sz - 1, i + (int)v - 1));
		add1(i, min(sz - 1, i + (int)v - 1), -i);
	}
}
void solve() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (auto& x : a)
		cin >> x;
	for (int i = 0; i < n; ++i) {
		add_value(a[i]);
		add_modulo(a[i]);
		cout << ans << ' ';
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}