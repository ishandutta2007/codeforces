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

int a[200005];
int pos[200005];
int ans[200005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	std::vector<pii> v;
	for (int i = 0; i < n; ++i) {
		v.pb({a[i], i});
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return (a.fi > b.fi || (a.fi == b.fi && a.se < b.se));
	});
	int m;
	oset s;
	cin >> m;
	std::vector<pair<int, int> > q(m);
	for (int i = 0; i < m; ++i) {
		cin >> q[i].fi >> pos[i];
		pos[i]--;
		q[i].se = i;
	}
	sort(q.begin(), q.end());
	int j = 0;
	for (int l = 1; l <= n; ++l) {
		int i = l - 1;
		s.insert(v[i].se);
		while (j < m && q[j].fi == l) {
			ans[q[j].se] = a[*s.find_by_order(pos[q[j].se])];
			j++;
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
}