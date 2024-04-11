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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
#define piii pair<int, pair<int, int>>
oset s[10014];
piii a[100004];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int k; cin >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i].fi >> a[i].se.fi >> a[i].se.se;
	sort(a, a + n);
	priority_queue<pii, std::vector<pii>, greater<pii> > pq;
	pq.push({10000000000ll, 10000000000});
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		while (pq.top().fi < a[i].fi) {
			auto p = pq.top();
			int ii = p.se;
			s[a[ii].se.se].erase({-a[ii].fi, -ii});
			pq.pop();
		}
		for (int j = max(1ll, a[i].se.se - k); j <= a[i].se.se + k; ++j)
			cnt += s[j].order_of_key({-(a[i].fi - a[i].se.fi), 1});
		s[a[i].se.se].insert({-a[i].fi, -i});
		pq.push({a[i].fi + a[i].se.fi, i});
	}
	cout << cnt;
}