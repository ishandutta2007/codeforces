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

int a[1000006];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int k; cin >> k;
		for (int i = 0; i < n; ++i) cin >> a[i];
		bool ok = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == k) {
				ok = 1;
				break;
			} 
		} 
		if (!ok) {
			cout << "no" << '\n';
			continue;
		}
		if (n == 1) {
			cout << "yes" << '\n';
			continue;
		} 
		for (int i = 0; i < n; ++i) {
			if (a[i] >= k) {
				a[i] = 1;
			} else {
				a[i] = 0;
			}
		}
		ok = 0;
		int la = -100000000ll;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 1) {
				if (i - la - 1 < 2) {
					ok = 1;
					break;
				}
				la = i;
			} 
		}
		if (ok) {
			cout << "yes" << '\n';
		} else {
			cout << "no" << '\n';
		}
	}
}