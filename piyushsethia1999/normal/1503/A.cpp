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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		if (s[0] != '1' || s.back() != '1') {
			cout << "NO" << '\n';
			continue;
		}
		int cn0 = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') 
				cn0++;
		}
		if (cn0 & 1) {
			cout << "NO" << '\n';
			continue;			
		} 
		int l = -1;
		string s1(n, '0');
		string s2(n, '0');
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				if (l == -1) {
					l = i;
				} else {
					s1[l] = s2[i] = ')';
					s1[i] = s2[l] = '(';
					l = -1;
				}
			} 
		}
		int op = n / 2 - cn0 / 2;
		// print(op);
		// print(s1, s2);
		for (int i = 0; i < n; ++i) {
			if (s1[i] == '0') {
				if (op) {
					s1[i] = s2[i] = '(';
					op--;
				}
				else {
					s1[i] = s2[i] = ')';
				}
			} 
		// print(s1, s2);
		}
		cout << "YES" << '\n';
		cout << s1 << '\n';
		cout << s2 << '\n';

	}
}