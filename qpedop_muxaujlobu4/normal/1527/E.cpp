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
const int mod = 998244353;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200010, maxT = 61, A = 179, mid = 150;
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
ll tree[maxN << 2], to_push[maxN << 2];
int sz = 1;
void push(int v) {
	tree[v] += to_push[v];
	if (v < sz) {
		to_push[2 * v] += to_push[v];
		to_push[2 * v + 1] += to_push[v];
	}
	to_push[v] = 0;
}
void add(int ql, int qr, ll val, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		to_push[v] += val;
		push(v);
		return;
	}
	push(v);
	int m = (tr + tl) / 2;
	if (ql <= m)add(ql, qr, val, tl, m, 2 * v);
	if (qr > m)add(ql, qr, val, m + 1, tr, 2 * v + 1);
	push(2 * v);
	push(2 * v + 1);
	tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}
ll get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	push(v);
	if (ql <= tl && tr <= qr) {
		return tree[v];
	}
	ll res = INF;
	int m = (tr + tl) / 2;
	if (ql <= m) {
		res = min(res, get(ql, qr, tl, m, 2 * v));
	}
	if (qr > m) {
		res = min(res, get(ql, qr, m + 1, tr, 2 * v + 1));
	}
	return res;
}
void solve() {
	int n, k;
	cin >> n >> k;
	while (sz <= n)sz <<= 1;
	map<ll, int>mp;
	vector<ll>ref(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		int v;
		cin >> v;
		if (mp.count(v))ref[i] = mp[v];
		mp[v] = i;
	}
	vector<ll>dp(n + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < k; ++i) {
		fill(tree, tree + 2 * sz, 0);
		fill(to_push, to_push + 2 * sz, 0);
		for (int i = 0; i <= n; ++i) {
			add(i, i, dp[i]);
		}
		vector<ll>dp1(n + 1, INF);
		for (int i = 1; i <= n; ++i) {
			if (ref[i] != -1) {
				add(0, ref[i] - 1, i - ref[i]);
			}
			dp1[i] = get(0, i - 1);
		}
		dp = dp1;
	}
	cout << dp.back() << "\n";
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}