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
const ll INF = 2e18 + 100;
const int mod = 1000000007;
const ld eps = 1e-6, pi = acos(-1);
const ll maxN = 100010, maxT = 4096, A = 179, K = 170;
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
	cout << "No\n";
	exit(0);
}
ll ask(vector<int>qw) {
	cout << "? " << qw.size() << " ";
	for (auto x : qw)cout << x << " "; cout << endl;
	int v;
	cin >> v;
	return v;
}
vector<vector<ll>>g;
int tmr;
vector<int>tt, pp;
void dfs(int v) {
	tt[v] = tmr++;
	for (auto x : g[v]) {
		if (x == pp[v])
			continue;
		pp[x] = v;
		dfs(x);
	}
}
void solve() {
	ll n;
	cin >> n;
	g.assign(n, vector<ll>());
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int>qw(n);
	for (int i = 0; i < n; ++i)
		qw[i] = i + 1;
	ll mx = ask(qw);
	tmr = 0;
	tt.assign(n, 0);
	pp.assign(n, -1);
	dfs(0);
	vector<pair<int, int>>vv;
	for (int i = 0; i < n; ++i)vv.push_back({ tt[i],i + 1 });
	ll b = 1, e = n;
	sort(vv.begin(), vv.end());
	while (b + 1 != e) {
		ll m = (b + e) / 2;
		vector<int>qw;
		for (int i = 0; i < m; ++i)qw.push_back(vv[i].second);
		if (ask(qw) == mx)e = m;
		else b = m;
	}
	cout << "! " << pp[vv[e - 1].second - 1] + 1 << " " << vv[e - 1].second << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("party.in", "r", stdin); freopen("party.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}