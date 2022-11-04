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
const ll INF = 1e18 + 100;
int mod = 1000000007;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200010, maxT = 10000, A = 179, mid = 150;
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
	cout << "NO\n";
	exit(0);
}
int t[maxN << 3];
int sz = 1;
void upd(int& g, int v) {
	if (g == -1)g = v;
	else g = gcd(g, v);
}
int get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		return t[v];
	}
	int m = (tr + tl) / 2;
	int g = -1;
	if (ql <= m) {
		upd(g, get(ql, qr, tl, m, 2 * v));
	}
	if (qr > m) {
		upd(g, get(ql, qr, m + 1, tr, 2 * v + 1));
	}
	return g;
}
void solve() {
	int n;
	cin >> n;
	sz = 1;
	while (sz < 2 * n)sz <<= 1;
	fill(t, t + 2 * sz, 1);
	int g = -1;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		t[sz + i] = t[sz + i + n] = v;
		if (g == -1)g = v;
		else g = gcd(v, g);
	}
	for (int i = sz - 1; i > 0; --i) {
		t[i] = gcd(t[2 * i], t[2 * i + 1]);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int l = -1, r = n;
		while (l + 1 != r) {
			int m = (l + r) / 2;
			if (get(i, i + m) == g)r = m;
			else l = m;
		}
		ans = max(ans, r);
	}
	cout << ans << "\n";
}
int main()
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}