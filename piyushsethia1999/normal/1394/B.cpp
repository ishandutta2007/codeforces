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
// #define int long long
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

std::vector<pii> ad[200005];
map<pii, int> mp[200005];
set<int> ss[10];

int state(int k, int c) {
	return k * (k - 1) / 2 + c;
}

int adj[50][50] = {};

int temp[50] = {};
int a[10];
int st[11];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	for (int i = 0; i < m; ++i) {
		int u; cin >> u;
		int v; cin >> v;
		int w; cin >> w;
		ad[u].pb({w, v});
	}
	for (int u = 1; u <= n; ++u) {
		sort(all(ad[u]));
		for (int i = 0; i < sz(ad[u]); ++i)
			mp[ad[u][i].se][{sz(ad[u]), i + 1}]++;
	}
	for (int u = 1; u <= n; ++u) {
		memset(temp, 0, sizeof(temp));
		for (auto re : mp[u]) {
			if (re.se > 1)
				ss[re.fi.fi].insert(re.fi.se);
			temp[state(re.fi.fi, re.fi.se)] = 1;
			// print(state(re.fi.fi, re.fi.se));
		}
		for (int i = 0; i < 50; ++i) {
			for (int j = i + 1; j < 50; ++j) {
				if (temp[i] && temp[j]) {
					adj[i][j] = 1;
					adj[j][i] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= k; ++i)
		for (int c : ss[i])
			adj[state(i, c)][state(i, c)] = 1;
	// for (int i = 1; i <= k; ++i) {
	// 	for (int j = 1; j <= k; ++j) {
	// 		cout << adj[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	iota(a, a + k, 0);
	int cnt = 0;
	int tcntr = 0;
	do {
		tcntr++;
		for (int i = 1, cntr = tcntr; i <= k; ++i) {
			st[i] = cntr % i + 1;
			cntr /= i;
		}
		bool ok = 1;
		for (int i = 1; i <= k && ok; ++i) {
			int sti = state(i, st[i]);
			for (int j = 1; j <= k && ok; ++j) {
				int stj = state(j, st[j]);
				if (adj[sti][stj]) {
					ok = 0;
				}
			}
		}
		if (ok) {
			cnt++;
			// print(pair(st, k + 1));
		} else {

		}
	} while(next_permutation(a, a + k));
	cout << cnt << '\n';
}