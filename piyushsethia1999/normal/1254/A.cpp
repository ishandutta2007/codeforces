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

string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZqwertyuiopasdfghjklzxcvbnm1234567890";
string a[104];
int n, m, k;
int pox = 0, poy = 0;
int dir = 1;

bool get(char ch) {
	// print(ch, pox, poy);
	bool ok = (a[pox][poy] == 'R');
	a[pox][poy] = ch;
	poy += dir;
	if (poy < m && poy >= 0) return ok;
	poy -= dir;
	pox++;
	dir = -dir;
	return ok;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	// print(s.size());
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		int cn = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			// print(a[i]);
			for (int j = 0; j < m; ++j) {
				if (a[i][j] == 'R') {
					cn++;
				}
			}
		}
		// print(1);
		int cn1 = cn / k;
		int r = cn % k;
		dir = 1;
		cn1++;
		pox = 0, poy = 0;
		// print(1);
		for (int i = 0; i < r; ++i) {
			int to = 0;
			while (to < cn1) {
				if (get(s[i])) {
					to++;
				}
			} 	
		}
		// print(1);
		cn1--;
		// print(1);
		for (int i = r; i < k; ++i) {
			int to = 0;
			while (to < cn1) {
				if (get(s[i])) {
					to++;
				}
			}
		}
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < m; ++j) 
				if (a[i][j] == '.')
					a[i][j] = s[k - 1]; 
		// print(1);
		for (int i = 0; i < n; ++i) 
			cout << a[i] << '\n';
	}
}