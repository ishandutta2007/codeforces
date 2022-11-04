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
const ll INF = 3e18 + 100;
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 1 << 20, maxT = 600100, A = 179, K = 170;
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
vector<vector<int>>g;
vector<int>used;
vector<set<int>>to(maxN);
int dfs(int v) {
	used[v] = 1;
	sort(g[v].begin(), g[v].end());
	g[v].resize(unique(g[v].begin(), g[v].end()) - g[v].begin());
	if (g[v].size() > 1)
		return -1;
	if (to[v].size() > 1)
		return -1;
	int l = 1;
	if (g[v].empty())
		return l;
	if (used[g[v][0]])
		return -1;
	int dd = dfs(g[v][0]);
	if (dd == -1)
		return - 1;
	return l + dd;
}
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	g.assign(k, vector<int>());
	vector<int>d(k), bd(k);
	vector<vector<int>>tmp(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		tmp[i].resize(c);
		set<int>vert;
		for (auto& x : tmp[i]) {
			cin >> x;
			++d[--x];
		}
		for (int j = 0; j + 1 < tmp[i].size(); ++j) {
			g[tmp[i][j]].push_back(tmp[i][j + 1]);
			to[tmp[i][j + 1]].insert(tmp[i][j]);
		}
	}
	used.assign(k, 0);
	vector<int>lns(k + 1);
	for (int i = 0; i < k; ++i) {
		if (d[i] == 0) {
			++lns[1];
			continue;
		}
		if (!to[i].empty() || used[i])
			continue;
		int tmp = dfs(i);
		if (tmp == -1)
			continue;
		++lns[tmp];
	}
	vector<ll>dp(m + 1, 0);
	dp[0] = 1;
	set<int>s;
	for (int i = 0; i <= k; ++i) {
		if (lns[i] != 0)s.insert(i);
	}
	for (int i = 0; i < m; ++i) {
		for (auto x : s) {
			if (i + x > m)
				break;
			dp[i + x] = (dp[i + x] + dp[i] * lns[x]) % mod;
		}
	}
	cout << dp.back() << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("exam.in", "r", stdin); freopen("exam.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
11
6 8 7 9 11 13 15 17 19 18 20
*/