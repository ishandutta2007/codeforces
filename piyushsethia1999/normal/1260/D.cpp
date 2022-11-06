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
int a[300000];

struct trap
{
	int l, r, d;
	bool operator<(trap& a) {
		return a.d > d;
	}
} tr[300000];

int m, k, t, n;

bool che(int mm) {
	// print(mm);
	std::vector<trap> v;
	int mi = a[mm - 1];
	for (int i = 0; i < k; ++i) {
		if (tr[i].d > mi) {
			v.pb(tr[i]);
		}
	}
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.l < b.l;
	});
	std::vector<trap> tt;
	int l = 0, r = 0;
	int ttt = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i].r <= r) {
			continue;
		}
		// if(ok) print(ttt, v[i].l, v[i].r, l, r);
		if (v[i].l > r) {
			ttt += (v[i].l - l + 2 * (r - (l - 1)));
			l = v[i].l;
			// if (ok) print(1);
		}
		// print(ttt);
		r = max(r, v[i].r);
	}
	// print(ttt, l, r, n + 1);
	ttt -= 3;
	ttt += (n + 1 - (l - 1) + 2 * (r - (l - 1)));
	// print(mm, ttt, t);
	// exit(0);
	return (ttt <= t);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> m >> n >> k >> t;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < k; ++i)
		cin >> tr[i].l >> tr[i].r >> tr[i].d;
	sort(a, a + m, greater<int>());
	sort(tr, tr + k);
	int s = 0, e = m;
	while (s < e) {
		int mm = (s + e + 1) >> 1;
		if (che(mm)) {
			s = mm;
		} else {
			e = mm - 1;
		}
	} 
	cout << s << '\n';
}