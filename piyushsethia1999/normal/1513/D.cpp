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

class DSU
{
public:
	int *parent;
	int *mi;
	int n;
	DSU(int n) : n(n) { parent = new int[n]; mi = new int[n]; for (int i = 0; i < n; ++i) parent[i] = -1, mi[i] = i; };
	void merge(int x, int y);
	int root(int x);
};

int DSU::root(int x) { 
	return (parent[x] < 0 ? x : (parent[x] = root(parent[x])));
}
void DSU::merge(int x, int y) {
	if ((x = root(x)) == (y = root(y))) return;
	if (parent[x] > parent[y]) swap(x, y);
	parent[x] += parent[y];
	parent[y] = x;
	mi[x] = max(mi[x], mi[y]);
}

const int N = 200004;
const int MAXN = 2 * N;
int seg[MAXN];

void build() {
	for (int i = N - 1; i > 0; --i) seg[i] = __gcd(seg[i << 1], seg[(i << 1) | 1]);
}

int query(int l, int r) {
	r++; int a = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (r & 1) a = __gcd(a, seg[--r]);
		if (l & 1) a = __gcd(a, seg[l++]);
	}
	return a;
}

template<typename T>
class ST
{
	std::vector<std::vector<T> > table;
	T (*Union)(T, T b);
public:
	ST(std::vector<T>& a, T (*u)(T, T));
	T query(int l , int r);
};
template<typename T>
ST<T>::ST(std::vector<T>& a, T (*u)(T, T)) {
	Union = u;
	int n = a.size();
	int k = log2(n);
	table.resize(n, std::vector<T> (k + 1));
	for (int i = 0; i < n; ++i)
		table[i][0] = a[i];
	for (int j = 1; j <= k; ++j)
		for (int i = 0; i < (n + 1 - (1 << j)); ++i)
			table[i][j] = Union(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}
template<typename T>
T ST<T>::query(int l, int r)
{
	int m = log2(r - l + 1);
	return this->Union(table[l][m], table[r - (1 << m) + 1][m]);
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int p; cin >> p;
		vi vv(n);
		// for (int i = 0; i < n; ++i) cin >> seg[i + N];
		// for (int i = n; i < N; ++i) seg[i + N] = 0;
		for (int i = 0; i < n; ++i) cin >> vv[i];
		// build();
		ST<int> st(vv, __gcd);
		vector<pii> v;
		for (int i = 0; i < n; ++i) {
			// v.pb({seg[i + N], i});
			v.pb({vv[i], i});
		}
		sort(all(v));
		int su = 0;
		DSU d(n);
		for (int i = 0; i < n; ++i) {
			if (v[i].fi < p) {
				// print(v[i]);
				int in = v[i].se;
				int s = in, e = n - 1;
				while (s < e) {
					int m = (s + e + 1) / 2;
					// if (query(in, m) == v[i].fi) {
					if (st.query(in, m) == v[i].fi) {
						s = m;
					} else {
						e = m - 1;
					}
				}
				int r = s;
				s = 0, e = in;
				while (s < e) {
					int m = (s + e) / 2;
					// if (query(m, in) == v[i].fi) {
					if (st.query(m, in) == v[i].fi) {
						e = m;
					} else {
						s = m + 1;
					}
				}
				int l = s;
				while (l < r) {
					int ma = d.mi[d.root(l)];
					if (ma >= r) break;
					d.merge(l, ma + 1);
					su += v[i].fi; 
					l = ma + 1;
				}
			}
		}
		// print(su, p);/
		for (int i = 0; i < n - 1; ++i) {
			if (d.root(i) != d.root(i + 1)) {
				su += p;
			} 
		}
		cout << su << '\n';
	}
}