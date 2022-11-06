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

int a[400000];
int aa[400000];
vector<pii> qq[400000];
int ans[400000];

const int N = 300004;
const int MAXN = 4 * N;
int lazy[MAXN];
pii seg[MAXN];

void build(int no, int s, int e) {
	if (s == e) {
		seg[no] = {aa[s], s};
		return;
	}
	int m = (s + e) / 2;
	build(no * 2, s, m);
	build(no * 2 + 1, m + 1, e);
	seg[no] = min(seg[no * 2], seg[no * 2 + 1]);
}

void push(int no) {
	if (lazy[no]) {
		lazy[no * 2 + 1] += lazy[no];
		lazy[no * 2] += lazy[no];
		seg[no * 2 + 1].fi -= lazy[no];
		seg[no * 2].fi -= lazy[no];
		lazy[no] = 0;
	}
}

void update(int no, int s, int e, int l, int r) {
	if (l > r || s > r || l > e) return;
	if (l <= s && e <= r) {
		seg[no].fi--;
		lazy[no]++;
		// print(s, e, seg[no]);
		return;
	}
	push(no);
	int m = (s + e) / 2;
	update(no * 2, s, m, l, r);
	update(no * 2 + 1, m + 1, e, l, r);
	seg[no] = min(seg[no * 2], seg[no * 2 + 1]);
}

void update(int no, int s, int e, int l) {
	if (s > l || l > e) return;
	if (l <= s && e <= l) {
		seg[no] = {infi, l};
		return;
	}
	push(no);
	int m = (s + e) / 2;
	update(no * 2, s, m, l);
	update(no * 2 + 1, m + 1, e, l);
	seg[no] = min(seg[no * 2], seg[no * 2 + 1]);
}

pii query(int no, int s, int e, int l, int r) {
	if (l > r || s > r || l > e) return {infi, 0};
	if (l <= s && e <= r)
		return seg[no];
	push(no);
	int m = (s + e) / 2;
	return min(query(no * 2, s, m, l, r), query(no * 2 + 1, m + 1, e, l, r));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int q; cin >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 0; i < q; ++i) {
		int x; cin >> x;
		int y; cin >> y;
		qq[x].pb({i, n - y});
	}
	int to = 0;
	oset ss;
	for (int i = 1; i <= n; ++i) {
		if (i - a[i] >= 0 && i - a[i] <= to) {
			ss.insert(i);
			aa[i] = to - (i - a[i]);
			to++;
		} else {
			aa[i] = infi;
		}
	}
	// print(pair(aa + 1, n));
	// const infii = infi / 2;
	build(1, 1, n);
	for (int x = 0; x < n; ++x) {
		// print(ss);
		for (auto p : qq[x]) {
			ans[p.fi] = ss.order_of_key(p.se + 1);
			// print(p, ans[p.fi]);
		}
		if (ss.find(x + 1) != ss.end()) {
			ss.erase(x + 1);	
			update(1, 1, n, x + 1);
			update(1, 1, n, x + 1, n);
			while (seg[1].fi < 0) {
				// print(seg[1]);
				ss.erase(seg[1].se);
				int re = seg[1].se;
				update(1, 1, n, re);
				update(1, 1, n, re, n);
			}
		} 
	}
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}