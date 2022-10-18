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
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 5;

struct Edge {
	int to, w, type;
};

vector <Edge> g[MAXN];
int n, m, k;
bool kill[MAXN];
ll dist[MAXN];

void addE( int v, int u, int w, int type ) {
	g[v].pb({ u, w, type });
	g[u].pb({ v, w, type });
}

void solve() {
	set <pair<ll, int> > S;

	forn(i, n) {
		dist[i] = ll(1e18);
	}

	dist[0] = 0;
	S.insert(mp(0, 0));

	while (!S.empty()) {
		int v = S.begin()->s;
		S.erase(S.begin());

		forn(i, sz(g[v])) {
			int to = g[v][i].to;
			int w = g[v][i].w;
			int type = g[v][i].type;

			ll newDist = dist[v] + ll(w);
		
		    if  (type == 0) {
		    	if  (newDist <= dist[to]) {
		    		kill[to] = true;
		    		S.erase(mp(dist[to], to));
		    		dist[to] = newDist;
		    		S.insert(mp(dist[to], to));
		    	}
		    } else {
		    	if  (newDist < dist[to]) {
		    		kill[to] = false;
		    		S.erase(mp(dist[to], to));
		    		dist[to] = newDist;
		    		S.insert(mp(dist[to], to));
		    	}
		    }
		}
	}
}

int main() {
	memset (kill, false, sizeof kill);
	
	scanf("%d%d%d", &n, &m, &k);

	forn(i, m) {
		int v, u, w;
		scanf("%d%d%d", &v, &u, &w);
		--v;
		--u;

		addE(v, u, w, 0);
	}

	forn(i, k) {
		int to, w;
		scanf("%d%d", &to, &w);
		--to;

		addE(0, to, w, 1);
	}

	solve();

	int ans = 0;
	for (int v = 1; v < n; ++v) {
		int cntIn = 0;
		forn(i, sz(g[v])) {
			int type = g[v][i].type;
			if  (type == 1) {
				++ans;
				++cntIn;
			}
		}

		if  (!kill[v] && cntIn > 0) {
			--ans;
		}
	}

	printf("%d\n", ans);
	return 0;
}