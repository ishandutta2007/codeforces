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
const ll maxN = 200010, maxT = 519, A = 179, mid = 150, K = 350;
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
ll f[maxN], g[maxN];
void build() {
	f[0] = g[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
	}
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<vector<ll>>dp(2, vector<ll>(k + 1));
	dp[0][0] = 1;
	vector<ll>dd(2);
	for (int k1 = 0; k1 < n; ++k1) {
		dd[k1 % 2] = (dd[k1 % 2] + c(n, k1)) % mod;
	}
	for (int i = 0; i < k; ++i) {
		dp[1][i + 1] = (dp[1][i + 1] + dp[1][i] * dd[0]) % mod;
		dp[1][i + 1] = (dp[1][i + 1] + dp[1][i] * dd[1]) % mod;
		dp[1][i + 1] = (dp[1][i + 1] + dp[1][i]) % mod;
		if (n % 2 == 0) {
			dp[1][i + 1] = (dp[1][i + 1] + dp[0][i]) % mod;
		}
		else dp[0][i + 1] = (dp[0][i + 1] + dp[0][i]) % mod;
		dp[0][i + 1] = (dp[0][i + 1] + dp[0][i] * dd[0]) % mod;
	}


	cout << (dp[0].back() + dp[1].back()) % mod << "\n";
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
	build();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}