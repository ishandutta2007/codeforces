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
const int mod = 998244353;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }
int powm(int a, int b) { int res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }

set<int> s;
int P[200005];
int PI[200005];
int RPI[200005];
int p[200005];
int get(int l, int r) {
	return ((P[r] - P[l - 1]) % mod) * (RPI[r]) % mod;
}

void pre(int n) {
	int hun = powm(100, mod - 2);
	for (int i = 0; i <= n; ++i)
		p[i] = p[i] * hun % mod;
	PI[0] = 1;
	for (int i = 1; i <= n; ++i)
		PI[i] = PI[i - 1] * p[i] % mod;
	RPI[n] = powm(PI[n], mod - 2);
	for (int i = n - 1; i >= 0; --i)
		RPI[i] = RPI[i + 1] * p[i + 1] % mod;
	P[0] = 0;
	for (int i = 1; i <= n; ++i)
		P[i] = (P[i - 1] + PI[i - 1]) % mod;
}

int ans = 0;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	s.insert(1);
	p[0] = 100;
	int n; cin >> n;
	s.insert(n + 1);
	int q; cin >> q;
	for (int i = 1; i <= n; ++i) cin >> p[i];
	pre(n);
	ans = get(1, n);
	// q = 0;
	for (int i = 0; i < q; ++i) {
		int pp; cin >> pp;
		if (s.find(pp) == s.end()) {
			auto it = s.lower_bound(pp);
			int r = *it;
			int l = *(--it);
			ans -= get(l, r - 1);
			ans += get(l, pp - 1);
			ans += get(pp, r - 1);
			s.insert(pp);
		} else {
			s.erase(pp);
			auto it = s.lower_bound(pp);
			int r = *it;
			int l = *(--it);
			ans += get(l, r - 1);
			ans -= get(l, pp - 1);
			ans -= get(pp, r - 1);
		}
		ans %= mod;
		ans += mod;
		ans %= mod;
		cout << ans << '\n';
	}
}