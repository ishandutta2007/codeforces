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

int ii;
vi gr[400005];
int pa[400005];
int de[400005];
int ma[400005];

int dfs(int u, int p) {
	de[u] = de[p] + 1;
	pa[u] = p;
	ma[u] = de[u];
	for (int v : gr[u])
		if (v != p)
			ma[u] = max(ma[u], dfs(v, u));
	return ma[u];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	cin >> ii; ii--;
	for (int i = 0; i < n - 1; ++i) {
		int x; cin >> x; x--;
		int y; cin >> y; y--;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	dfs(0, 0);
	int ans = 0;
	int re = de[0];
	while (de[ii] > re + 2) {
		ii = pa[ii];
		re++;
	}
	cout << (ma[ii] - 1) * 2;
}