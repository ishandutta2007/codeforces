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
void solve() {
	int n;
	cin >> n;
	vector<ll>a(n);
	for (auto& x : a)
		cin >> x;
	vector<vector<ll>>pb(n, vector<ll>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			pb[i][j] = a[i] * bp(a[i] + a[j], mod - 2) % mod;
		}
	}
	vector<ll>dp(1 << n);
	ll ans = 0;
	for (int i = 1; i < (1 << n); ++i) {
		dp[i] = 1;
		vector<ll>vert(n, 1);
		for (int f = 0; f < n; ++f) {
			if ((i & (1 << f)) == 0)
				continue;
			for (int s = 0; s < n; ++s) {
				if ((i & (1 << s)) != 0)
					continue;
				dp[i] = dp[i] * pb[f][s] % mod;
				vert[f] = vert[f] * pb[f][s] % mod;
			}
		}
		for (int m = (i - 1) & i; m; m = (m - 1) & i) {
			int m1 = i ^ m;
			ll tmp = dp[m];
			for (int j = 0; j < n; ++j) {
				if ((m1 & (1 << j)) != 0)tmp = tmp * vert[j] % mod;
			}
			dp[i] = (dp[i] - tmp + mod) % mod;
		}


		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0)++cnt;
		}
		ans = (ans + dp[i] * cnt) % mod;
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