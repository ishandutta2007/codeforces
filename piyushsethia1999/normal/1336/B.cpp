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

int res(int a, int b, int c) {
	return ((a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a));
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int r; cin >> r;
		int g; cin >> g;
		int b; cin >> b;
		vi rr(r);
		vi gg(g);
		vi bb(b);
		for (int i = 0; i < r; ++i) cin >> rr[i];
		for (int i = 0; i < g; ++i) cin >> gg[i];
		for (int i = 0; i < b; ++i) cin >> bb[i];
		sort(rr.begin(), rr.end());
		sort(gg.begin(), gg.end());
		sort(bb.begin(), bb.end());
		int mi = 3 * 1000000000000000000ll;
		for (int i = 0; i < r; ++i) {
			if ((upper_bound(all(gg), rr[i])) != gg.begin() && lower_bound(all(bb), rr[i]) != bb.end())
				mi = min(mi, res(rr[i], *(upper_bound(all(gg), rr[i]) - 1), *lower_bound(all(bb), rr[i])));
			if ((upper_bound(all(bb), rr[i])) != bb.begin() && lower_bound(all(gg), rr[i]) != gg.end())
				mi = min(mi, res(rr[i], *(upper_bound(all(bb), rr[i]) - 1), *lower_bound(all(gg), rr[i])));
		}
		for (int i = 0; i < g; ++i) {
			if ((upper_bound(all(rr), gg[i])) != rr.begin() && lower_bound(all(bb), gg[i]) != bb.end())
				mi = min(mi, res(gg[i], *(upper_bound(all(rr), gg[i]) - 1), *lower_bound(all(bb), gg[i])));
			if ((upper_bound(all(bb), gg[i])) != bb.begin() && lower_bound(all(rr), gg[i]) != rr.end())
				mi = min(mi, res(gg[i], *(upper_bound(all(bb), gg[i]) - 1), *lower_bound(all(rr), gg[i])));
		}
		for (int i = 0; i < b; ++i) {
			if ((upper_bound(all(rr), bb[i])) != rr.begin() && lower_bound(all(gg), bb[i]) != gg.end())
				mi = min(mi, res(bb[i], *(upper_bound(all(rr), bb[i]) - 1), *lower_bound(all(gg), bb[i])));
			if ((upper_bound(all(gg), bb[i])) != gg.begin() && lower_bound(all(rr), bb[i]) != rr.end())
				mi = min(mi, res(bb[i], *(upper_bound(all(gg), bb[i]) - 1), *lower_bound(all(rr), bb[i])));
		}
		cout << mi << "\n";
	}
}