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
const ll maxN = 1000010, maxT = 3010, A = 179, K = 420;
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
struct block {
	int len, st;
	block() {
		len = 0, st = 0;
	}
	block(int vl) {
		len = 1;
		st = vl;
	}
	block(const block& a, const block& b) {
		if (max(a.len, b.len) == 0) {
			len = st = 0;
			return;
		}
		if (a.len == 0) {
			len = b.len;
			st = b.st;
			return;
		}
		if (b.len == 0) {
			len = a.len;
			st = a.st;
			return;
		}
		int ena = a.st ^ ((a.len % 2) ^ 1);
		if (ena == b.st) {
			if (a.len >= b.len) {
				len = a.len - b.len;
				st = a.st;
				return;
			}
			len = b.len - a.len;
			st = b.st ^ (a.len % 2);
		}
		else {
			len = a.len + b.len;
			st = a.st;
		}
	}
};
vector<block>t;
int sz = 1;
block get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr)return t[v];
	block res = block();
	int m = (tr + tl) / 2;
	if (ql <= m)res = block(res, get(ql, qr, tl, m, 2 * v));
	if (qr > m)res = block(res, get(ql, qr, m + 1, tr, 2 * v + 1));
	return res;
}
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	sz = 1;
	while (sz < n)sz <<= 1;
	t.assign(2 * sz, block(0));
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(' || s[i] == ')')t[i + sz] = block(1);
		else t[i + sz] = block(0);
	}
	for (int i = sz - 1; i > 0; --i) {
		t[i] = block(t[2 * i], t[2 * i + 1]);
	}
	int q;
	cin >> q;
	while (q--) {
		int  l, r;
		cin >> l >> r;
		cout << get(--l, --r).len / 2 << "\n";
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
	//freopen("input.in", "r", stdin); freopen("input.out", "w", stdout);
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