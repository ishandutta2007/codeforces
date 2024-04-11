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

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

int Sz;
vi g[MAXN];
int tin[MAXN];
int tout[MAXN];
int par[MAXN][25];
int timer = 0;
int depth[MAXN];
int logN;
int k, n;

struct cmp_time {
	inline bool operator() ( int a, int b ) {
		return tin[a] < tin[b];
	}
};

set <int, cmp_time> s;

inline bool ancestor( int v, int u ) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int lca( int v, int u ) {
	if  (ancestor(v, u)) {
		return v;
	}

	if  (ancestor(u, v)) {
		return u;
	}

	for (int l = logN; l >= 0; l--)
		if  (!ancestor(par[v][l], u)) {
			v = par[v][l];	
		}

	return par[v][0];
}

int dist( int v, int u ) {
	return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}

int prev( set <int> :: iterator it ) {
	return it == s.begin() ? *s.rbegin() : *(--it);
}

int next( set <int> :: iterator it ) {
	return *it == *s.rbegin() ? *s.begin() : *(++it);
}

void remove_vertex( int v ) {
	assert(!s.empty());

	set <int> :: iterator it = s.find(v);
	int v1 = prev(it);
	int v2 = next(it);

	Sz -= dist(v1, v);
	Sz -= dist(v, v2);
	Sz += dist(v1, v2);

	s.erase(it);
}

void add_vertex( int v ) {
	s.insert(v);
	set <int> :: iterator it = s.find(v);

	int v1 = prev(it);
	int v2 = next(it);

	Sz -= dist(v1, v2);
	Sz += dist(v1, v);
	Sz += dist(v, v2);	
}

void dfs( int v, int p = 0, int de = 0 ) {
	par[v][0] = p;
	for (int l = 1; l <= logN; l++)
		par[v][l] = par[par[v][l - 1]][l - 1];

	tin[v] = timer++;
	depth[v] = de;

	forn(i, sz(g[v])) {
		int to = g[v][i];

		if  (to != p) {
			dfs(to, v, de + 1);
		}
	}

	tout[v] = timer++;	
}

int main() {
	scanf("%d%d", &n, &k);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	logN = 1;
	while ((1 << logN) <= n) logN++;

	dfs(0);

	k = 2 * k - 2;
	int res = 1;
	int r = -1;
	Sz = 0;

	for (int l = 0; l < n; l++) {
		if  (l) {
			remove_vertex(l - 1);
		}

		while (Sz <= k && r < n - 1) {
			add_vertex(++r);
		}

		if  (Sz > k) {
			remove_vertex(r--);
		}

		assert(Sz <= k);
		assert(sz(s) == r - l + 1);

		res = max(res, r - l + 1);	
	}

	printf("%d\n", res);	
	return 0;
}