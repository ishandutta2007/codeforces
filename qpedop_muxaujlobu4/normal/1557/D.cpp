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
const ll maxN = 1 << 20, maxT = 519, A = 179, mid = 150, K = 350;
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
	cout << "No\n";
	exit(0);
}
pair<int, int> t[maxN << 1], p[maxN << 1];
int sz = maxN;
void push(int v) {
	t[v] = max(t[v], p[v]);
	if (v < sz) {
		p[2 * v] = max(p[2 * v], p[v]);
		p[2 * v + 1] = max(p[2 * v + 1], p[v]);
	}
	p[v] = { 0,0 };
}
void sett(int ql, int qr, pair<int, int> add, int tl = 0, int tr = sz - 1, int v = 1) {
	if (ql <= tl && tr <= qr) {
		p[v] = max(p[v], add);
		push(v);
		return;
	}
	int m = (tr + tl) / 2;
	if (ql <= m) {
		sett(ql, qr, add, tl, m, 2 * v);
	}
	else push(2 * v);
	if (qr > m)
		sett(ql, qr, add, m + 1, tr, 2 * v + 1);
	else push(2 * v + 1);
	t[v] = max(t[2 * v], t[2 * v + 1]);
}
pair<int, int> get(int ql, int qr, int tl = 0, int tr = sz - 1, int v = 1) {
	push(v);
	if (ql <= tl && tr <= qr) {
		return t[v];
	}
	int m = (tr + tl) / 2;
	pair<int, int> r = { 0,sz };
	if (ql <= m)
		r = max(r, get(ql, qr, tl, m, 2 * v));
	else push(2 * v);
	if (qr > m)
		r = max(r, get(ql, qr, m + 1, tr, 2 * v + 1));
	else push(2 * v + 1);
	return r;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>vls;
	vector<vector<pair<int, int>>>seg(n);
	for (int i = 0; i < m; ++i) {
		int id, l, r;
		cin >> id >> l >> r; 
		vls.push_back(l);
		vls.push_back(r);
		seg[--id].push_back({ l,r });
	}
	sort(vls.begin(), vls.end());
	vls.resize(unique(vls.begin(), vls.end()) - vls.begin());
	vector<int>dp(n);
	vector<int>pr(n);
	for (int i = n - 1; i >= 0; --i) {
		for (auto& p : seg[i]) {
			p.first = lower_bound(vls.begin(), vls.end(), p.first) - vls.begin();
			p.second = lower_bound(vls.begin(), vls.end(), p.second) - vls.begin();
		}
		for (auto p : seg[i]) {
			pair<int, int>tmp = get(p.first, p.second);
			if (tmp.first + 1 > dp[i]) {
				dp[i] = tmp.first + 1;
				pr[i] = tmp.second;
			}
			//dp[i] = max(dp[i], get(p.first, p.second) + 1);
		}
		for (auto p : seg[i]) {
			sett(p.first, p.second, { dp[i],i });
		}
	}


	push(1);
	int vv = t[1].second;
	cout << n - t[1].first << "\n";
	set<int>ss;
	for (int i = 0; i < n; ++i)
		ss.insert(i);
	while (dp[vv] > 1) {
		ss.erase(vv);
		vv = pr[vv];
	}
	ss.erase(vv);
	for (auto x : ss)
		cout << x + 1 << " ";

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