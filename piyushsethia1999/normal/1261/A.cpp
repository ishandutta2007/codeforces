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

std::vector<pair<int, int> > v;
string s;

void replace(int j, char c) {
	for (int i = j + 1; i < sz(s); ++i) 
		if (s[i] == c) {
			// print(j + 1, i + 1);
			// print(s.substr(0, j), s.substr(j, i - j + 1), s.substr(i + 1));
			v.pb({j + 1, i + 1});
			string g = s.substr(j, i - j + 1);
			reverse(all(g));
			s = s.substr(0, j) + g + s.substr(i + 1);
			return;
		}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	while (t--) {
		v.clear();
		int n, k;
		cin >> n >> k >> s;
		k--;
		// print(n, k, s);
		for (int i = 0; i < k; ++i) {
			if (s[2 * i] != '(') {
				// print(s[2 * i]);
				replace(2 * i, '(');
			}
			if (s[2 * i + 1] != ')') {
				// print(s[2 * i + 1]);
				replace(2 * i + 1, ')');
			}
		}
		// print(s);
		for (int i = 2 * k; i <= (n + 2 * k - 1) / 2; ++i) {
			if (s[i] != '(') {
				replace(i, '(');
			}
		}
		print(s);
		cout << v.size() << '\n';
		for (auto p : v) {
			cout << p.fi << " " << p.se << "\n";
		}
	}
}