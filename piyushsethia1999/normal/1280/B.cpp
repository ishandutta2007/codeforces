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
#define all(con) con.begin(),con.end()
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


string s[100];
int n, m;

bool check4() {
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			if (s[i][j] == 'A')
				return 1;
	return 0;
}

bool check3() {
	for (int i = 0; i < n; ++i) 
		if (s[i][m - 1] == 'A' || s[i][0] == 'A') return 1;
	for (int j = 0; j < m; ++j) 
		if (s[0][j] == 'A' || s[n - 1][j] == 'A') return 1;
	return 0; 
}

bool check2() {
	if (s[0][0] == 'A' || s[0][m - 1] == 'A' || s[n - 1][0] == 'A' || s[n - 1][m - 1] == 'A') return 1;
	for (int i = 0; i < n; ++i) {
		bool ok = 1;
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'P') ok = 0; 
		}
		if (ok) return 1;
	}
	for (int j = 0; j < m; ++j) {
		bool ok = 1;
		for (int i = 0; i < n; ++i) {
			if (s[i][j] == 'P') ok = 0; 
		}
		if (ok) return 1;
	}
	return 0;
}

bool check1() {
	bool ok = 1;
	for (int i = 0; i < n; ++i) 
		if (s[i][0] == 'P') ok = 0;
	if (ok) return 1;
	ok = 1;
	for (int i = 0; i < n; ++i) 
		if (s[i][m - 1] == 'P') ok = 0;
	if (ok) return 1;
	ok = 1;
	for (int i = 0; i < m; ++i) 
		if (s[0][i] == 'P') ok = 0;
	if (ok) return 1;
	ok = 1;
	for (int i = 0; i < m; ++i) 
		if (s[n - 1][i] == 'P') ok = 0;
	if (ok) return 1;
	ok = 1;
	return 0;
}

bool check0() {
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			if (s[i][j] == 'P') return 0;
	return 1; 
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		cin >> n;
		cin >> m;
		for (int i = 0; i < n; ++i) cin >> s[i];
		if (check0()) {
			cout << 0 << '\n';
		} else if(check1()) {
			cout << 1 << '\n';
		} else if(check2()) {
			cout << 2 << '\n';
		} else if(check3()) {
			cout << 3 << '\n';
		} else if(check4()) {
			cout << 4 << '\n';
		} else {
			cout << "MORTAL" << '\n';
		}
	}
}