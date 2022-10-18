#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXN = int(2e3 + 5);

struct DSU {
	vi par;
	vi sz;

	DSU() {}

	DSU( int n ) {
		par.assign(n, 0);
		sz.assign(n, 1);

		FORN(i, n) {
			par[i] = i;
		}
	}

	int get_set( int x ) {
		return x == par[x] ? x : par[x] = get_set(par[x]);
	}

	bool union_set( int x, int y ) {
		x = get_set(x);
		y = get_set(y);

		if  (x == y) {
			return false;
		}

		if  (sz[x] > sz[y]) {
			swap(x, y);
		}

		par[x] = y;
		sz[y] += sz[x];

		return true;
	}
};

int d[MAXN][MAXN];
vector < pair <int, pii> > D;
int n;
vector <pii> g[MAXN];
ll sum[MAXN];
int p[MAXN][30];
int tin[MAXN];
int tout[MAXN];
int timer = 0;

bool upper( int v, int u ) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void dfs( int v, int par, ll S ) {
	sum[v] = S;

	tin[v] = timer++;

	p[v][0] = par;
	for (int i = 1; i <= 20; ++i) {
		p[v][i] = p[p[v][i - 1]][i - 1];
	}

	FORN(i, SZ(g[v])) {
		int to = g[v][i].F;
		int w = g[v][i].S;

		if  (to != par) {
			dfs(to, v, S + w);
		}
	}

	tout[v] = timer++;
}

int lca( int v, int u ) {
	if  (upper(v, u)) {
		return v;
	}	

	if  (upper(u, v)) {
		return u;
	}

	for (int l = 20; l >= 0; --l) {
		if  (!upper(p[v][l], u)) {
			v = p[v][l];	
		}
	}

	return p[v][0];
}

ll get_dist( int v, int u ) {
	return sum[v] + sum[u] - 2ll * sum[lca(v, u)];
}                             

bool check() {
	dfs(0, 0, 0);

	FORN(i, n) {
		FORN(j, n) {
			if  (d[i][j] != get_dist(i, j) || (d[i][j] == 0 && i != j)) {
				return false;
			}
		}
	}	

	return true;
}

int main() {
	scanf("%d", &n);

	FORN(i, n)
		FORN(j, n) {
			scanf("%d", &d[i][j]);
			D.PB(MP(d[i][j], MP(i, j)));
		}

	sort(ALL(D));
	DSU dsu(n);

	FORN(i, SZ(D)) {
		int dist = D[i].F;
		int v = D[i].S.F;
		int u = D[i].S.S;

		if  (dsu.get_set(v) != dsu.get_set(u)) {
			g[u].PB(MP(v, dist));
			g[v].PB(MP(u, dist));
			dsu.union_set(v, u);
		}
	}

	puts(check() ? "YES" : "NO");
	return 0;
}