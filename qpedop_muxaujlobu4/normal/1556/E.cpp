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
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 100010, maxT = 600100, A = 179, K = 170;
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
pair<ll, ll>t[maxN << 2];
int sz = 1;
void sett(int v, ll vl) {
	t[v | sz] = { vl,vl };
	for (v = (v | sz) / 2; v; v >>= 1) {
		t[v].first = min(t[2 * v].first, t[2 * v + 1].first);
		t[v].second = max(t[2 * v].second, t[2 * v + 1].second);
	}
}
pair<ll, ll>get(int l, int r) {
	ll mn = INF, mx = -INF;
	for (l |= sz, r |= sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1) {
			mn = min(mn, t[l].first);
			mx = max(mx, t[l++].second);
		}
		if (r % 2 == 0) {
			mn = min(mn, t[r].first);
			mx = max(mx, t[r--].second);
		}
	}
	return { mn,mx };
}
void solve() {
	int n, q;
	cin >> n >> q;
	vector<ll>ps(n + 1), a(n), b(n);
	for (auto& x : a)
		cin >> x;
	for (auto& x : b)
		cin >> x;
	while (sz <= n)
		sz <<= 1;
	sett(0, 0);
	for (int i = 0; i < n; ++i) {
		ps[i + 1] = ps[i] + (b[i] - a[i]);
		sett(i + 1, ps[i + 1]);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		ll mn, mx;
		tie(mn, mx) = get(l, r);
		if (ps[r] != ps[l - 1] || mn != ps[r]) {
			cout << "-1\n";
		}
		else cout << mx - mn << "\n";
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
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
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