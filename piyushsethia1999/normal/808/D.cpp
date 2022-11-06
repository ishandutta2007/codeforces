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

int a[100004];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int to = 0;
	multiset<int> m1, m2;
	for (int o = 0; o < n; o++) { cin >> a[o]; to += a[o]; m1.insert(a[o]); }
	if (to & 1) {
		cout << "NO" << '\n';
		return 0;
	} 
	int su = 0;
	for (int i = 0; i < n; ++i) {
		if (m1.find((to - su) / 2) != m1.end() || m2.find((su - to) / 2) != m2.end()) {
			cout << "YES" << '\n';
			return 0;
		}
		su += a[i];
		to -= a[i];
		m1.erase(m1.find(a[i]));
		m2.insert(a[i]);
	}
	if (m1.find((to - su) / 2) != m1.end() || m2.find((su - to) / 2) != m2.end()) {
		cout << "YES" << '\n';
		return 0;
	}
	cout << "NO" << '\n';
}