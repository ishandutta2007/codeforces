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

const int N = 200004;
const int MAXN = 2 * N;
int seg[MAXN];

void update(int i, int val) {
	for(seg[i += N] = val; i > 1; i >>= 1) seg[i >> 1] = max(seg[i], seg[i ^ 1]);
}

int query(int l, int r) {
	if (l > r) return 0; 
	r++; int a = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (r & 1) a = max(a, seg[--r]);
		if (l & 1) a = max(a, seg[l++]);
	}
	return a;
}

int maxx[200005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vector<pii> a(n + 1);	
	int su = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].fi >> a[i].se;
		su += a[i].se;
	}
	sort(a.begin() + 1, a.end());
	int co = 0;
	update(n, n);
	for (int i = 1; i <= n; ++i)
		maxx[i] = max(maxx[i - 1], a[i].fi + a[i].se);
	for (int i = n - 1; i >= 1; --i) {
		int in = (upper_bound(a.begin() + 1, a.end(), pii(a[i].fi + a[i].se, infi)) - a.begin());
		int ma = max(i, query(i + 1, in - 1));
		update(i, ma);
		// print(i, ma);
	}
	int in = 1;
	while (in < n) {
		int ma = query(in, in);
		// print(ma);
		if (ma == n) break;
		in = ma;
		// print(a[in].se);
		co += a[in + 1].fi - maxx[in]; 
		in = ma + 1;
	} 
	cout << co + su << '\n';
}