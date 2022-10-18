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

bool alive[MAXN];
vi g[MAXN];
int n;
char rank[MAXN];
int sz[MAXN];

void pre_dfs( int v, int p = -1 ) {
	sz[v] = 1;

	forn(i, sz(g[v])) {
		int to = g[v][i];

		if  (to != p && alive[to]) {
			pre_dfs(to, v);
			sz[v] += sz[to];
		}
	}
}

int dfs( int v, int sz_component, int p = -1 ) {
	forn(i, sz(g[v])) {
		int to = g[v][i];

		if  (to != p && alive[to]) {
			if  (sz[to] > sz_component / 2) {
				return dfs(to, sz_component, v);
			}
		}
	}

    return v;    
}

int find_center( int v ) {
	pre_dfs(v);

	return dfs(v, sz[v]);
}

void solve( int v, char ch ) {
	if  (ch > 'Z') {
		puts("Impossible!");
		exit(0);
	}

	v = find_center(v);
	rank[v] = ch;
	alive[v] = false;

	forn(i, sz(g[v])) {
		int to = g[v][i];

		if  (alive[to]) {
			solve(to, ch + 1);
		}
	}
}

int main() {	
	scanf("%d", &n);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	memset (alive, true, sizeof alive);

	solve(0, 'A');

	forn(i, n)
		printf("%c ", rank[i]);	
	return 0;
}