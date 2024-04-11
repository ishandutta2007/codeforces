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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 1010, A = 179, K = 600;
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
int f[K][maxN];
vector<int>g[maxN];
int pr[maxN];
int deep[maxN];
void dfs(int v, int p = -1) {
	pr[v] = p;
	for (auto x : g[v]) {
		if (x == p)continue;
		deep[x] = deep[v] + 1;
		dfs(x, v);
		for (int k = 0; k < K; ++k)
			f[k][v] += max(1, f[k][x] - k);
	}
}
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	vector<pair<int, int>>vi(n);
	vector<int>dp(n);
	for (int i = 0; i < n; ++i) {
		vi[i].second = i;
		vi[i].first = g[i].size();
		if (i)--vi[i].first;
		dp[vi[i].second] = vi[i].first;
	}
	sort(vi.begin(), vi.end());
	int q;
	cin >> q;
	vector<int>used(n);

	while (q--) {
		int v, k;
		cin >> v >> k;
		--v;
		if (k < K) {
			cout << f[k][v] << "\n";
			continue;
		}
		int t = lower_bound(vi.begin(), vi.end(), make_pair(k + 1, -1))
			- vi.begin();
		vector<int>touch;
		priority_queue<pair<int, int>>q;
		for (int i = t; i < n; ++i) {
			q.push({ deep[vi[i].second],vi[i].second });
			used[vi[i].second] = 1;
			touch.push_back(vi[i].second);
		}
		while (!q.empty()) {
			int v = q.top().second;
			q.pop();
			if (pr[v] != -1) {
				--dp[pr[v]];
				dp[pr[v]] += dp[v] - k;
				touch.push_back(pr[v]);
				if (!used[pr[v]] && dp[pr[v]] > k) {
					used[pr[v]] = 1;
					q.push({ deep[pr[v]],pr[v] });
				}
			}
		}
		cout << dp[v] << "\n";
		for (auto x : touch) {
			used[x] = 0;
			if (x == 0)dp[x] = g[x].size();
			else dp[x] = g[x].size() - 1;
		}
	}

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