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

int mal[100005];
int mar[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	string s; cin >> s;
	string t; cin >> t;
	int j = 0;
	int m = t.size();
	mal[0] = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (j < m && s[i] == t[j])
			j++;
		mal[i + 1] = j;
	}
	int n = s.size();
	mar[n] = 0;
	j = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (j < m && s[i] == t[m - j - 1])
			j++;
		mar[i] = j;
	}
	int ii = 0;
	for (int i = 0; i <= n; ++i)
		if (mal[ii] + mar[ii] < mal[i] + mar[i]) 
			ii = i;
	if (mal[ii] + mar[ii] > m) {
		cout << t << '\n';
	} else if(mal[ii] + mar[ii] > 0) {
		cout << t.substr(0, mal[ii]) + t.substr(sz(t) - mar[ii], mar[ii]);
	} else {
		cout << "-" << '\n';
	}
}