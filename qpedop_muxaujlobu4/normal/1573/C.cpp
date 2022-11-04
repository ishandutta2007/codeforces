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
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 1 << 21, maxT = 4096, A = 179, K = 170;
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
int ans;
vector<vector<int>>g;
vector<int>ts, used;
void dfs(int v) {
	used[v] = 1;
	for (auto x : g[v]) {
		if (used[x]) {
			if (used[x] == 1)ans = 0;
			continue;
		}
		dfs(x);
	}
	ts.push_back(v);
	used[v] = 2;
}
void solve() {
	int n;
	cin >> n;
	ts.clear();
	used.assign(n, 0);
	ans = 1;
	g.assign(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int v;
			cin >> v;
			g[--v].push_back(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (used[i])
			continue;
		dfs(i);
	}
	if (!ans) {
		cout << "-1\n";
		return;
	}
	reverse(ts.begin(), ts.end());
	vector<int>dp(n, 1);
	int mx = 1;
	for (auto x : ts) {
		mx = max(mx, dp[x]);
		for (auto to : g[x]) {
			if (to < x)dp[to] = max(dp[to], dp[x] + 1);
			else dp[to] = max(dp[to], dp[x]);
		}
	}

	cout << mx << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("kitten.in", "r", stdin); freopen("kitten.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
11
6 8 7 9 11 13 15 17 19 18 20
*/