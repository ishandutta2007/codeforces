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

int up[40][100000];
int mi[40][100000];
int we[40][100000];

int su[100000];
int mm[100000];
int pa[100000];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int k; cin >> k;
	for (int i = 0; i < n; ++i) cin >> up[0][i];
	for (int i = 0; i < n; ++i) cin >> mi[0][i];
	for (int i = 0; i < n; ++i) we[0][i] = mi[0][i];
	for (int i = 1; i < 40; ++i)
		for (int u = 0; u < n; ++u) 
			up[i][u] = up[i - 1][up[i - 1][u]],
			we[i][u] = we[i - 1][u] + we[i - 1][up[i - 1][u]],
			mi[i][u] = min(mi[i - 1][u], mi[i - 1][up[i - 1][u]]);
	for (int i = 0; i < n; ++i) mm[i] = 1000000000ll;
	for (int i = 0; i < n; ++i) pa[i] = i;
	for (int i = 0; i < 40; ++i) {
		if (k & (1ll << i)) {
			for (int u = 0; u < n; ++u) {
				mm[u] = min(mm[u], mi[i][pa[u]]);
				su[u] = su[u] + we[i][pa[u]];
				pa[u] = up[i][pa[u]];
			}
		}
	}
	for (int i = 0; i < n; ++i) cout << su[i] << " " << mm[i] << "\n";
}