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

int a[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	set<int> s;
	int cntr = 0;
	vector<pii> v;
	bool ok = 1;
	map<int, int> mp;
	set<int> only3;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 0) {

		} else if (a[i] == 1) {
			s.insert(cntr);
			mp[cntr] = i;
			v.pb({i, cntr++});
		} else if (a[i] == 2) {
			if (!s.empty()) {
				only3.insert(*s.begin());
				mp[*s.begin()] = i;
				v.pb({i, *s.begin()});
				s.erase(s.begin());
			} else {
				ok = 0;
			}
		} else {
			if (!only3.empty()) {
				only3.insert(cntr);
				mp[cntr] = i;
				v.pb({i, cntr});
				v.pb({mp[*only3.begin()], cntr++});
				only3.erase(only3.begin());
			} else if (!s.empty()) {
				only3.insert(cntr);
				mp[cntr] = i;
				v.pb({i, cntr});
				v.pb({mp[*s.begin()], cntr++});
				s.erase(s.begin());
			} else {
				ok = 0;
			}
		}
	}
	if (ok) {
		cout << v.size() << '\n';
		for (int i = 0; i < v.size(); ++i) {
			cout << n - v[i].se << " " << v[i].fi + 1 << '\n';
		}
	} else {
		cout << -1 << '\n';
	}
}