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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int k; cin >> k;
		string s; cin >> s;
		int in = 0;
		while (in < n && s[in] != 'W') in++;
		std::vector<int> tp;
		int to = 0; 
		for (int i = in; i < n; ++i) {
			if (s[i] == 'W') {
				if (i + 1 < n && s[i + 1] == 'W')
					to++;
				to++;
			} else {
				int j = i;
				while (j + 1 < n && s[j + 1] == 'L') j++;
				tp.pb(j - i + 1); 
				i = j;
			}
		}
		// print(to);
		if (tp.size() && s[n - 1] == 'L')
			tp.pop_back();
		if (to == 0) {
			cout << min(2 * n - 1, max(0ll, 2 * k - 1)) << '\n';
			continue;
		}
		sort(all(tp));
		// print(tp);
		int K = k;
		int ext = 0;
		for (int i = 0; i < tp.size(); ++i) {
			if (tp[i] <= k) {
				k -= tp[i];
				ext++;
			}
		}
		cout << min(2 * n - 1, to + K * 2 + ext) << '\n';
	}
}