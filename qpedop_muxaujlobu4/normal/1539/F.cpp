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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200100, maxT = 61, A = 179, mid = 150;
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
pair<int, int>operator +(const pair<int, int>& a, const int& b) {
	return { a.first + b,a.second + b };
}
pair<int, int> tree[maxN << 2];
int to_push[maxN << 2];
int sz = 1;
void push(int v) {
	tree[v] = tree[v] + to_push[v];
	if (v < sz) {
		to_push[2 * v] += to_push[v];
		to_push[2 * v + 1] += to_push[v];
	}
	to_push[v] = 0;
}
void add(int ql, int qr, int val, int tl = 0, int tr = sz - 1, int v = 1) {
	push(v);
	if (ql <= tl && tr <= qr) {
		to_push[v] += val;
		push(v);
		return;
	}
	int m = (tr + tl) / 2;
	if (ql <= m)
		add(ql, qr, val, tl, m, 2 * v);
	if (qr > m)
		add(ql, qr, val, m + 1, tr, 2 * v + 1);
	push(2 * v);
	push(2 * v + 1);
	tree[v].first = min(tree[2 * v].first, tree[2 * v + 1].first);
	tree[v].second = max(tree[2 * v].second, tree[2 * v + 1].second);
}
void upd(pair<int, int>& a, pair<int, int>b) {
	a.first = min(a.first, b.first);
	a.second = max(a.second, b.second);
}
pair<int, int>get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	push(v);
	if (ql <= tl && tr <= qr) {
		return tree[v];
	}
	int m = (tr + tl) / 2;
	pair<int, int> res = { INF, -INF };
	if (ql <= m) {
		upd(res, get(ql, qr, tl, m, 2 * v));
	}
	if (qr > m) {
		upd(res, get(ql, qr, m + 1, tr, 2 * v + 1));
	}
	return res;
}
void solve(){
	int n;
	cin >> n;
	vector<vector<int>>ps(n);
	vector<int>a(n);
	while (sz <= n)
		sz <<= 1;
	fill(begin(tree), end(tree), make_pair(0, 0));
	vector<int>ans(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		add(i + 1, n, 1);
		ps[--a[i]].push_back(i);
	}
	for (const auto &vec : ps) {
		for (auto i : vec) {
			pair<int, int>l, r;
			r = get(i + 1, n);
			l = get(0, i);
			int cnt = r.second - l.first;
			ans[i] = max(ans[i], cnt / 2);
		}
		for (auto i : vec) {
			add(i + 1, n, -2);
		}
		for (auto i : vec) {
			pair<int, int>l, r;
			r = get(i + 1, n);
			l = get(0, i);
			int cnt = abs(r.first - l.second);
			ans[i] = max(ans[i], (cnt - 1) / 2);
		}
	}

	for (auto x : ans)cout << x << " "; cout << "\n";
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
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}