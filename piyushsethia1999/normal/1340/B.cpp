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

int diff(string&a, string& b) {
	int cnt = 0;
	for (int i = 0; i < 7; ++i) {
		if (a[i] == '1' && b[i] == '0') return -1;
		if (a[i] == '0' && b[i] == '1') cnt++;
	}
	return cnt;
}

string ss[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool dp[4001][4001];
string s[4000];
std::vector<pii> a[2005];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	dp[0][0] = 1;
	int n; cin >> n;
	int k; cin >> k;
	for (int i = 0; i < n; ++i) cin >> s[i];
	reverse(s, s + n);
	for (int i = 0; i < n; ++i) 
		for (int j = 9; j >= 0; --j) {
			int co = diff(s[i], ss[j]);
			if (co != -1)
				a[i].pb({co, j}); 
		}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			for (auto p : a[i])
			if (dp[i][j])
				dp[i + 1][j + p.fi] = 1; 
		}
	}
	if (!dp[n][k]) {
		cout << -1 << '\n';
		return 0;
	}
	string res = "";
	for (int i = n - 1; i >= 0; --i) {
		for (auto p : a[i]) {
			if (dp[i][k - p.fi]) {
				k -= p.fi;
				res += ('0' + p.se);
				break;
			} 
		}
	}
	cout << res;
}