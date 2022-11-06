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

int fact[100006];
int ifact[100006];

void pre() {
	fact[0] = 1;
	for (int i = 1; i <= 100005; ++i) {
		fact[i] = fact[i - 1] * i % mod;
	}
	ifact[100005] = powm(fact[100005], mod - 2);
	for (int i = 100004; i >= 0; --i) {
		ifact[i] = ifact[i + 1] * (i + 1) % mod;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	// print();
	pre();
	int n; cin >> n;
	std::map<int, int> mp;
	// print();
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int su = 0;
	// print();
	for (int i = 0; i < n; ++i) mp[a[i]]++, su += a[i];
	if (su % n != 0) {
		cout << 0 << '\n';
		return 0;
	}
	su /= n;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > su) {
	// print();
			cnt1++;
		} else if (a[i] < su) {
			cnt2++;
		}
	}
	int re = 1;
	// print();
	// print();
	for (auto mm : mp) {
		re = re * ifact[mm.se] % mod;
	}
	int ans = 0;
	if (cnt1 <= 1 || cnt2 <= 1) {
		ans = fact[n];
	} else {
		ans = fact[n] * (fact[cnt1] * fact[cnt2] % mod) % mod * ifact[cnt1 + cnt2] % mod * 2ll % mod;
	}
	ans = ans * re % mod;
	cout << ans << '\n';
}