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
const ll maxN = 400010, maxT = 10000, A = 179, mid = 150;
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
vector<vector<int>>g;
vector<int>used;
vector<int>circl;
vector<int>cnt;
int rr;
vector<int>ts;
int ps[maxN];
void dfs(int v) {
	used[v] = 1;
	for (auto x : g[v]) {
		if (used[x] == 2) {
			continue;
		}
		if (used[x] == 1) {
			++rr;
			++cnt[x];
			continue;
		}
		dfs(x);
	}
	used[v] = 2;
	if (rr) {
		circl[v] = 1;
	}
	rr -= cnt[v];
}
void dfs_d(int v) {
	circl[v] = 1;
	for (auto x : g[v]) {
		if (!circl[x])
			dfs_d(x);
	}
}
vector<int>ans;
void dfs_t(int v) {
	used[v] = 1;
	for (auto x : g[v]) {
		if (!used[x] && ans[x] != -1) {
			dfs_t(x);
		}
	}
	ps[v] = ts.size();
	ts.push_back(v);
}
void solve() {
	int n, m;
	cin >> n >> m;
	g.assign(n, vector<int>());
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
	}
	circl.assign(n, 0);
	cnt.assign(n, 0);
	used.assign(n, 0);
	rr = 0;
	dfs(0);
	for (int i = 0; i < n; ++i) {
		if (circl[i] == 1) {
			dfs_d(i);
		}
	}
	ans.assign(n, 1);
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0)ans[i] = 0;
		if (circl[i]) {
			ans[i] = -1;
		}
	}
	if (ans[0] != -1) {
		ts.clear();
		used.assign(n, 0);
		dfs_t(0);
		reverse(ts.begin(), ts.end());
		for (int i = 0; i < ts.size(); ++i) {
			ps[ts[i]] = i;
		}
		vector<int>dp(ts.size());
		dp[0] = 1;
		for (int i = 0; i < dp.size(); ++i) {
			int v = ts[i];
			ans[v] = dp[i];
			for (auto x : g[v]) {
				if (used[x] != 1) {
					continue;
				}
				dp[ps[x]] = min(dp[ps[x]] + dp[i], 2);
			}
		}
	}
	for (auto x : ans)
		cout << x << " ";
	cout << "\n";
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