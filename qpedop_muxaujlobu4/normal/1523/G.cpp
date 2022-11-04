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
const ll INF = 1e9;
const int mod = 1000000007;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 1 << 17, maxT = 61, A = 179, mid = 150;
mt19937 mt_rand(time(0));
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
int sz = 1;
struct tree
{
	vector<int>l, r;
	vector<int> t;
	inline int add() {
		int id = t.size();
		t.push_back(INF);
		l.push_back(-1);
		r.push_back(-1);
		return id;
	}
	tree() {
		l.assign(1, -1);
		r.assign(1, -1);
		t.assign(1, INF);
		/*l.reserve(1e4);
		r.reserve(1e4);
		t.reserve(1e4);*/
	}
	inline int get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 0) {
		if (ql <= tl && tr <= qr)
			return t[v];
		int m = (tr + tl) / 2, res = INF;
		//bld_cld(v);
		if (ql <= m && l[v] != -1) {
			res = min(res, get(ql, qr, tl, m, l[v]));
		}
		if (qr > m && r[v] != -1) {
			res = min(res, get(ql, qr, m + 1, tr, r[v]));
		}
		return res;
	}
	inline void upd(int qi, int val, int tl = 0, int tr = sz - 1, int v = 0) {
		while (tl != tr) {
			t[v] = min(t[v], val);
			int m = (tr + tl) / 2;
			if (qi <= m) {
				tr = m;
				if (l[v] == -1)
					l[v] = add();
				v = l[v];
			}
			else {
				tl = m + 1;
				if (r[v] == -1)
					r[v] = add();
				v = r[v];
			}
		}
		t[v] = min(t[v], val);
	}
};
vector<int>by_sz[maxN];
vector<pair<us, us>>qw;
tree t[maxN];
vector<pair<us, int>>to_push[maxN];
inline void push(int v) {
	for (auto x : to_push[v]) {
		t[v].upd(x.first, x.second);
		if (v < sz) {
			to_push[2 * v].push_back(x);
			to_push[2 * v + 1].push_back(x);
		}
	}
	to_push[v].clear();
	to_push[v].shrink_to_fit();
}
inline int get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	push(v);
	if (ql <= tl && tr <= qr) {
		return t[v].get(ql, qr);
	}
	int m = (tr + tl) / 2;
	int res = INF;
	if (ql <= m)
		res = min(res, get(ql, qr, tl, m, 2 * v));
	if (qr > m)
		res = min(res, get(ql, qr, m + 1, tr, 2 * v + 1));
	return res;
}
inline void upd(int ql, int qr, int qq, int val, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		to_push[v].push_back({ qq,val });
		push(v);
		return;
	}
	push(v);
	int m = (tr + tl) / 2;
	if (ql <= m) {
		upd(ql, qr, qq, val, tl, m, 2 * v);
	}
	if (qr > m) {
		upd(ql, qr, qq, val, m + 1, tr, 2 * v + 1);
	}
	t[v].upd(qq, val);
	//t[v].upd(qq, min(t[2 * v].get(qq, qq), t[2 * v + 1].get(qq, qq)));
}
inline int rec(int l, int r) {
	if (r < l)return 0;
	int idx = get(l, r);
	if (idx == INF)return 0;
	int res = (int)qw[idx].second - qw[idx].first + 1;
	res += rec(l, (int)qw[idx].first - 1);
	res += rec((int)qw[idx].second + 1, r);
	return res;
}
void solve() {
	int n, m;
	cin >> n >> m;
	while (sz < n)sz <<= 1;
	qw.assign(m, pair<int, int>());
	for (int i = 0; i < m; ++i) {
		cin >> qw[i].first >> qw[i].second;
		--qw[i].first;
		--qw[i].second;
		by_sz[qw[i].second - qw[i].first + 1].push_back(i);
	}
	//build();
	vector<int>ans(n);
	for (int sz = n; sz > 0; --sz) {
		for (auto x : by_sz[sz]) {
			upd(qw[x].first, qw[x].first, qw[x].second, x);
		}
		by_sz[sz].clear();
		by_sz[sz].shrink_to_fit();
		ans[sz - 1] = rec(0, n - 1);
	}
	for (auto x : ans)
		cout << x << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
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