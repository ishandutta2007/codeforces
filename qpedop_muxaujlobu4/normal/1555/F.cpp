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
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 1 << 20, maxT = 10010, A = 179, mid = 150;
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
int f[maxN];
int find(int v) {
	return (f[v] == v ? v : f[v] = find(f[v]));
}
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	f[a] = b;
	return true;
}

vector<vector<pair<int, int>>>g;
vector<int>pr;
int d[maxN], tin[maxN], tmr = 0, fi[maxN], deep[maxN];
int pp[20][maxN];
int lca(int a, int b) {
	if (deep[a] < deep[b])swap(a, b);
	int l = deep[a] - deep[b];
	for (int i = 0; i < 19; ++i) {
		if ((l & (1 << i)) != 0)a = pp[i][a];
	}
	if (a == b)
		return a;
	for (int i = 19; i >= 0; --i) {
		if (pp[i][a] != pp[i][b])
			a = pp[i][a], b = pp[i][b];
	}
	return pp[0][a];
}
void dfs(int v, int p = -1) {
	d[v] = 1;
	tin[v] = tmr++;
	pp[0][v] = max(p, 0);
	pr[v] = p;
	for (auto x : g[v]) {
		if (x.first == p)
			continue;
		fi[x.first] = fi[v] ^ x.second;
		deep[x.first] = deep[v] + 1;
		dfs(x.first, v);
		d[v] += d[x.first];
	}
}
int t[maxN << 1];
int sz = 1;
void add(int ql, int qr, int vl, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		t[v] += vl;
		return;
	}
	int m = (tr + tl) / 2;
	if (ql <= m) {
		add(ql, qr, vl, tl, m, 2 * v);
	}
	if (qr > m) {
		add(ql, qr, vl, m + 1, tr, 2 * v + 1);
	}
}
int get(int v) {
	int r = 0;
	for (v = v | sz; v; v >>= 1) {
		r += t[v];
	}
	return r;
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		f[i] = i;
	g.assign(n, vector<pair<int, int>>());
	vector<int>a(m), b(m), w(m);
	vector<int>in_t(m);
	for (int i = 0; i < m; ++i) {
		cin >> a[i] >> b[i] >> w[i];
		if (uni(--a[i], --b[i])) {
			g[a[i]].push_back({ b[i],w[i] });
			g[b[i]].push_back({ a[i],w[i] });
			in_t[i] = 1;
		}

	}
	pr.assign(n, -2);
	for (int i = 0; i < n; ++i) {
		if (pr[i] == -2)
			dfs(i);
	}
	while (sz < tmr)
		sz <<= 1;
	for (int i = 0; i < n; ++i)
		f[i] = i;
	for (int i = 1; i < 20; ++i) {
		for (int j = 0; j < n; ++j) {
			pp[i][j] = pp[i - 1][pp[i - 1][j]];
		}
	}
	for (int i = 0; i < m; ++i) {
		if (in_t[i]) {
			cout << "YES\n";
			continue;
		}
		int v = a[i], u = b[i];
		int lc = lca(u, v);
		if ((fi[v] ^ w[i] ^ 1) != fi[u]) {
			cout << "NO\n";
			continue;
		}
		if (get(tin[u]) + get(tin[v]) != 2 * get(tin[lc])) {
			cout << "NO\n";
			continue;
		}
		if (!uni(u, v)) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		while (u != lc) {
			add(tin[u], tin[u] + d[u] - 1, 1);
			uni(u, pr[u]);
			u = pr[u];
		}
		swap(u, v);
		while (u != lc) {
			add(tin[u], tin[u] + d[u] - 1, 1);
			uni(u, pr[u]);
			u = pr[u];
		}
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
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}