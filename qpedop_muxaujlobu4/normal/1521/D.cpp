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
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 1 << 10, maxT = 2001, A = 179, mid = 150;
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
	cout << "No solution\n";
	exit(0);
}
vector<vector<int>>g;
vector<vector<int>>dp;
vector<pair<int, int>>a1, a2;
set<pair<int, int>>s;
bool cmp(const int& a, const int& b) {
	return dp[1][a] - dp[0][a] > dp[1][b] - dp[0][b];
}
void dfs(int v, int p = -1) {
	if (p != -1) {
		g[v].erase(find(g[v].begin(), g[v].end(), p));
	}
	for (auto x : g[v]) {
		dfs(x, v);
	}
	sort(g[v].begin(), g[v].end(), cmp);
	if (g[v].empty()) {
		return;
	}
	if (g[v].size() == 1) {
		dp[1][v] = dp[0][v] = max(dp[0][g[v][0]], dp[1][g[v][0]] + 1);
		return;
	}
	for (int i = 2; i < g[v].size(); ++i) {
		dp[1][v] += dp[0][g[v][i]];
		dp[0][v] += dp[0][g[v][i]];
	}
	dp[1][v] += dp[0][g[v][1]];
	dp[0][v] += max(dp[0][g[v][1]], 1 + dp[1][g[v][1]]);
	dp[1][v] += max(dp[0][g[v][0]], 1 + dp[1][g[v][0]]);
	dp[0][v] += max(dp[0][g[v][0]], 1 + dp[1][g[v][0]]);
}
void dfs1(int v, int ss, int p = -1) {
	if (ss == 1)s.insert({ v,p });
	else {
		if (p != -1)a1.push_back({ v,p });
	}
	for (int i = 0; i < g[v].size(); ++i) {
		int x = g[v][i];
		if (i == 0) {
			if (dp[1][x] + 1 > dp[0][x])dfs1(x, 1, v);
			else dfs1(x, 0, v);
			continue;
		}
		if (i == 1 && dp[1][x] + 1 > dp[0][x] && ss == 0) {
			dfs1(x, 1, v);
		}
		else dfs1(x, 0, v);
	}
}
vector<int>used;
void solve() {
	int n;
	cin >> n;
	a1.clear();
	a2.clear();
	s.clear();
	g.assign(n, vector<int>());
	dp.assign(2, vector<int>(n));
	vector<pair<int, int>>ed;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
		ed.push_back({ a,b });
	}
	dfs(0);
	cout << n - 1 - dp[0][0] << "\n";

	dfs1(0, 0);
	g.assign(n, vector<int>());
	used.assign(n, 0);
	int lst = -1;
	for (auto pi : ed) {
		if (s.count(pi) || s.count({ pi.second,pi.first })) {
			g[pi.first].push_back(pi.second);
			g[pi.second].push_back(pi.first);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (used[i] == 1 || g[i].size() == 2)
			continue;
		if (lst != -1)
			a2.push_back({ i,lst });
		if (g[i].empty()) {
			lst = i;
			used[i] = 1;
			continue;
		}
		int v = g[i][0];
		used[i] = 1;
		while (g[v].size() != 1) {
			used[v] = 1;
			int to;
			for (auto x : g[v])
				if (!used[x])to = x;
			v = to;
		}
		used[v] = 1;
		lst = v;
	}
	for (int i = 0; i < n - 1 - dp[0][0]; ++i) {
		cout << ++a1[i].first << " " << ++a1[i].second 
			<< " " << ++a2[i].first << " " << ++a2[i].second << "\n";
	}
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