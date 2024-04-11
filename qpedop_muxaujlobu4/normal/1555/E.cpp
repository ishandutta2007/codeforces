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
int t[maxN << 1], p[maxN << 1];
int sz = 1 << 20;
void push(int v) {
	t[v] += p[v];
	if (v < sz) {
		p[2 * v] += p[v];
		p[2 * v + 1] += p[v];
	}
	p[v] = 0;
}
void add(int ql, int qr, int vl, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		p[v] += vl;
		push(v);
		return;
	}
	push(v);
	int m = (tr + tl) / 2;
	if (ql <= m)
		add(ql, qr, vl, tl, m, 2 * v);
	else push(2 * v);
	if (qr > m)
		add(ql, qr, vl, m + 1, tr, 2 * v + 1);
	else push(2 * v + 1);
	t[v] = min(t[2 * v], t[2 * v + 1]);
}
vector<pair<int, int>>cst[1 << 20];
void solve() {
	int n, m;
	cin >> n >> m;
	--m;//?
	for (int i = 0; i < n; ++i) {
		int l, r, w;
		cin >> l >> r >> w;
		--l, --r, --w;
		--r;//?
		if (r + 1 == m)r = sz - 1;
		cst[w].push_back({ l,r });
	}
	int ans = 1e6 + 10;
	int y = 0;
	for (int i = 0; i < maxN; ++i) {
		while (y < maxN && t[1] == 0) {
			for (auto x : cst[y])
				add(x.first, x.second, 1);
			++y;
		}
		if (t[1])
			ans = min(ans, y - 1 - i);
		for (auto x : cst[i])
			add(x.first, x.second, -1);
	}
	cout << ans << "\n";
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