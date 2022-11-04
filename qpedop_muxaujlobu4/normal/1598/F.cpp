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
const ll maxN = 1000010, maxT = 3010, A = 179, K = 420;
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
	cout << "No solution\n";
	exit(0);
}
int sub[20][2 * maxN];
void solve() {
	int n;
	cin >> n;
	vector<int>min_bal(n), dlt(n), cnt(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int mn = 0, b = 0;
		for (auto x : s) {
			if (x == '(')++b;
			else --b;
			if (b < mn)mn = b, cnt[i] = 0;
			if (b == mn) {
				++cnt[i];
				++sub[i][maxN + b];
			}
		}
		min_bal[i] = mn;
		dlt[i] = b;
	}
	vector<int>dp(1 << n, -INF);
	int ans = 0;
	dp[0] = 0;
	for (int i = 0; i < (1 << n); ++i) {
		if (dp[i] < 0)continue;
		int dd = 0;
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) != 0)dd += dlt[j];
		}
		for (int j = 0; j < n; ++j) {
			if ((i & (1 << j)) == 0) {
				if (dd + min_bal[j] < 0) {
					int wnt = -dd;
					ans = max(ans, dp[i] + sub[j][maxN + wnt]);
					continue;
				}
				int tmp = dp[i];
				if (dd + min_bal[j] == 0)tmp += cnt[j];
				dp[i | (1 << j)] = max(dp[i | (1 << j)], tmp);
			}
		}
		ans = max(ans, dp[i]);
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
	//freopen("input.in", "r", stdin); freopen("input.out", "w", stdout);
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