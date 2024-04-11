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
const ll INF = 1000000007;
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 100100, maxT = 510, A = 179, K = 450;
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
vector<vector<int>>g;
vector<vector<int>>vert;
void dfs(int v, int c=0, int p = -1) {
	vert[c].push_back(v);
	for (auto x : g[v]) {
		if (x == p)continue;
		dfs(x, c ^ 1, v);
	}
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
	vert.assign(2, vector<int>());
	dfs(0);
	if (vert[1].size() < vert[0].size())swap(vert[1], vert[0]);
	int sz = vert[0].size();
	vector<vector<int>>to(2);
	for (int i = 1; i <= n; ++i) {
		int mx = 0;
		for (int j = 0; j < 30; ++j)if ((i & (1 << j)) != 0)mx = j;
		if ((sz & (1 << mx)) != 0)to[0].push_back(i - 1);
		else to[1].push_back(i - 1);
	}
	vector<int>ans(n);
	for (int i = 0; i < to[0].size(); ++i)ans[vert[0][i]] = to[0][i];
	for (int i = 0; i < to[1].size(); ++i)ans[vert[1][i]] = to[1][i];
	for (auto x : ans)cout << x + 1 << ' '; cout << "\n";
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