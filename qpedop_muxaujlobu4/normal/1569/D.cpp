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
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 600100, A = 179, K = 170;
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
	cout << "-1\n";
	exit(0);
}
ll f[maxN], g[maxN];
void build() {
	f[0] = g[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
	}
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
	ll ans = 0;
	int n, m, k;
	cin >> n >> m >> k;
	set<int>X, Y;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		X.insert(v);
	}
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		Y.insert(v);
	}
	X.insert(INF);
	Y.insert(INF);
	map<int, vector<int>>mX, mY;
	for (int i = 0; i < k; ++i) {
		int f, s;
		cin >> f >> s;
		if (X.count(f) && Y.count(s))
			continue;
		if (X.count(f)) {
			int v = *Y.lower_bound(s);
			mY[v].push_back(f);
		}
		else {
			int v = *X.lower_bound(f);
			mX[v].push_back(s);
		}
	}
	for (auto pi : mX) {
		vector<int>& v = pi.second;
		sort(v.begin(), v.end());
		int y = 0;
		int sz = v.size();
		for (int i = 0; i < sz; ++i) {
			while (y < sz && v[y] == v[i])++y;
			ans += sz - y;
		}
	}
	for (auto pi : mY) {
		vector<int>& v = pi.second;
		sort(v.begin(), v.end());
		int y = 0;
		int sz = v.size();
		for (int i = 0; i < sz; ++i) {
			while (y < sz && v[y] == v[i])++y;
			ans += sz - y;
		}
	}
	cout << ans << "\n";
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
	build();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
2 2
1 1
1 1 2 1
2 1 2
*/