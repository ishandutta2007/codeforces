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
#include <unordered_map>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
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
const int MAXN = 1e5 + 10;
const ll INF = (ll) 1e18;

vii g[MAXN];
ll d[MAXN];
int n;
ll depth[MAXN];

void read() {
  scanf("%d", &n);
  forn(i, n - 1) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    --a;
    --b;

    g[a].pb(mp(b, w));
    g[b].pb(mp(a, w));
  }
}

void dfs1(int v, int p) {
  depth[v] = 0;

  for (auto& it : g[v]) {
    int to = it.fst;
    int w = it.snd;

    if  (to == p) {
      continue;
    }

    dfs1(to, v);

    depth[v] = max(depth[v], w + depth[to]);
  }
}

void dfs2(int v, int p, ll up) {
  ll mx1 = -1;
  ll mx2 = -1;

  for (auto& it : g[v]) {
    int to = it.fst;
    int w = it.snd;

    if  (to == p) {
      continue;
    }

    ll cur = depth[to] + w;

    if  (cur > mx1) {
      mx2 = mx1;
      mx1 = cur;
    } else if  (cur > mx2) {
      mx2 = cur;
    }
  }

  d[v] = max(up, depth[v]);

  for (auto& it : g[v]) {
    int to = it.fst;
    int w = it.snd;

    if  (to == p) {
      continue;
    }
  
    ll cur = depth[to] + w;

    if  (cur == mx1) {
      dfs2(to, v, max(up, mx2) + w);
    } else {
      dfs2(to, v, max(up, mx1) + w);
    } 
  }
}

int root;
int par[MAXN][20];
int size[MAXN];
int logN;

void dfs3(int v, int p) {
	par[v][0] = p;
	for (int i = 1; i <= logN; ++i) {
		par[v][i] = par[par[v][i - 1]][i - 1];
	}

  for (auto& it : g[v]) {
    int to = it.fst;

    if  (to == p) {
      continue;
    }

    dfs3(to, v);
  }
}

void precalc() {
  root = 0;

  dfs1(0, -1);
  dfs2(0, -1, 0);

  forn(v, n) {
    if  (d[v] < d[root]) {
      root = v;
    }
  }

	logN = 1;
	while ((1 << logN) <= n) ++logN;

	dfs3(root, root);
}

void dfs(int v, int p, ll l) {
	size[v] += 1;

	for (auto& it : g[v]) {
		int to = it.fst;

		if  (to == p) {
			continue;
		}

//		printf("%d -> %d\n", v + 1, to + 1);
		dfs(to, v, l);

		size[v] += size[to];
	}

	int u = v;
	for (int deg = logN; deg >= 0; --deg) {
		if  (d[par[u][deg]] + l >= d[v]) {
			u = par[u][deg];	
		}
	}

	if  (u != root) {
		--size[par[u][0]];
//		printf("v=%d, --size[%d], u=%d\n", v + 1, par[u][0] + 1, u + 1);
	}
}

int solve(ll l) {
	memset (size, 0, sizeof(int) * n);
	dfs(root, -1, l);	

	int ans = 0;
	forn(v, n) {
		ans = max(ans, size[v]);
//		printf("size[%d] = %d\n", v + 1, size[v]);
	}

	return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
#endif

  read();

  precalc();

  int q;
  scanf("%d", &q);
  forn(i, q) {
    ll l;
    cin >> l;
    printf("%d\n", solve(l));
  }

  return 0;
}