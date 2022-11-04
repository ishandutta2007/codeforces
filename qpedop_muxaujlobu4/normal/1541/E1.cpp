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
const ld eps = 1e-6, pi = acosl(-1);
const ll maxN = 10210, maxT = 10010, A = 179, mid = 150;
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
int pl(const int& a, const int& b) {
	int r = a + b;
	if (r >= mod)r -= mod;
	return r;
}
vector<ll>c, b;
map<ll, ll>mp;
int n;
bool check_0(ll x) {
	ll d = 0, s = 0;
	bool ff = 1;
	for (int i = 0; i < n; ++i) {
		if (i) {
			d += b[i - 1];
			s += d;
		}
		ll vv = x * (i + 1) + s;
		ff &= vv <= 0;
	}
	return ff;
}
bool check_1(ll x) {
	ll d = 0, s = 0;
	bool ff = 0;
	ll sum_s = 0;
	for (int i = 0; i < n; ++i) {
		sum_s += c[i];
		if (i) {
			d += b[i - 1];
			s += d;
		}
		ll vv = x * (i + 1) + s;
		ff |= sum_s < vv;
	}
	return ff;
}
ll get_r(ll x) {
	if (mp.count(x))
		return mp[x];
	if (check_0(x)) {
		ll r = 1;
		for (auto x : c) {
			r = (r * (x + 1)) % mod;
		}
		return mp[x] = r;
	}
	if (check_1(x)) {
		return mp[x] = 0;
	}
	ll d = 0, s = 0;
	vector<vector<ll>>dp(n + 1, vector<ll>(maxN));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (i) {
			d += b[i - 1];
			s += d;
		}
		ll vv = x * (i + 1) + s;
		ll cc = c[i];
		for (int j = maxN - cc - 2; j >= 0; --j) {
			if (j + cc < vv)
				break;
			dp[i + 1][max(vv, (ll)j)] = pl(dp[i + 1][max(vv, (ll)j)], dp[i][j]);
			dp[i + 1][j + cc + 1] = pl(dp[i + 1][j + cc + 1], mod - dp[i][j]);
		}
		for (int j = 1; j < maxN; ++j) {
			dp[i + 1][j] = pl(dp[i + 1][j], dp[i + 1][j - 1]);
		}
	}
	ll ans = 0;
	for (int i = 0; i < maxN; ++i)
		ans = pl(ans, dp[n][i]);
	return mp[x] = ans;
}
void solve() {
	cin >> n;
	c.assign(n, 0);
	b.assign(n - 1, 0);
	for (auto& x : c)
		cin >> x;
	for (auto& x : b)
		cin >> x;
	int q;
	cin >> q;
	while (q--) {
		ll x;
		cin >> x;
		cout << get_r(x) << "\n";
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
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