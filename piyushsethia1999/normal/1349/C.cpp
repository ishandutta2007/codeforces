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
// #define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<short int,short int>
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

string a[1005];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;
int v[1004][1004];

bool valid(int x, int y) {
	return !(x < 0 || y < 0 || x >= n || y >= m);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cin >> n;
	cin >> m;
	int t; cin >> t;
	for (int i = 0; i < n; ++i) cin >> a[i];
	queue<pii> q;
	// for (int i = 0; i < 1000000; ++i) q.push({1, 1});
	memset(v, 0x3f, sizeof(v));
	// print(1);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) {
			char c = a[i][j];
			for (int k = 0; k < 4; ++k) {
				int xx = i + dx[k];
				int yy = j + dy[k];
				if (valid(xx, yy) && a[xx][yy] == c)
					v[xx][yy] = v[i][j] = 0;
			}
		}
	// print(1);
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j) 
			if (v[i][j] == 0)
				q.push({i, j});
	// print(1);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int i = p.fi;
		int j = p.se;
		for (int k = 0; k < 4; ++k) {
			int xx = i + dx[k];
			int yy = j + dy[k];
			if (valid(xx, yy) && v[xx][yy] == infi) {
				v[xx][yy] = v[i][j] + 1;
				q.push({xx, yy});
			}
		}
	}
	// print(1);
	while (t--) {
		int i; cin >> i; i--;
		int j; cin >> j; j--;
		long long p; cin >> p;
		if (v[i][j] == infi) {
			cout << a[i][j] << "\n";
		} else {
			if (v[i][j] < p) {
				p -= v[i][j];
				if (p & 1) {
					if (a[i][j] == '1') {
						cout << '0' << '\n';
					} else {
						cout << '1' << '\n';
					}
				} else {
					cout << a[i][j] << "\n";
				}
			} else {
				cout << a[i][j] << "\n";
			}
		}
	}
}