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
#define hash kjfdkljkdhgjdkfhgurehg
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

vi g[MAXN];
int sz[MAXN];
int n, m;
int par[MAXN][20];
int tin[MAXN];
int tout[MAXN];
int timer;
int depth[MAXN];
int logN;

bool upper(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void dfs(int v, int p) {
  tin[v] = timer++;
  sz[v] = 1;

  par[v][0] = p;
  for (int i = 1; i <= logN; ++i) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }

  for (int to : g[v]) {
    if  (to != p) {
      depth[to] = depth[v] + 1;
      dfs(to, v);
      sz[v] += sz[to];
    }
  }

  tout[v] = timer++;
}
 
int lca(int a, int b) {
  if  (upper(a, b)) {
    return a;
  }

  if  (upper(b, a)) {
    return b;
  }

  for (int l = logN; l >= 0; --l) {
    if  (!upper(par[a][l], b)) {
      a = par[a][l];
    }
  }

  return par[a][0];
}

int go_up(int v, int len) {
  for (int l = logN; l >= 0; --l) {
    if  (len & (1 << l)) {
      v = par[v][l];
    }
  }

  return v;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n;
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;

    g[a].pb(b);
    g[b].pb(a);
  }

  logN = 1;
  while ((1 << logN) <= n) ++logN;

  timer = 0;
  depth[0] = 0;
  dfs(0, 0);

  cin >> m;
  while (m --> 0) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;

    if  (depth[a] < depth[b]) {
      swap(a, b);  
    }

    int c = lca(a, b);
    int len = depth[a] + depth[b] - 2 * depth[c];

    if  (len & 1) {
      puts("0");
      continue;
    }

    if  (a == b) {
      printf("%d\n", n);
      continue;
    }

    if  (len / 2 == depth[a] - depth[c]) {
      assert(len / 2 == depth[b] - depth[c]);

      int ca = go_up(a, len / 2 - 1);
      int cb = go_up(b, len / 2 - 1);

      int low = sz[c] - sz[ca] - sz[cb];
      int up = n - sz[c];

      printf("%d\n", low + up);
    } else {
      int mid = go_up(a, len / 2);

      int mida = go_up(a, len / 2 - 1);

      printf("%d\n", sz[mid] - sz[mida]); 
    }
  }

  return 0;
}