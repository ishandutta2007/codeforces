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
const ll maxN = 50010, maxT = 600100, A = 179, K = 170;
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
void solve() {
	int n;
	cin >> n;
	vector<ll>c(n);
	for (auto& x : c)
		cin >> x;
	vector<pair<ll, ll>>seg(n);
	seg[0] = { 0,c[0] };
	ll b = c[0];
	for (int i = 1; i < n; ++i) {
		if (i % 2 == 1) {
			seg[i] = { b - c[i],b - 1 };
			b -= c[i];
		}
		else {
			seg[i] = { b + 1,b + c[i] };
			b += c[i];
		}
	}
	ll ans = 0;

	for (int i = 0; i < n; ++i) {
		ll bb = 0;
		for (int j = 0; j <= i; ++j) {
			if (j % 2 == 0)bb += c[j];
			else bb -= c[j];
		}
		ll mn = bb;
		for (int j = i + 1; j < n; ++j) {
			ll l, r, l1, r1;
			tie(l, r) = seg[i];
			tie(l1, r1) = seg[j];
			ans += max(0LL, min(mn, min(r, r1)) - max(l, l1) + 1);
			if (j % 2 == 0)bb += c[j];
			else bb -= c[j];
			mn = min(mn, bb);
		}
	}
	cout << ans << endl;
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