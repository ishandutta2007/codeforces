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
int a[6];
int b[100005];
int in[100005];
int c[100005][7];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	for (int i = 0; i < 6; ++i) cin >> a[i];
	sort(a, a + 6);
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> b[i];
	sort(b, b + n);
	vi va;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 6; ++j) 
			va.pb(c[i][5 - j] = b[i] - a[j]);
	for (int i = 0; i < n; ++i) 
		c[i][6] = 2 * infi;
	int len = infi;
	sort(all(va));
	va.resize(unique(all(va)) - va.begin());
	priority_queue<pii> pq;
	multiset<int> mm;
	// print(pair(a, 6));
	// print(pair(b, n));
	for (int i = 0; i < n; ++i) {
		// print(pair(c[i], 7));
		pq.push({-c[i][in[i]], i});
		mm.insert(-c[i][in[i]]);
	}
	for (int i = 0; i < va.size(); ++i) {
		int val = va[i];
		// print(val);
		// print(mm);
		while (-pq.top().fi < val) {
			auto pp = pq.top(); pq.pop();
			mm.erase(-c[pp.se][in[pp.se]]);
			in[pp.se]++;
			pq.push({-c[pp.se][in[pp.se]], pp.se});
			mm.insert(-c[pp.se][in[pp.se]]);
		}
		// print(mm);
		len = min(len, -*mm.begin() - val);
	}
	cout << len << '\n';
}