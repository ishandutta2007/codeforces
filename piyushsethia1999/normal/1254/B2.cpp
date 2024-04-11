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


inline int val(int n, int p, int nn) {
	int mid = (n + 1) / 2;
	int l = p + 1;
	int r = p + nn;
	if (mid <= r && mid >= l) {
		return (l - mid + r - mid);
	} else if(mid <= l) {
		return (r - l + 1);
	}
	return -(r - l + 1);
}

int get(int p, std::vector<pair<int, int>> v) {
	// print(p);
	if (p == 2) {
		int la = -1;
		int tt = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (la != -1) {
				tt += (v[i].fi - la);
				v[i].se--;
			}
			v[i].se %= p;
			if (v[i].se) {
				la = v[i].fi;
			} else {
				la = -1;
			}
		}
		return tt;
	}
	int n = v.size();
	int tt = 0;
	int j = 0;
	int rem = 0;
	for (int i = 0; i < n; ++i) {
		if (rem > 0) {
			int mi = min(p - rem, v[i].se);
			v[i].se -= mi;
			tt += val(p, rem, mi) * v[i].fi;
			rem += mi;
			if (rem == p) rem = 0;
		}
		if (v[i].se) {
			v[i].se %= p;
			rem = v[i].se;
			tt += val(p, 0, v[i].se) * v[i].fi;
			v[i].se = 0;
		}
	}
	return tt;
}
int a[1000005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	std::vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) cin >> a[i];
	int cn = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i]) {
			cn += a[i];
			v.pb({i, a[i]});
		}
	}
	if (cn == 1) {
		cout << -1;
		return 0;
	}
	std::vector<int> pr;
	for (int i = 2; i * i <= cn; ++i) {
		if (cn % i == 0) {
			pr.pb(i);
			while (cn % i == 0) cn /= i;
		}
	}
	if (cn > 1) pr.pb(cn);
	int to = 2000000000000000000ll;
	for (int p : pr) {
		to = min(get(p, v), to);
	}
	cout << to << '\n';
}