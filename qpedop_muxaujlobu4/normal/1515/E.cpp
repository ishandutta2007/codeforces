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
int mod = 1000000007;
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 200100, maxT = 10010, A = 179, mid = 150;
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
int pl(const int& a, const int& b) {
	int r = a + b;
	if (r >= mod)r -= mod;
	return r;
}
void solve() {
	int n;
	cin >> n >> mod;
	if (n <= 3) {
		if (n == 3)cout << "6\n";
		if (n == 2)cout << "2\n";
		if (n == 1)cout << "1\n";
		return;
	}
	build();
	vector<ll>fun(n + 1);
	fun[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int st = 1; st <= i; ++st) {
			fun[i] = pl(fun[i], c(i - 1, st - 1));
		}
	}
	vector<vector<ll>>dp(n + 1, vector<ll>(n + 1, 0));
	dp[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][1] = fun[i];
	}
	for (int i = 2; i <= n; ++i) {
		for (int k = 2; k <= n; ++k) {
			for (int st = 1; st + 1 < i; ++st) {
				int cnt_empty = k - 2;
				if (cnt_empty > st)
					continue;
				int cnt_have = st - cnt_empty;
				int len = i - st - 1;
				dp[i][k] = pl(dp[i][k], dp[st][k - 1] *
					c(cnt_have + len, cnt_have) % mod * fun[len] % mod);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans = pl(ans, dp[n][i]);
	}
	cout << ans << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
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

/*
5
2 1 3 5 4
simple solve: 1 2 3 1 2
1 2 3 3 3
*/