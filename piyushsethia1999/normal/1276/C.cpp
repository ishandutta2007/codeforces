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
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }


int a[400005];
int fr[400005];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	std::vector<int> v;
	for (int i = 0; i < n; ++i) cin >> a[i], v.pb(a[i]);
	sort(v.begin(), v.end());
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(all(v), a[i]) - v.begin();
		fr[a[i]]++;
	}
	std::vector<pii> aa;
	int su = n;
	for (int i = 0; i < v.size(); ++i)
		aa.pb({fr[i], i});
	sort(aa.rbegin(), aa.rend());
	print(aa);
	int i = 0;
	int sr = n;
	int ma = 0;
	int le = -1;
	int in = -1;
	for (int l = n; l >= 1; --l) {
		while (i < aa.size() && aa[i].fi >= l) {
			sr -= aa[i].fi;
			i++;
		}
		int br = i + sr / l;
		if (br < l) continue; 
		// print(br, l, br * l);
		if (br * l > ma) {
			ma = br * l;
			le = l;
			in = i;
		}
	}
	assert(le != -1);
	int l = le;
	std::vector<std::vector<int> > gr(ma / l, std::vector<int> (l));
	print(in);
	for (int i = 0; i < in; ++i) {
		for (int j = 0; j < l; ++j) 
			gr[i][j] = aa[i].se;
		print(gr[i]);
	}
	std::vector<int> v1;
	int jn = in;
	while (in < aa.size()) {
		for (int i = 0; i < aa[in].fi; ++i) 
			v1.pb(aa[in].se);
		in++;
	}
	in = jn;
	// print(v1);
	// print(ma, l);
	// print(in, ma / l);
	int kn = 0;
	for (int i = in; i < (ma / l); ++i) {
		// print(i);
		for (int j = 0; j < l; ++j) {
			// print(v1[kn]);
			gr[i][j] = v1[kn++];
		}
	}
	print(gr);
	cout << ma << '\n';
	cout << l << " " << ma / l << '\n';
	for (int i = 0; i < l; ++i) {
		for (int k = 0; k < ma / l; ++k) {
			int j = (ma / l - i + k) % (ma / l);
			cout << v[(gr[j][i])] << ' ';
		}
		cout << '\n';
	}
}