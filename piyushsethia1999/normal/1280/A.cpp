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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	while (t--) {
		int x; cin >> x;
		string s; cin >> s;
		int l = 0;
		int l2 = sz(s);
		int lri = sz(s);
		int lle = 0;
		int val = 0;
		while (sz(s) < x) {
			l++;
			lle++;
			int l1 = (s[l - 1] - '0');
			val = l1;
			lri--;
			lri = lri * l1 % mod;
			int len = l + (sz(s) - l) * l1;
			if (len >= x) {
				string rig = s.substr(l);
				l1--;
				while (l1 && sz(s) < x) {
					s += rig;
					l1--;
				}
			} else {
				string rig = s.substr(l);
				l1--;
				while (l1) {
					s += rig;
					l1--;
				}
			}
			// print(s);
			// print(lle, lri, val);
		}
		while (l < x) {
			l++;
			lle++;
			int l1 = ((s[l - 1] - '0')) % mod;
			val = l1;
			lri--;
			lri = (lri * l1) % mod;
			// print(lle, lri, val);
		} 
		cout << ((lri + lle) % mod + mod) % mod << '\n';
	}
}