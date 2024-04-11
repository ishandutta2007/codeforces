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
const ld eps = 1e-6, pi = acos(-1);
const ll maxN = 110, maxT = 4096, A = 179, K = 170;
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
	cout << "-1\n";
	exit(0);
}
ll dp[maxN][maxN][maxN];
vector<vector<ll>>c;
vector<ll>fact;
ll C(int n, int k) {
	return c[n - k][k];
}
int n, m, k, p;
void lazy(int sz, int cnt, int dep) {
	if (dp[dep][sz][cnt] != -1)return;
	ll& F = dp[dep][sz][cnt];
	F = 0;
	if (!sz) {
		F = 1;
		return;
	}
	//if ((m - dep < 7 && (1 << (m - dep)) < cnt) || (cnt && sz < m - dep)) return;
	if (dep == m) {
		F = (cnt == 1 ? fact[sz] : 0);
		return;
	}
	for (int i = 0; i < sz; ++i) {
		ll fi = 0;
		for (int j = max(0, cnt + i + 1 - sz); j <= min(cnt, i); j++)
			if (dp[dep + 1][i][j] && dp[dep + 1][sz - i - 1][cnt - j]) {
				lazy(i, j, dep + 1);
				lazy(sz - i - 1, cnt - j, dep + 1);
				fi = (fi + 1ll * dp[dep + 1][i][j] * dp[dep + 1][sz - i - 1][cnt - j]) % p;
			}
		F = (F + 1ll * fi * c[sz - 1 - i][i]) % p;
	}
}
void solve() {
	cin >> n >> m >> k >> p;
	--m;
	c.assign(maxN, vector<ll>(maxN, 1 % p));
	fact.assign(maxN, 1 % p);
	for (int i = 1; i < maxN; ++i)
		fact[i] = (ll)fact[i - 1] * i % p;
	for (int i = 1; i < maxN; ++i) {
		for (int j = 1; j < maxN; ++j) {
			c[i][j] = (c[i - 1][j] + c[i][j - 1]) % p;
		}
	}
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			for (int t = 0; t < maxN; ++t)dp[i][j][t] = -1;
		}
	}
	lazy(n, k, 0);
	cout << dp[0][n][k] << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("snake.in", "r", stdin); freopen("snake.out", "w", stdout);
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