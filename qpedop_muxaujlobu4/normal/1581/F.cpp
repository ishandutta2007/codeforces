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
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-13, pi = acos(-1);
const ll maxN = 4010, maxT = 4096, A = 179, K = 420;
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
ll dp[maxN][maxN], sz[maxN], a[maxN], val[maxN];
int cd = 0;
int n, m;
void mrg(int v, int to) {
	for (int cnt = sz[v] + sz[to]; cnt > 0; --cnt) {
		for (int l = min((int)sz[v], cnt); l >= 0 && l + sz[to] >= cnt; --l) {
			int r = cnt - l;
			dp[v][cnt] = max(dp[v][cnt], dp[v][l] + dp[to][r] - 2LL * l * r * val[v]);
		}
	}
	sz[v] += sz[to];
}
int rec(int l, int r) {
	int v = cd++;
	++sz[v];
	int id = l;
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] < a[id]) {
			id = i;
		}
	}
	val[v] = a[id];
	dp[v][1] = a[id] * (m - 1);
	if (id != l) {
		int to = rec(l, id - 1);
		mrg(v, to);
	}
	if (id != r) {
		int to = rec(id + 1, r);
		mrg(v, to);
	}
	return v;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	rec(0, n - 1);
	cout << dp[0][m] << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("snow.in", "r", stdin); freopen("snow.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
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