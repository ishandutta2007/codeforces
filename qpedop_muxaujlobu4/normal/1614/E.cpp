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
const ll INF = 1000000000;
const int mod = 1000000007;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 20000010, maxT = 200000, A = 179, K = 450;
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
int mx[maxN], mn[maxN], add[maxN], rl[maxN], rr[maxN];
int sz = 1;
void push(int v) {
	mx[v] += add[v];
	mn[v] += add[v];
	if (rr[v]) {
		add[rr[v]] += add[v];
		add[rl[v]] += add[v];
	}
	add[v] = 0;
}
void new_vert(int v) {
	if (rr[v])return;
	rl[v] = sz++;
	rr[v] = sz++;
	int l = mn[v], r = mx[v];
	int mid = (l + r) / 2;
	mn[rl[v]] = l;
	mx[rl[v]] = mid;
	mn[rr[v]] = mid + 1;
	mx[rr[v]] = r;
}
int get(int st, int tl = 0, int tr = INF, int v = 0) {
	push(v);
	if (tl != tr) {
		new_vert(v);
	}
	if (tl == tr) {
		return mn[v];
	}
	int mid = (tl + tr) / 2;
	if (st <= mid) {
		return get(st, tl, mid, rl[v]);
	}
	return get(st, mid + 1, tr, rr[v]);
}
void add_vl(int vl, int tl = 0, int tr = INF, int v = 0) {
	push(v);
	if (tl != tr) {
		new_vert(v);
	}
	if (mx[v] < vl) {
		add[v] += 1;
		push(v);
		return;
	}
	if (mn[v] > vl) {
		add[v] += -1;
		push(v);
		return;
	}
	if (mx[v] == mn[v] && mx[v] == vl)return;
	int mid = (tr + tl) / 2;
	add_vl(vl, tl, mid, rl[v]);
	add_vl(vl, mid + 1, tr, rr[v]);
	mn[v] = mn[rl[v]];
	mx[v] = mx[rr[v]];
}
void solve() {
	mx[0] = INF;
	mn[0] = 0;
	int q;
	cin >> q;
	int lst(0);
	while (q--) {
		int t;
		cin >> t;
		add_vl(t);
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j) {
			int v;
			cin >> v;
			lst = get((v + lst) % (INF + 1));
			cout << lst << '\n';
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
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
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