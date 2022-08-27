#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define ull unsigned long long 
using namespace std;
const int N = 1 << 20;
bool flg = false;
struct frac {
	ll x, y; // (x / y); y should > 0
	inline void fix () { if(y < 0) y = -y, x = -x; }
	frac (ll a = 0, ll b = 0) { x = a, y = b, fix(); }
	friend bool operator < (frac a, frac b) { return a.x * b.y < a.y * b.x; } // if it is long long * long long, use __int128
	friend bool operator >= (frac a, frac b) { return a.x * b.y >= a.y * b.x; } 
};
struct Point {
	mutable ll x, y;
	mutable frac k;
	Point (ll a = 0, ll b = 0, frac tk = 0) { x = a, y = b, k = tk; }
	friend bool operator < (Point a, Point b) { return !flg ? a.x < b.x : a.k < b.k; }
};
struct MXHULL { 
	multiset < Point > a;
	double div (ll x, ll y) { return (double) x / y; } // for long long : a / b - ((a ^ b) < 0 && a % b)
	bool check (multiset < Point > :: iterator x, multiset < Point > :: iterator y) {
		if(y == a.end ()) return x -> k = frac (1, 0), false;
		if (x -> x == y -> x) x -> k = x -> y > y -> y ? frac (1, 0) : frac (-1, 0);
		else x -> k = frac (x -> y - y -> y, y -> x - x -> x); 
		return x -> k >= y -> k;
	}
	void insert (ll u, ll v) {
		Point p (u, v, frac (1, 0));
		a.insert (p);
		auto z = a.lower_bound (p), y = z++, x = y;
		while (check (y, z)) a.erase (z++);
		if (x != a.begin () && check (--x, y)) a.erase (y++), check(x, y);
		while ((y = x) != a.begin () && (--x) -> k >= y -> k) a.erase (y++), check (x, y);
	}
	ll query (ll x, ll y) { // y >= 0
		if(!sz(a)) return -1e18;
		if (y == 0) return x > 0 ? x * (* -- a.end ()).x : x * (* a.begin ()).x;
		flg = true;
		auto u = a.lower_bound (Point (0, 0, frac(x, y)));
		flg = false;
		return x * (u -> x) + y * (u -> y);
	}
};
struct mxhull { // geting max (ax + by), only can insert 
	MXHULL a, b;
	void insert (ll x, ll y) {
		a.insert (x, y);
		b.insert (-x, -y);
	}
	ll query (ll x, ll y) {
		return y > 0 ? a.query (x, y) : b.query (-x, -y) ;
	}
};

int n, fa[N], siz[N]; 
vi e[N];
ll h[N];
void dfs (int x) {
	siz[x] = 1;
	for (const int &v : e[x]) if(v != fa[x]) fa[v] = x, dfs (v), siz[x] += siz[v];
}
ll dp[N], ns = 1e18;
void dfs2 (int x) {
	dp[x] = 1e18;
	for (const int &v : e[x]) if(v != fa[x]) dfs2 (v), dp[x] = min(dp[x], dp[v] + h[siz[x] - siz[v]]);
	if(dp[x] == 1e18) dp[x] = 0	;
	ns = min(ns, h[n - siz[x]] + dp[x]);
	mxhull a;
	for (const int &v : e[x]) {
		ll w = dp[v] - (ll) n * siz[v] - h[siz[v]] + (ll) siz[v] * siz[v];
		ns = min(ns, h[n] + w - a.query(1, siz[v]));
		a.insert (-w, -siz[v]);
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) h[i] = (ll) i * (i - 1) / 2;
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1);
	dfs2 (1);
	cout << (ll) n * (n - 1) - ns << '\n';
	return 0;
}