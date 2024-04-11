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
const int mod = 31607;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 100100, maxT = 4010, A = 179, mid = 150;
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
int t[maxN << 2];
int sz;
void sett(int v, int add) {
	v |= sz;
	while (v) {
		t[v] += add;
		v >>= 1;
	}
}
int get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		return t[v];
	}
	int m = (tr + tl) / 2, r = 0;
	if (ql <= m) {
		r += get(ql, qr, tl, m, 2 * v);
	}
	if (qr > m) {
		r += get(ql, qr, m + 1, tr, 2 * v + 1);
	}
	return r;
}
void solve() {
	int n;
	cin >> n;
	map<int, vector<int>>mp;
	bool f = 1;
	sz = 1;
	while (sz < n)sz <<= 1;
	fill(t, t + 2 * sz, 0);
	for (int i = 0; i < n; ++i) {
		sett(i, 1);
		int v;
		cin >> v;
		mp[v].push_back(i);
	}
	for (const auto &vec : mp) {
		ll cnt = 0;
		vector<int>rofl;
		for (auto i : vec.second) {
			sett(i, -1);
			ll tmp = 0;
			tmp += get(0, i);
			tmp += n - 1 - i - get(i, n - 1);
			rofl.push_back(tmp % 2);
			cnt += tmp;
		}
		f &= cnt % 2 == 0;
		vector<int>c(2);
		for (int i = 0; i < rofl.size(); ++i) {
			c[i % 2] += rofl[i];
		}
		f &= c[1] == c[0];
	}
	if (f)cout << "YES\n";
	else cout << "NO\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}