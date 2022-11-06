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

vector<pii> v;

int l[100005];
int r[100005];
int a[100005];
int p[100005];

int cnt = 0;

void dfs(int root, int s, int e) {
	// print(root, s, e);
	if (s >= e || root == -1) return;
	// print(a[root]);
	auto iter = lower_bound(v.begin() + s, v.begin() + e, pii(a[root], 0ll));
	dfs(l[root], s, iter - v.begin());
	if (iter->fi == a[root] && iter - v.begin() < e) {
		dfs(r[root], iter - v.begin() + 1, e);
		cnt += iter->se;
	} else
		dfs(r[root], iter - v.begin(), e);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> l[i] >> r[i];
		if (l[i] != -1)
			p[l[i]] = i;
		if (r[i] != -1)
			p[r[i]] = i;
	}
	int root = 0;
	for (int i = 1; i <= n && !root; ++i)
		if (p[i] == 0) root = i;
	vi aa;
	for (int i = 1; i <= n; ++i)
		aa.pb(a[i]);
	sort(aa.begin(), aa.end());
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (j + 1 < n && aa[j + 1] == aa[i]) j++;
		v.pb({aa[i], j - i + 1});
		i = j;
	}
	v.pb({1000000001ll, 0});
	// print(v);
	dfs(root, 0, v.size() - 1);
	cout << n - cnt << '\n';
}