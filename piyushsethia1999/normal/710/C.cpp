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

int a[50][50];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	set<pii> odd;
	for (int i = 0; i < n; ++i) odd.insert({n / 2, i}), odd.insert({i, n / 2}), a[i][n / 2] = a[n / 2][i] = 1;
	int m = (n * n + 1) / 2 - odd.size();
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			if ((!a[i][j]) && m) {
				m -= 4;
				a[i][j] = a[n - 1 - i][j] = a[i][n - 1 - j] = a[n - 1 - i][j] = a[n - 1 - i][n - 1 -j] = 1;
				odd.insert({i, j});
				odd.insert({n - i - 1, j});
				odd.insert({n - i - 1, n - 1 -j});
				odd.insert({i, n - 1 -j});
			}
	int ii = 1;
	for (auto oo : odd) {
		a[oo.fi][oo.se] = ii;
		ii += 2;
	}
	ii = 2;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			if (!a[i][j]) {
				a[i][j] = ii;
				ii += 2;
			}
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			cout << a[i][j] << " \n"[j == n - 1];
}