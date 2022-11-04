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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 400100, maxT = 61, A = 179, mid = 150;
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
void solve(){
	int n;
	ll m;
	cin >> n >> m;
	vector<ll>qw(n);
	vector<vector<pair<ll, ll>>>seg(2, vector<pair<ll, ll>>(n));
	vector<vector<pair<ll, ll>>>dp(2, vector<pair<ll, ll>>(n + 1, { -1,-1 }));
	vector<vector<int>>p(2, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		cin >> qw[i];
		for (int j = 0; j < 2; ++j) {
			cin >> seg[j][i].first >> seg[j][i].second;
		}
	}
	dp[0].back() = dp[1].back() = { 0,m };
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < 2; ++j) {
			if (seg[j][i].first > qw[i] || qw[i] > seg[j][i].second) {
				continue;
			}
			if (dp[j][i + 1].first != -1) {
				dp[j][i] = dp[j][i + 1];
				dp[j][i].first = max(dp[j][i].first, seg[j ^ 1][i].first);
				dp[j][i].second = min(dp[j][i].second, seg[j ^ 1][i].second);
				p[j][i] = -1;
			}
			if (dp[j ^ 1][i + 1].first <= qw[i] && qw[i] <= dp[j ^ 1][i + 1].second) {
				dp[j][i] = seg[j ^ 1][i];
				p[j][i] = -2;
			}
		}
	}
	int st = -1;
	for (int j = 0; j < 2; ++j) {
		if (dp[j][0].first <= 0 && 0 <= dp[j][0].second) {
			st = j;
		}
	}
	if (st == -1) {
		cout << "No\n";
		return;
	}
	cout << "Yes\n";
	vector<int>ans(n);
	for (int i = 0; i < n; ++i) {
		ans[i] = st;
		if (p[st][i] == -2)st ^= 1;
	}
	for (auto x : ans)cout << x << " "; cout << "\n";
}
int main()
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