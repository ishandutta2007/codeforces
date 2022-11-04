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
const ld eps = 1e-13, pi = acos(-1);
const ll maxN = 100010, maxT = 50, A = 179, K = 420;
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
void solve() {
	ll k;
	cin >> k;
	map<string, int>cd;
	cd["white"] = 0;
	cd["yellow"] = 1;
	cd["green"] = 2;
	cd["blue"] = 3;
	cd["red"] = 4;
	cd["orange"] = 5;
	map<ll, int>clr;
	set<ll>qu;
	int n;
	cin >> n;
	map<ll, vector<ll>>dp;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		string s;
		cin >> s;
		clr[v] = cd[s];
		qu.insert(v);
		//qu.insert(v ^ 1);
	}

	while (!qu.empty()) {
		ll v = *qu.rbegin();
		qu.erase(v);
		if (v > 1)qu.insert(v / 2);
		if (dp.count(2 * v) && !dp.count(2 * v + 1)) {
			qu.insert(2 * v + 1);
			qu.insert(v);
			continue;
		}
		if (dp.count(2 * v + 1) && !dp.count(2 * v)) {
			qu.insert(2 * v);
			qu.insert(v);
			continue;
		}
		if (dp.count(2 * v)) {
			vector<ll>l = dp[2 * v], r = dp[2 * v + 1];
			vector<ll>my(6, 0);
			int cc = -1;
			if (clr.count(v))cc = clr[v];
			for (int i = 0; i < 6; ++i) {
				if (cc != -1 && i != cc)
					continue;
				ll sm = 0;
				for (auto x : r)sm = (sm + x) % mod;
				for (int j = 0; j < 6; ++j) {
					if (j == i || (j ^ 1) == i)
						continue;
					my[i] = (my[i] + l[j] * (sm - r[i] + mod - r[i ^ 1] + mod)) % mod;
				}
			}
			dp[v] = my;
			continue;
		}
		ll val = 0;
		ll cnt = 1;
		for (ll t = v * 2; t < (1LL << k); t *= 2) {
			cnt = (cnt * 2);
			val += cnt;
		}
		val %= mod - 1;
		val = bp(4, val);
		vector<ll>my(6, 0);
		if (clr.count(v)) {
			my[clr[v]] = val;
		}
		else {
			my.assign(6, val);
		}
		dp[v] = my;
	}
	ll ans = 0;
	for (auto x : dp[1])ans = (ans + x) % mod;
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
	//freopen("pluk.in", "r", stdin); freopen("pluk.out", "w", stdout);
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