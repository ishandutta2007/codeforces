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
const int mod = 1000000007;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 1 << 20, maxT = 200000, A = 179, K = 450;
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
	cout << "impossible\n";
	exit(0);
}
int sz;
vector<ll>t;
void sett(ll vl, int v) {
	for (v += sz; v; v >>= 1)t[v] = min(t[v], vl);
}
ll get(int l, int r) {
	ll res = INF;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1) {
			res = min(res, t[l++]);
		}
		if (r % 2 == 0) {
			res = min(res, t[r--]);
		}
	}
	return res;
}
void solve() {
	int n;
	ll s;
	cin >> n >> s;
	sz = 1;
	while (sz <= n)sz <<= 1;
	t.assign(2 * sz, INF);
	ll sum = 0;
	sett(sum, 0);
	vector<ll>a(n + 1);
	for (int i = 1; i <= n; ++i) {
		ll vl;
		cin >> vl;
		sum += vl;
		sett(a[i] = sum, i);
	}
	int ans = 0;
	int l = -1, r = -1;
	for (int i = 0; i < n; ++i) {
		int b = i, e = n + 1;
		while (b + 1 != e) {
			int m = (b + e) / 2;
			ll tmp = get(i, m);
			if (tmp - a[i] + s >= 0)b = m;
			else e = m;
		}
		if (b - i > ans) {
			ans = b - i;
			l = i + 1, r = b;
		}
	}

	if (ans == 0)cout << "-1\n";
	else cout << l << " " << r << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
7 7
1 2
2 3
3 4
4 5
2 5
5 6
6 7
5
4 3 2 5 6 7
1
*/