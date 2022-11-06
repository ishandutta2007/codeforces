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
// #define int long long
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
int nex[100005];
int pre[100005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		set<int> s;
		for (int i = 0; i < n; ++i) {
			if (__gcd(a[i], a[(i + 1) % n]) == 1) {
				s.insert(i);
			}
			nex[i] = (i + 1) % n;
			pre[nex[i]] = i;
		}
		int i = 0;
		vector<int> v;
		while (!s.empty()) {
			auto it = s.lower_bound(i);
			if (it == s.end()) {
				i = 0; continue;
			}
			auto tbe = nex[*it];
			i = tbe;
			int pr = pre[i];
			int ne = nex[i];
			s.erase(pr);
			s.erase(i);
			nex[pr] = ne;
			pre[ne] = pr;
			v.pb(i + 1);
			if (pr != i && __gcd(a[pr], a[ne]) == 1) {
				s.insert(pr);
			}
		}
		cout << v.size() << " ";
		for (int i: v) {
			cout << i << " ";
		}
		cout << '\n';
	}
}