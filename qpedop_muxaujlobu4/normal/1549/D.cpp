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
int mod = 1000000007;
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 200100, maxT = 10010, A = 179, mid = 150;
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
ll t[maxN << 2];
int sz;
void sett(int v, ll vl) {
	t[v | sz] = vl;
	for (v = (v | sz) / 2; v; v >>= 1) {
		t[v] = gcd(t[v * 2], t[v * 2 + 1]);
	}
}
ll get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		return t[v];
	}
	ll g = t[ql + sz];
	int m = (tr + tl) / 2;
	if (ql <= m)
		g = gcd(g, get(ql, qr, tl, m, 2 * v));
	if (qr > m)
		g = gcd(g, get(ql, qr, m + 1, tr, 2 * v + 1));
	return g;
}
void solve() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (auto& x : a)
		cin >> x;
	if (n == 1) {
		cout << "1\n";
		return;
	}
	sz = 1;
	while (sz < n)sz <<= 1;
	fill(t, t + 2 * sz, 1);
	for (int i = 0; i + 1 < n; ++i) {
		sett(i, abs(a[i] - a[i + 1]));
	}
	int y = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		while (y < n && (y < i || get(i, y)>1)) {
			++y;
		}
		ans = max(ans, y - i);
	}

	cout << ans + 1 << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
5
2 1 3 5 4
simple solve: 1 2 3 1 2
1 2 3 3 3
*/