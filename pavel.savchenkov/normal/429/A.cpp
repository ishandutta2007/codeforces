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
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

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

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

vi g_init[MAXN];
vi g[MAXN];

int init[MAXN];
int goal[MAXN];

int dp[2][MAXN];
int n;

bool root[MAXN];

void build( int v, int p = -1 ) {
	forn(i, sz(g_init[v])) {
		int to = g_init[v][i];

		if  (to == p) {
			continue;
		}

		forn(j, sz(g_init[to])) {
			int to2 = g_init[to][j];

			if  (to2 == v) {
				continue;
			}

			g[v].pb(to2);
			root[to2] = false;
		}

		build(to, v);
	}
}

vi res;

void solve( int v, int change = 0 ) {
	if  (((init[v] + change) & 1) == goal[v]) {
		forn(i, sz(g[v])) {
			int to = g[v][i];

			solve(to, change);
		}	
	} else {
		res.pb(v);

		forn(i, sz(g[v])) {
			int to = g[v][i];

			solve(to, change ^ 1);
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

 	scanf("%d", &n);
 	forn(i, n - 1) {
 		int u, v;
 		scanf("%d%d", &u, &v);
 		--u;
 		--v;

 		g_init[u].pb(v);
 		g_init[v].pb(u);
 	}

 	forn(i, n) {
 		scanf("%d", &init[i]);
 	}

 	forn(i, n) {
 		scanf("%d", &goal[i]);
 	}

 	memset (root, true, sizeof root);

 	build(0);

 	forn(i, n)
 		if  (root[i]) {
 			solve(i);
 		}

 	printf("%d\n", sz(res));
 	forn(i, sz(res))
 		printf("%d\n", res[i] + 1);
	return 0;
}