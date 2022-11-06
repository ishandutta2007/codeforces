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
int a[200005];
int b[200005];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	vector<pii> a1, a2;
	int re = 0;
	for (int i = 0; i < n; ++i) {
		re += abs(a[i] - b[i]);
		if (a[i] > b[i]) {
			a1.pb({a[i], b[i]});
		} else {
			a2.pb({b[i], a[i]});
		}
	}
	int n1 = a1.size(), n2 = a2.size();
	sort(all(a1));
	sort(all(a2));
	int r = n2;
	int ma = infi;
	int ma1 = infi;
	int ans = 0;
	for (int i = n1 - 1; i >= 0; --i) {
		while (r - 1 >= 0 && a2[r - 1].fi >= a1[i].fi) {
			r--;
			ma = min(ma, a2[r].se);
		}
		ma1 = min(ma1, a1[i].se);
		ans = max(ans, a1[i].fi - max(ma1, ma));
	}
	print(ans);
	swap(a1, a2);
	swap(n1, n2);
	r = n2;
	ma = infi;
	ma1 = infi;
	
	for (int i = n1 - 1; i >= 0; --i) {
		while (r - 1 >= 0 && a2[r - 1].fi >= a1[i].fi) {
			r--;
			ma = min(ma, a2[r].se);
		}
		ma1 = min(ma1, a1[i].se);
		ans = max(ans, a1[i].fi - max(ma1, ma));
	}
	print(a1, a2, ans);
	cout << re - 2 * ans << '\n';
}