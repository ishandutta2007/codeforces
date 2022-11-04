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
const ld eps = 1e-4, pi = acosl(-1);
const ll maxN = 1 << 18, maxT = 100100, A = 179, mid = 150;
ll bp(ll et, ll b) {
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
int sz;
int p[maxN << 2];
pair<int, int> tree[maxN << 2];
int yk = 0;
pair<int, int>qw[maxN];
void push(int v) {
	tree[v].first += p[v];
	if (v < sz) {
		p[2 * v] += p[v];
		p[2 * v + 1] += p[v];
	}
	p[v] = 0;
}
void mrg(int v) {
	tree[v].first = max(tree[2 * v].first, tree[2 * v + 1].first);
	tree[v].second = 0;
	if (tree[v].first == tree[2 * v].first)
		tree[v].second += tree[2 * v].second;
	if (tree[v].first == tree[2 * v + 1].first)
		tree[v].second += tree[2 * v + 1].second;
}
void add(int ql, int qr, int vl, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		p[v] += vl;
		push(v);
		return;
	}
	push(v);
	int m = (tr + tl) / 2;
	if (ql <= m)add(ql, qr, vl, tl, m, 2 * v);
	if (qr > m)add(ql, qr, vl, m + 1, tr, 2 * v + 1);
	push(2 * v);
	push(2 * v + 1);
	mrg(v);
}
void solve() {
	int k;
	cin >> k;
	sz = 1 << k;
	for (int i = 0; i < sz; ++i)tree[sz + i].second = 1;
	for (int i = sz - 1; i > 0; --i) {
		mrg(i);
	}
	string s;
	cin >> s;
	int add1 = 2;
	for (int j = k - 1; j >= 0; --j) {
		for (int st = 0; st < (1 << k); st += add1) {
			qw[yk++] = { st,st + add1 - 1 };
		}
		add1 <<= 1;
	}
	for (int i = 0; i < yk; ++i) {
		int l, r;
		tie(l, r) = qw[i];
		int m = (l + r) / 2;
		if (s[i] == '?')
			add(l, r, 1);
		if (s[i] == '0')
			add(l, m, 1);
		if (s[i] == '1')
			add(m + 1, r, 1);
	}
	int q;
	cin >> q;
	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		--i;
		int l, r;
		tie(l, r) = qw[i];
		int m = (l + r) / 2;
		if (s[i] == '?')
			add(l, r, -1);
		if (s[i] == '0')
			add(l, m, -1);
		if (s[i] == '1')
			add(m + 1, r, -1);
		s[i] = c;
		if (s[i] == '?')
			add(l, r, 1);
		if (s[i] == '0')
			add(l, m, 1);
		if (s[i] == '1')
			add(m + 1, r, 1);
		cout << tree[1].second << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}