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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 300100, maxT = 510, A = 179, K = 450;
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
int sz = -1;
ll p[2][maxN * 4];
pair<ll, ll>t[2][maxN * 4];
void push(int is, int v) {
	t[is][v].first += p[is][v];
	if (v < sz) {
		p[is][2 * v] += p[is][v];
		p[is][2 * v + 1] += p[is][v];
	}
	p[is][v] = 0;
}
void upd(int is, int v) {
	if (is == 0)t[is][v].first = min(t[is][2 * v].first, t[is][2 * v + 1].first);
	else t[is][v].first = max(t[is][2 * v].first, t[is][2 * v + 1].first);
	t[is][v].second = 0;
	if (t[is][2 * v].first == t[is][v].first)
		t[is][v].second += t[is][2 * v].second;
	if (t[is][2 * v + 1].first == t[is][v].first)
		t[is][v].second += t[is][2 * v + 1].second;
}
void add(int l, int r, ll val, int is, int tl = 0, int tr = sz - 1, int v = 1) {
	if (l <= tl && tr <= r) {
		p[is][v] += val;
		push(is, v);
		return;
	}
	push(is, v);
	int m = (tr + tl) / 2;
	if (l <= m)add(l, r, val, is, tl, m, 2 * v);
	else push(is, 2 * v);
	if (r > m)add(l, r, val, is, m + 1, tr, 2 * v + 1);
	else push(is, 2 * v + 1);
	upd(is, v);
}
void upd(pair<ll, ll>& r, pair<ll, ll>fr, bool mx) {
	if (mx) {
		if (r.first > fr.first)return;
		if (fr.first > r.first)r = { fr.first,0 };
		r.second += fr.second;
	}
	else {
		if (r.first < fr.first)return;
		if (fr.first < r.first)r = { fr.first,0 };
		r.second += fr.second;
	}
}
pair<ll, ll>get(int l, int r, int is, int tl = 0, int tr = sz - 1, int v = 1) {
	push(is, v);
	if (l <= tl && tr <= r) {
		return t[is][v];
	}
	int m = (tr + tl) / 2;
	pair<ll, ll>res = { 0,0 };
	if (l <= m) {
		upd(res, get(l, r, is, tl, m, 2 * v), is);
	}
	if (r > m) {
		upd(res, get(l, r, is, m + 1, tr, 2 * v + 1), is);
	}
	push(is, 2 * v);
	push(is, 2 * v + 1);
	upd(is, v);
	return res;
}
bool is_it_good(int r) {
	int r1, r2;
	if (r % 2 == 0)r1 = r / 2, r2 = (r - 1) / 2;
	else r1 = r2 = r / 2;
	return get(0, r1, 0).first >= 0 && get(0, r2, 1).first <= 0;
}
ll gett(int r) {
	int r1, r2;
	if (r % 2 == 0)r1 = r / 2, r2 = (r - 1) / 2;
	else r1 = r2 = r / 2;
	return get(0, r1, 0).second + get(0, r2, 1).second;
}
int get_gr(int is, int tl = 0, int tr = sz - 1, int v = 1) {
	push(is, v);
	if (is == 0 && t[is][v].first >= 0)return -1;
	if (is == 1 && t[is][v].first <= 0)return -1;
	if (tl == tr) {
		return tl;
	}
	int m = (tr + tl) / 2;
	int res = get_gr(is, tl, m, 2 * v);
	if (res != -1)return res;
	return get_gr(is, m + 1, tr, 2 * v + 1);
}

int find_gr() {
	return min(get_gr(0) * 2, get_gr(1) * 2 + 1) - 1;
}
void solve() {
	int n;
	cin >> n;
	sz = 1;
	while (sz < (n + 3) / 2)sz <<= 1;
	for (int i = sz; i < 2 * sz; ++i) {
		t[0][i].second = t[1][i].second = 1;
		p[0][i] = p[1][i] = t[0][i].first = t[1][i].first = 0;
	}
	for (int i = sz - 1; i > 0; --i) {
		t[0][i].second = t[1][i].second = t[0][2 * i].second + t[0][2 * i + 1].second;
		p[0][i] = p[1][i] = t[0][i].first = t[1][i].first = 0;
	}
	add(sz - 1, sz - 1, -INF, 0);
	add(sz - 1, sz - 1, INF, 1);
	vector<ll>a(n);
	for (auto& x : a)cin >> x;
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i % 2 == 1)a[i] = -a[i];
		add(i / 2, sz - 1, a[i], i % 2);
		add((i + 1) / 2, sz - 1, a[i], (i + 1) % 2);
		int l = min(find_gr(), n - 1);
		//cout << i << " " << l << endl;
		if (l == 0) {
			if (a[i] == 0)++ans;
		}
		else ans += gett(l) - i;
	}
	cout << ans << "\n";
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