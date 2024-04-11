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
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 200010, maxT = 200000, A = 179, K = 450;
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
ll f[maxN], g[maxN];
ll p2[maxN];
void build() {
	f[0] = g[0] = 1;
	p2[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
		p2[i] = p2[i - 1] * 2 % mod;
	}
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
	int n, m;
	cin >> n >> m;
	const int mx_b = 30;
	vector<vector<ll>>arr(mx_b, vector<ll>(n + 1));
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		ll x;
		cin >> x;
		for (int j = 0; j < mx_b; ++j) {
			if ((x & (1LL << j)) == 0)
				++arr[j][l], --arr[j][r];
		}
	}
	ll ans = 0;
	for (int bit = 0; bit < mx_b; ++bit) {
		ll vl = 1LL << bit;
		vl %= mod;
		for (int j = 1; j <= n; ++j)arr[bit][j] += arr[bit][j - 1];
		int c1 = 0, c0 = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[bit][i] == 0)++c1;
			else ++c0;
		}
		for (int i = 1; i <= c1; i += 2) {
			ans = (ans + c(c1, i) * p2[c0] % mod * vl) % mod;
		}
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
	build();
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