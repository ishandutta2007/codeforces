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

vi u;
vi p;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int a; cin >> a;
	int b; cin >> b;
	int c; cin >> c;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int c; cin >> c;
		string s; cin >> s;
		if (s[0] == 'P') {
			p.pb(c);
		} else {
			u.pb(c);
		}
	}
	sort(u.begin(), u.end());
	sort(p.begin(), p.end());
	int cnt = 0, co = 0;
	int uu = 0;
	int pp = 0;
	while (a > 0 && uu < u.size()) {
		cnt++;
		a--;
		co += u[uu++];
	}
	// print(u, p, uu, co, pp);
	while (b > 0 && pp < p.size()) {
		cnt++;
		b--;
		co += p[pp++];
	}
	// print(u, p, uu, co, pp, b);
	// print(co);
	for (int i = pp; i < p.size(); ++i) u.pb(p[i]);
	sort(u.begin() + uu, u.end());
	while (c > 0 && uu < u.size()) {
		cnt++;
		c--;
		co += u[uu++];
	}
	cout << cnt << " " << co << '\n';
}