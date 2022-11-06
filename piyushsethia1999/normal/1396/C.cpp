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

int dp[1000006][8], a[1000006];

void minn(int& aaa, int a) {
	aaa = min(aaa, a);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	// 0 -> all dead
	// 1 -> one boss
	/////////////////// 2 -> boss
	// 3 -> all
	int n; cin >> n;
	int r1; cin >> r1;
	int r2; cin >> r2;
	int r3; cin >> r3;
	int d; cin >> d;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n + 2; ++i) {
		for (int j = 0; j < 8; ++j) 
			dp[i][j] = 500000000000000000ll;
	}
	dp[0][3] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 8; j >= 0; --j) {
			int st = j % 4, pst = j / 4;
			if (pst == 0) {
			 	if (st == 0) {
			 		minn(dp[i + 1][3], dp[i][j] + d);
			 	} else if (st == 1) {
			 		// r3
			 		minn(dp[i][0], dp[i][j] + r3);
			 		// r2
			 		minn(dp[i][0], dp[i][j] + r2);
			 		// r1
			 		minn(dp[i][0], dp[i][j] + r1);
			 	} else if (st == 2) {
			 		// r3
			 		minn(dp[i][0], dp[i][j] + r3);
			 		// r2
			 		minn(dp[i][1], dp[i][j] + r2 + d + d);
			 		minn(dp[i + 1][3 + 4], dp[i][j] + r2 + d);
			 		// r1
			 		minn(dp[i][1], dp[i][j] + r1 + d + d);
			 		minn(dp[i + 1][3 + 4], dp[i][j] + r1 + d);
			 	} else {
			 		// r3
			 		minn(dp[i][2], dp[i][j] + r3 * a[i]);
			 		// r2
			 		minn(dp[i][1], dp[i][j] + r2 + d + d);
			 		minn(dp[i + 1][3 + 4], dp[i][j] + r2 + d);
			 		// r1
			 		minn(dp[i][2], dp[i][j] + r1 * a[i]);
			 	}
			} else if (pst == 1) {
			 	if (st == 0) {
			 		minn(dp[i][0], dp[i][j] + d + min({r1, r2, r3}) + d);
			 		if (i == n - 1) 
				 		minn(dp[i][0], dp[i][j] + d + min({r1, r2, r3}));
			 	} else if (st == 1) {
			 		// r3
			 		minn(dp[i][0], dp[i][j] + r3 + d + min({r1, r2, r3}));
			 		// r2
			 		minn(dp[i][0], dp[i][j] + r2 + d + min({r1, r2, r3}));
			 		// r1
			 		minn(dp[i][0], dp[i][j] + r1 + d + min({r1, r2, r3}));
			 	} else if (st == 2) {
			 		// r3
			 		minn(dp[i][0 + 4], dp[i][j] + r3);
			 		// r2
			 		minn(dp[i][1], dp[i][j] + r2 + d + min({r1, r3, r2}) + d);
			 		// r1
			 		minn(dp[i][1], dp[i][j] + r1 + d + min({r1, r3, r2}) + d);
			 	} else {
			 		// sabko 1 1 karke maaro then use pistol aur awp
			 		int c1 = min(r1, r3) * a[i];
			 		minn(dp[i][2 + 4], dp[i][j] + c1);

			 		// use r2
			 		minn(dp[i][1], dp[i][j] + r2 + d + min({r1, r3, r2}) + d);
			 	}			 	
			}
		}
		// print(pair(dp[i], 8));
		// print(pair(dp[i + 1], 8));
	}
	cout << dp[n - 1][0] << '\n';
}