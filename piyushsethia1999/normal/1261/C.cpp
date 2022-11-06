#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define all(con) con.begin1(),con.end()
const ll infl = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
//const int mod=998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int n, m;
string s[1000005];

int dp[5000005];
bool ok[1000006];

inline int in1(int i, int j) {
	return i * m + j;
}

bool clear(int t) {
	t = t * 2 + 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			int ii = in1(i, j);
			if (s[i][j] == 'X')
				ok[ii] = 1;
			if (dp[ii] == t) {
				for (int in = i; in < i + t; ++in) {
					for (int jn = j; jn < j + t; ++jn) {
						ok[in1(in, jn)] = 0;
					}
				}
			} else if (dp[ii] > t) {
				ok[ii] = 0;
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (ok[in1(i, j)]) {
				return false;
			}
		}
	}
	return true;
}


inline bool valid(int i, int j) {
	return i < n && j < m; 
}

void pre() {
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			int ii = in1(i, j);
			if (s[i][j] == 'X') {
				dp[ii] = 10000;
				if (valid(i + 1, j + 1)) dp[ii] = min(dp[ii], dp[in1(i + 1, j + 1)]); else dp[ii] = 0;
				if (valid(i + 1, j)) dp[ii] = min(dp[ii], dp[in1(i + 1, j)]); else dp[ii] = 0;
				if (valid(i, j + 1)) dp[ii] = min(dp[ii], dp[in1(i, j + 1)]); else dp[ii] = 0;
				dp[ii]++; 
				// dp[ii] = min(min(dp[in1(i + 1, j)], dp[in1(i, j + 1)]), dp[in1(i + 1, j + 1)]) + 1;
			}
		}
	}
	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cout << dp[in1(i, j)] << " ";
	// 	}
	// 	cout << '\n';
	// }
}

void fix(int t) {
	int t1 = t;
	t = t * 2 + 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			int ii = in1(i, j);
			if (s[i][j] == 'X')
				s[i][j] = '.';
			if (dp[ii] >= t) {
				s[i + t1][j + t1] = 'X';
			// } else {
				// print(dp[ii], t);
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	pre();
	int st = 0, et = 10004;
	while (st < et) {
		int mt = (st + et + 1) / 2;
		if (clear(mt)) {
			st = mt;
		} else {
			et = mt - 1;
		}
	}
	fix(st);
	cout << st << '\n';
	for (int i = 0; i < n; ++i) 
		cout << s[i] << '\n';
}