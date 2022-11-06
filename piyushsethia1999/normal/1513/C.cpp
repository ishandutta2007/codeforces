#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef print
#define print(...)
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod = 998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int d[20][10][10];

void dd(int m, vi& dp) {
	for (int i = 0; i < 20; ++i) {
		if (m & (1ll << i)) {
			vi tdp(10, 0);
			for (int j = 0; j < 10; ++j) {
				for (int k = 0; k < 10; ++k) {
					tdp[k] += (dp[j] * d[i][j][k]) % mod;
					tdp[k] %= mod;
				}
				// print(tdp);
			}
			swap(tdp, dp);
			// print(tdp);
		} 
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	for (int i = 0; i < 9; ++i)
		d[0][i][i + 1] = 1;
	d[0][9][0] = d[0][9][1] = 1;
	for (int l = 1; l < 20; ++l) {
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				for (int k = 0; k < 10; ++k) {
					d[l][i][j] += (d[l - 1][i][k] * d[l - 1][k][j]) % mod;
					d[l][i][j] %= mod;
				}
			}
		}
	}
	// int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int m; cin >> m;
		vi dp(10, 0);
		int nn = 0;
		while (n) {
			dp[n % 10]++;
			n /= 10;
		} 
		// print(dp);
		dd(m, dp);
		// print(dp);
		int ans = 0;
		for (int i = 0; i < 10; ++i) {
			ans += dp[i];
		}
		ans %= mod;
		cout << (ans + mod) % mod << '\n';
	}
}