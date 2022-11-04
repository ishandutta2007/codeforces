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
const int mod = 998244353;
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 600100, A = 179, K = 170;
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
int sz = 1;
ll f[maxN * 2], g[maxN * 2];
int t[maxN * 4], p[maxN * 4];
void build() {
	while (sz < maxN)
		sz <<= 1;
	f[0] = g[0] = 1;
	for (int i = 1; i < maxN * 2; ++i) {
		f[i] = f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
	}
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void push(int v, int l, int r) {
	if (!p[v])
		return;
	if (p[v] == 1) {
		t[v] = (r - l + 1);
	}
	else {
		t[v] = 0;
	}
	if (v < sz)
		p[2 * v] = p[2 * v + 1] = p[v];
	p[v] = 0;
}
void sett(int ql, int qr, int vl, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		p[v] = vl;
		push(v, tl, tr);
		return;
	}
	push(v, tl, tr);
	int m = (tr + tl) / 2;
	if (ql <= m)
		sett(ql, qr, vl, tl, m, 2 * v);
	if (qr > m)
		sett(ql, qr, vl, m + 1, tr, 2 * v + 1);
	push(2 * v, tl, m);
	push(2 * v + 1, m + 1, tr);
	t[v] = t[2 * v] + t[2 * v + 1];
}
int get(int k, int tl = 0, int tr = sz - 1, int v = 1) {
	push(v, tl, tr);
	if (k == 1 && tl == tr && t[v] == 1) {
		return -(v - sz);
	}
	if (t[v] < k) {
		return t[v];
	}
	int m = (tr + tl) / 2;
	int tmp = get(k, tl, m, 2 * v);
	if (tmp < 0)return tmp;
	k -= tmp;
	return get(k, m + 1, tr, 2 * v + 1);
}
void solve() {
	int n, m;
	cin >> n >> m;
	sett(1, n, 1);
	vector<pair<int, int>>a(m);
	set<int>vls;
	for (auto& x : a) {
		cin >> x.first >> x.second;
	}
	reverse(a.begin(), a.end());
	for (auto x : a) {
		vls.insert(get(x.second + 1));
		int tmp = -get(x.second);
		sett(tmp, tmp, 2);
	}
	sett(1, n, 2);
	cout << c(2 * n - 1 - vls.size(), n) << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	build();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
2 2
1 1
1 1 2 1
2 1 2
*/