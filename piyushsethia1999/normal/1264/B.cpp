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

int getnext(std::vector<int> v, int c, bool fl) {
	if (c == 0) return 1;
	if (c == 3) return 2;
	if (c == 1) {
		if (fl) {
			if (v[0] > 0) return 0;
			return 2;
		} else {
			if (v[2] > 0) return 2;
			return 0;
		}
	}
	if (fl) {
		if (v[1] > 0) return 1;
		return 3;
	} else {
		if (v[3] > 0) return 3;
		return 1;
	}
	return -1;
}

void start(std::vector<int> v, int c, bool fl) {
	if (!v[c]) return;
	int cn = v[0] + v[1] + v[2] + v[3];
	string s = "";
	while (true) {
		v[c]--;
		cn--;
		s += '0' + c;
		s += ' ';
		// print(v, cn, c);
		if (!cn) {
			cout << "YES" << '\n';
			cout << s << '\n';
			exit(0);
		}
		c = getnext(v, c, fl);
		if (v[c] == 0) return;
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	std::vector<int> v(4);
	for (int i = 0; i < 4; ++i) cin >> v[i];
	start(v, 0, 1);
	start(v, 1, 1);
	start(v, 2, 0);
	start(v, 3, 0);
	start(v, 2, 1);
	start(v, 3, 1);
	start(v, 0, 0);
	start(v, 1, 0);
	cout << "NO" << '\n';
}