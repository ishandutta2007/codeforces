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
const ll maxN = 8192, maxT = 5010, A = 179, K = 450;
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
int dp[maxN];
vector<int>idx[maxT];
void show() {
	set<int>ans;
	for (int i = 0; i < maxN; ++i) {
		if (dp[i] != INF) {
			ans.insert(i);
		}
	}
	cout << ans.size() << "\n";
	for (auto x : ans)cout << x << " ";
	cout << "\n";
}
void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		idx[v].push_back(i + 1);
	}
	for (int i = 1; i < maxN; ++i)dp[i] = INF;
	for (int j = 1; j < maxT; ++j) {
		if (idx[j].empty())
			continue;
		if (idx[j].size() >= 1000) {
			vector<pair<int, int>>msk;
			msk.reserve(maxN);
			for (int i = 0; i < maxN; ++i) {
				int vll = dp[i ^ j];
				if (vll == INF)
					continue;
				msk.push_back({ vll,i });
			}
			sort(msk.begin(), msk.end());
			int sz = msk.size();
			int y = 0;
			for (auto x : idx[j]) {
				while (y < sz && msk[y].first < x) {
					dp[msk[y].second] = min(dp[msk[y].second], x);
					++y;
				}
			}
		}
		else {
			int sz = idx[j].size();
			for (int i = 0; i < maxN; ++i) {
				int vll = dp[i ^ j];
				if (vll == INF)
					continue;
				int ms = i;
				int b = -1, e = sz;
				while (b + 1 != e) {
					int m = (b + e) / 2;
					if (idx[j][m] >= vll)e = m;
					else b = m;
				}
				if (e == sz)
					continue;
				dp[ms] = min(dp[ms], idx[j][e]);
			}
		}
		//show();
	}
	show();
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