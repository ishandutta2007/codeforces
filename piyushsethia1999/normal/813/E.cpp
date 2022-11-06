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

int le[2000000];
int ri[2000000];
int seg[2000000];
int ro[100006];
int ti = 1;

void bui(int n, int s, int e) {
	if (s == e) {
		seg[n] = 1;
		return ;
	}
	le[n] = ti++;
	ri[n] = ti++;
	int m = (s + e) / 2;
	bui(le[n], s, m);
	bui(ri[n], m + 1, e);
	seg[n] = seg[le[n]] + seg[ri[n]];
}

int newn(int n, int s, int e, int rr) {
	if (e < rr || rr < s)
		return n;
	if (s == e) {
		int nn = ti++;
		seg[nn] = 0;
		return nn;
	}
	int m = (s + e) / 2;
	int nn = ti++;
	le[nn] = newn(le[n], s, m, rr);
	ri[nn] = newn(ri[n], m + 1, e, rr);
	seg[nn] = seg[le[nn]] + seg[ri[nn]];
	return nn;
}

int que(int n, int s, int e, int l, int r) {
	if (e < l || r < s) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = (s + e) / 2;
	return que(le[n], s, m, l, r) + que(ri[n], m + 1, e, l, r);  
}

int a[100004];
vi d[100004];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int k; cin >> k;
	for (int i = 0; i < n; ++i) cin >> a[i];
	bui(0, 0, n - 1);
	ro[0] = 0;
	d[a[0]].pb(0);
	for (int i = 1; i < n; ++i) {
		d[a[i]].pb(i);
		if (sz(d[a[i]]) > k)
			ro[i] = newn(ro[i - 1], 0, n - 1, d[a[i]][sz(d[a[i]]) - k - 1]);
		else
			ro[i] = ro[i - 1];
	}
	int q; cin >> q;
	int la = 0;
	while (q--) {
		int x; cin >> x;
		int y; cin >> y;
		x = (x + la) % n;
		y = (y + la) % n;
		if (x > y) swap(x, y);
		cout << (la = que(ro[y], 0, n - 1, x, y)) << '\n'; 
	}
}