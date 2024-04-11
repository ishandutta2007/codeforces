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
const ld eps = 1e-9, pi = acosl(-1);
const ll maxN = 200010, maxT = 519, A = 179, mid = 350, K = 500;
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
void add_to_bs(vector<int>& b, int d) {
	int y = 30;
	int sz = b.size();
	for (int i = sz - 1; i >= 0; --i) {
		while ((b[i] & (1 << y)) == 0)--y;
		if ((d & (1 << y)) != 0)
			d ^= b[i];
	}
	if (d == 0)
		return;
	b.push_back(d);
	y = sz;
	++sz;
	while (y && b[y - 1] > b[y]) {
		swap(b[y], b[y - 1]);
		--y;
	}
	int yy = 30;
	for (int i = y - 1; i >= 0; --i) {
		while ((b[i] & (1 << yy)) == 0)
			--yy;
		if ((b[y] & (1 << yy)) != 0) {
			b[y] ^= b[i];
		}
	}

	yy = 30;
	while ((b[y] & (1 << yy)) == 0)
		--yy;
	for (int i = sz - 1; i > y; --i) {
		if ((b[i] & (1 << yy)) != 0) {
			b[i] ^= b[y];
		}
	}
}
void rbld_bs(vector<int>& b, int add) {
	// 0
	for (auto& x : b)x ^= add;
	if (b.empty())return;
	int sz = b.size();
	int yi = 30;
	for (int i = sz - 1; i >= 0; --i) {
		sort(b.begin(), b.end());
		while ((b[i] & (1 << yi)) == 0 && yi > 0) {
			--yi;
		}
		for (int j = 0; j < sz; ++j) {
			if (i == j)
				continue;
			if ((b[j] & (1 << yi)) != 0) {
				b[j] ^= b[i];
			}
		}
	}
	if (!b.empty() && b[0] == 0)b.erase(b.begin());
}
vector<int>t[maxN << 2];
int t1[maxN << 2];
int sz = 1;
void mrg(vector<int>&l, vector<int>r) {
	for (auto x : r)
		add_to_bs(l, x);
}
void add(int v, int vl) {
	if (vl == 0)
		return;
	v += sz;
	if (t[v].empty())t[v] = { vl };
	else {
		t[v][0] ^= vl;
		if (t[v][0] == 0)t[v].clear();
	}
	for (v = v / 2; v; v >>= 1) {
		t[v] = t[2 * v];
		mrg(t[v], t[2 * v + 1]);
	}
}
vector<int>get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		return t[v];
	}
	vector<int> r;
	int m = (tr + tl) / 2;
	if (ql <= m) {
		mrg(r, get(ql, qr, tl, m, 2 * v));
	}
	if (qr > m) {
		mrg(r, get(ql, qr, m + 1, tr, 2 * v + 1));
	}
	return r;
}
void add1(int ql, int qr, int vl, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		t1[v] ^= vl;
		return;
	}
	int m = (tr + tl) / 2;
	if (ql <= m) {
		add1(ql, qr, vl, tl, m, 2 * v);
	}
	if (qr > m)
		add1(ql, qr, vl, m + 1, tr, 2 * v + 1);
}
int get1(int p) {
	int v = 0;
	p += sz;
	while (p) {
		v ^= t1[p];
		p >>= 1;
	}
	return v;
}
void solve() {
	int n, q;
	cin >> n >> q;
	while (sz < n)sz <<= 1;
	vector<int>a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		add1(i, i, a[i]);
	}
	for (int i = 0; i + 1 < n; ++i) {
		add(i, a[i] ^ a[i + 1]);
	}
	while (q--) {
		int t;
		cin >> t;
		int l, r;
		cin >> l >> r;
		--l, --r;
		if (t == 1) {
			int k;
			cin >> k;
			//add(l, k);
			if (l)add(l - 1, k);
			add(r, k);
			if (r != l) {
				//add(r - 1, k);
			}
			add1(l, r, k);
		}
		else {
			vector<int>bb;
			if (r > l)
				bb = get(l, r - 1);
			add_to_bs(bb, get1(l));
			int sz = bb.size();
			cout << (1 << sz) << "\n";
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
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
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