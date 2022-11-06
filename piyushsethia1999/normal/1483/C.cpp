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

const int N = 300005;
const int MAXN = 2 * N;
int seg[MAXN];

void update(int i, int val) {
	for (seg[i += N] = val; i > 1; i >>= 1) seg[i >> 1] = max(seg[i], seg[i ^ 1]);
}

int query(int l, int r) {
	r++; int a = -infl;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (r & 1) a = max(a, seg[--r]);
		if (l & 1) a = max(a, seg[l++]);
	}
	return a;
}

int h[300005];
int b[300005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < MAXN; ++i) seg[i] = -infl;
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	update(0, 0);
	stack<pair<int, int> > st;
	set<pii> ss;
	int ans;
	for (int i = 1; i <= n; ++i) {
		while (!st.empty() && h[st.top().se] > h[i]) {
			ss.erase(st.top());
			st.pop();
		}
		int j = 1;
		if (!st.empty()) j = st.top().se + 1;
		int dpn = query(j - 1, i - 1);
		pii p = {dpn + b[i], i};
		st.push(p);
		ss.insert(p);
		update(i, ss.rbegin()->fi);
		// print(st);
		print(ss.rbegin()->fi);
	}
	cout << ss.rbegin()->fi;
}