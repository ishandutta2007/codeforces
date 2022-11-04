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
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 100010, maxT = 10010, A = 179, mid = 150;
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
vector<vector<int>>g;
vector<int>way;
ll d[maxN];
void dfs(int v, int to, int p = -1) {
	way.push_back(v);
	if (v == to)
		return;
	for (auto x : g[v]) {
		if (x == p)
			continue;
		dfs(x, to, v);
		if (way.back() == to)
			return;
	}
	way.pop_back();
}
void dfs_d(int v, int p = -1) {
	d[v] = 1;
	for (auto x : g[v]) {
		if (x == p)
			continue;
		dfs_d(x, v);
		d[v] += d[x];
	}
}
int pl(const int& a, const int& b) {
	int r = a + b;
	if (r >= mod)r -= mod;
	return r;
}
void solve() {
	int n;
	cin >> n;
	g.assign(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1));
	dp[0][0] = 1;
	ll p2 = (mod + 1) / 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i + 1][j] = pl(dp[i + 1][j], dp[i][j] * p2 % mod);
			dp[i][j + 1] = pl(dp[i][j + 1], dp[i][j] * p2 % mod);
		}
	}
	vector<vector<ll>>dp1(n + 1, vector<ll>(n + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 0; k < j; ++k) {
				dp1[i][j] = pl(dp1[i][j], dp[i - 1][k] * p2 % mod);
			}
		}
	}
	ll ans = 0;
	fill(dp1[0].begin(), dp1[0].end(), 1);
	for (int i = n - 1; i >= 0; --i) {
		dfs_d(i);
		for (int j = i - 1; j >= 0; --j) {
			way.clear();
			dfs(i, j);
			for (int k = 0; k + 1 < way.size(); ++k) {
				ans = pl(ans, (d[way[k]] - d[way[k + 1]])
					* dp1[k][way.size() - k - 1] % mod);
			}
		}
	}
	cout << ans * bp(n, mod - 2) % mod << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
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