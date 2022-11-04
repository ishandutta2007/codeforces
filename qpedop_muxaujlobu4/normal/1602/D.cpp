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
const ll maxN = 1 << 20, maxT = 1010, A = 179, K = 450;
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
vector<pair<int, int>>t;
int sz = 1;
void sett(int v, pair<int, int>vl) {
	t[v + sz] = vl;
	for (v = v + sz >> 1; v; v >>= 1)t[v] = max(t[2 * v]
		, t[2 * v + 1]);
}
pair<int, int> get(int l, int r) {
	pair<int, int>rr = { -1,-1 };
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1)rr = max(rr, t[l++]);
		if (r % 2 == 0)rr = max(rr, t[r--]);
	}
	return rr;
}
void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1), b(n + 1);
	sz = 1;
	while (sz <= n)sz <<= 1;
	t.assign(2 * sz, make_pair(-1, -1));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	vector<int>p(n + 1, -1);
	p[n] = n;
	vector<int>upp(n + 1);
	vector<vector<int>>g(n + 1);
	for (int i = 1; i <= n; ++i) {
		int to = min(n, i + b[i]);
		if (to == n)
			sett(i, make_pair(0, n));
		else sett(i, make_pair(INF, to));
		g[to].push_back(i);
	}
	queue<int>bfs;
	bfs.push(n);
	while (!bfs.empty()) {
		int v = bfs.front();
		bfs.pop();
		if (a[v] == v) {
			//cout << "find!\n";
			vector<int>ans;
			p[0] = v;
			upp[0] = 0;
			int vv = 0;
			while (vv != n) {
				ans.push_back(upp[vv]);
				vv = p[vv];
			}
			cout << ans.size() << "\n";
			reverse(ans.begin(), ans.end());
			for (auto x : ans)cout << x << " "; cout << "\n";
			return;
		}
		int l = v - a[v], r = v;
		while (true) {
			int id = get(l, r).second;
			if (p[id] != -1)break;
			p[id] = v;
			bfs.push(id);
			for (auto x : g[id]) {
				sett(x, { 0,id });
				if (l <= x && x <= r)upp[id] = x;
			}
		}
	}

	cout << "-1\n";
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