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
struct edge {
	int fr, to;
	ll f, c, cost;
	edge(int FR = 0, int TO = 0, ll F = 0, ll C = 0, ll COST = 0) {
		fr = FR;
		to = TO;
		f = F;
		c = C;
		cost = COST;
	}
};
ll CS[maxN];
int pr[maxN];
set<int>vert;
struct MinCostMaxFlow {
	int sz, s, t;
	static const ll INF = 1e18;
	vector<edge>Ed;
	ll COST;
	MinCostMaxFlow(int SZ = 1) {
		sz = SZ;
		s = 0, t = sz - 1;
		COST = 0;
	}
	void add(int fr, int to, int c, int cost) {
		Ed.push_back(edge(fr, to, 0, c, cost));
		Ed.push_back(edge(to, fr, 0, 0, -cost));
	}
	bool ford() {
		for (auto x : vert) {
			CS[x] = INF;
			pr[x] = -1;
		}
		CS[s] = 0;
		bool cs = true;
		while (cs) {
			cs = false;
			int num = -1;
			for (auto x : Ed) {
				++num;
				if (CS[x.fr] == INF || x.f == x.c)continue;
				if (CS[x.fr] + x.cost < CS[x.to]) {
					cs = true;
					CS[x.to] = CS[x.fr] + x.cost;
					pr[x.to] = num;
				}
			}
		}
		ll flow = 1;
		int v = t;
		if (CS[t] == INF)return false;
		COST += CS[t] * flow;
		while (v != s) {
			int e = pr[v];
			Ed[e].f += flow;
			Ed[e ^ 1].f -= flow;
			v = Ed[e].fr;
		}
		return true;
	}
	ll run(int k) {
		for (int i = 0; i < k; ++i)
			if (!ford()) break;
		return -COST;
	}
};
vector<pair<int, int>>g[maxN];
void solve() {
	int n, k;
	cin >> n >> k;
	k = min(k, 1 << (n - 1));
	MinCostMaxFlow f = MinCostMaxFlow((1 << n) + 2);
	vector<int>a(1 << n);
	for (auto& x : a)
		cin >> x;

	for (int i = 0; i < (1 << n); ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0)++cnt;
		}
		if (cnt % 2)
			continue;
		for (int j = 0; j < n; ++j) {
			ll c = a[i] + a[i ^ (1 << j)];
			g[c].push_back({ i,i ^ (1 << j) });
		}
	}
	int sz = (2 * n - 1) * (k - 1) + 1;
	for (int i = maxN - 1; i >= 0; --i) {
		for (int j = 0; j < g[i].size(); ++j)
		{
			if (sz) {
				--sz;
				vert.insert(g[i][j].first + 1);
				vert.insert(g[i][j].second + 1);
				f.add(g[i][j].first + 1, g[i][j].second + 1, 1, -i);
			}
		}
	}
	for (auto x : vert) {
		--x;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if ((x & (1 << i)) != 0)++cnt;
		}
		if (cnt % 2) {
			f.add(x + 1, f.t, 1, 0);
		}
		else f.add(f.s, x + 1, 1, 0);
	}
	vert.insert(f.t);
	vert.insert(f.s);
	cout << f.run(k) << "\n";
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