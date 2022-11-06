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
int n, k;

void add(string& s) {
	int in = s.size() - 1;
	while (s[in] == '9') {
		s[in--] = '0';
	}
	s[in] = s[in] + 1;
}

void prin(string s) {
	// print(s);
	for (int i = 0; i < n; ++i) {
		cout << s[i % k];
	}
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> n;
	cin >> k;
	string s; cin >> s;
	string ss = s.substr(0, k);
	cout << n << '\n';
	for (int i = 0; i < n / k; ++i) {
		if (s.substr(i * k, k) != ss) {
			if (s.substr(i * k, k) < s) {
				prin(ss);
			} else {
				add(ss);
				prin(ss);
			}
		}
	}
	if (n % k != 0) {
		string tt = s.substr((n/k)*k);
		string st = ss.substr(0, sz(tt));
		if (tt <= st) {

		} else {
			add(ss);
		}
	}
	prin(ss);
}