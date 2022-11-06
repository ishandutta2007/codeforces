#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
//const int mod=998244353;
const int mod = 1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

int a[300005];
int pos[200005];
const int N = 200005;
int seg[400005];
int seg2[400005];
int que(int l, int r) {
	int ans = 0;
	r++;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans += seg[l++];
		if(r & 1) ans += seg[--r];
	}
	return ans;
}
int que2(int l, int r) {
	int ans = 0;
	r++;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if(l & 1) ans += seg2[l++];
		if(r & 1) ans += seg2[--r];
	}
	return ans;
}
void upd(int i) {
	int ii = i;
	for (seg[i += N] = ii; i > 1; i >>= 1) {
		seg[i >> 1] = seg[i] + seg[i ^ 1];
	}
}
void upd2(int i) {
	int ii = i;
	for (seg2[i += N] = 1; i > 1; i >>= 1) {
		seg2[i >> 1] = seg2[i] + seg2[i ^ 1];
	}
}

int inversions(int i) {
	int qq = que2(pos[i], N - 1);
	upd2(pos[i]);
	return qq;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) {
		pos[a[i]] = i; 
	}
	oset s;
	int aa = 0;
	for (int i = 1; i <= n; ++i) {
		s.insert(pos[i]);
		int medpos = *s.find_by_order(i / 2);
		upd(pos[i]);
		int ans = medpos * (i / 2 + 1) - que(0, medpos)
		 + que(medpos + 1, N - 1) - (i - 1 - (i / 2)) * medpos;
		aa += inversions(i);
		ans += aa;
		ans -= ((i / 2) * (i / 2 + 1)) / 2;
		ans -= (((i - 1) / 2) * ((i - 1) / 2 + 1)) / 2;
		cout << ans << " ";
	}
}