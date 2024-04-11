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
const ld eps = 1e-13, pi = acos(-1);
const ll maxN = 100010, maxT = 50, A = 179, K = 420;
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
	cout << "No solution\n";
	exit(0);
}
vector<vector<int>>g, gg;
vector<int>used, f, cnt;
int find(int v) { return (f[v] == v ? v : f[v] = find(f[v])); }
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	f[a] = b;
	cnt[b] += cnt[a];
}
vector<ll>c;
void dfs(int v, int clr = 1) {
	c[clr - 1] += cnt[v];
	used[v] = clr;
	for (auto x : gg[v]) {
		if (used[x]) {
			if (used[x] == used[v])c[0] += -INF, c[1] += -INF;
			continue;
		}
		dfs(x, ((clr - 1) ^ 1) + 1);
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	g.assign(n, vector<int>());
	cnt.assign(n, 1);
	f.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		f[i] = i;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		string s;
		cin >> s;
		if (s[0] == 'i') {
			g[a].push_back(b);
			g[b].push_back(a);
		}
		else {
			uni(a, b);
		}
	}
	gg.assign(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (auto x : g[i]) {
			x = find(x);
			int t = find(i);
			if (x == t) {
				cout << "-1\n";
				return;
				continue;
			}
			gg[t].push_back(x);
		}
	}
	used.assign(n, 0);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (f[i] != i || used[i])
			continue;
		c.assign(2, 0);
		dfs(i);
		ans += max(c[0], c[1]);
	}
	if (ans < 0)cout << "-1\n";
	else cout << ans << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("pluk.in", "r", stdin); freopen("pluk.out", "w", stdout);
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