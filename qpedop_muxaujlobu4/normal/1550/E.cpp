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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200010, maxT = 25000, A = 179, mid = 150;
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
int n, k;
string s;
bool f(int l) {
	vector<int>dp(1 << k, INF);
	dp[0] = 0;
	vector<int>cnt(k + 1);
	int y = 0;
	vector<vector<int>>rf(k, vector<int>(n + 1, INF));
	for (int i = 0; i + l <= n; ++i) {
		while (y < i + l && y < n) {
			if (s[y] != '?')
				++cnt[s[y++] - 'a'];
			else {
				++cnt.back();
				++y;
			}
		}
		for (int j = 0; j < k; ++j) {
			if (cnt[j] + cnt.back() == l) {
				rf[j][i] = i + l;
			}
		}
		if (s[i] != '?')
			--cnt[s[i] - 'a'];
		else
			--cnt.back();
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < k; ++j) {
			rf[j][i] = min(rf[j][i], rf[j][i + 1]);
		}
	}
	for (int i = 0; i < (1 << k); ++i) {
		if (dp[i] > n)
			continue;
		for (int j = 0; j < k; ++j) {
			dp[i | (1 << j)] =
				min(dp[i | (1 << j)], rf[j][dp[i]]);
		}
	}

	return dp.back() <= n;
}
void solve() {
	cin >> n >> k >> s;
	int b = 0, e = n + 1;
	while (b + 1 != e) {
		int m = (b + e) / 2;
		if (f(m))b = m;
		else e = m;
	}
	cout << b << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}