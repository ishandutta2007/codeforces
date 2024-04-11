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

class DSU
{
public:
	int *parent;
	int n;
	DSU(int n) : n(n) { parent = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1; };
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	~DSU();
};

int DSU::root(int x) { return (parent[x] < 0 ? x : (parent[x] = root(parent[x]))); }

void DSU::merge(int x, int y)
{
	if ((x = root(x)) == (y = root(y))) return;
	if (parent[x] > parent[y]) swap(x, y);
	parent[x] += parent[y];
	parent[y] = x;
}

bool DSU::areInSame(int x, int y) { return (root(x) == root(y)); }

DSU::~DSU()
{
	delete parent;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int m; cin >> m;
		int a; cin >> a; a--;
		int b; cin >> b; b--;
		if (a < b) swap(a, b); 
		DSU d(n);
		std::vector<pii> ex;
		for (int i = 0; i < m; ++i) {
			int u; cin >> u; u--;
			int v; cin >> v; v--;
			if (u < v)
				swap(u, v);
			// print(u, v);
			if (u != a && u != b && v != a && v != b) {
				// print(u, v, 1);
				d.merge(u, v);
			}
			else if(u != a || v != b) {
				// print(u, v, 2);
				ex.pb({u, v});
			}
		}
		set<int> s;
		set<int> r;
		set<int> in;
		for (auto &e : ex) {
			if (e.fi != a && e.fi != b) swap(e.fi, e.se);
			e.se = d.root(e.se);
			if (e.fi == a)
				s.insert(e.se);
		}
		// print(ex);
		for (auto e : ex) {
			if (e.fi == b) {
				r.insert(e.se);
				// print(e.se);
				if (s.find(e.se) != s.end())  {
					// print(e.se);
					in.insert(e.se);
				}
			}
		}
		// print(s);
		// print(r);
		// print(in);
		int i1 = 0;
		for (int i : s) {
			if (in.find(i) == in.end()) {
				i1 += (-d.parent[i]);
			}
		}
		int i2 = 0;	
		for (int i : r) {
			if (in.find(i) == in.end()) {
				i2 += (-d.parent[i]);
			}
		}
		cout << i1 * i2 << '\n';
	}
}