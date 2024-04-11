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

int comp[MAXN];
vvi g;
vvi g_all;
int n, m;
bool was[MAXN];
bool cycle[MAXN];
int color[MAXN];

void dfs1(int v) {
  was[v] = true;

  for (int to : g_all[v]) {
    if  (!was[to]) {
      comp[to] = comp[v];
      dfs1(to);
    }
  }
}

void dfs2(int v) {
  color[v] = 1;

  for (int to : g[v]) {
    if  (color[to] == 1) {
      cycle[v] = true;
      continue;
    }

    if  (color[to] == 0) {
      dfs2(to);
    }
  }

  color[v] = 2;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> m;

  g.resize(n);
  g_all.resize(n);

  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(b);
    
    g_all[a].pb(b);
    g_all[b].pb(a);
  }

  memset (was, false, sizeof was);
  int comps = 0;
  forn(v, n) {
    if  (!was[v]) {
      comp[v] = comps++;
      dfs1(v);
    }
  }

  memset (color, 0, sizeof color);
  forn(v, n) {
    if  (color[v] == 0) {
      dfs2(v);
    }
  }

  vi ans(comps, 0);
  vi Sz(comps, 0);
  forn(v, n) {
    ++Sz[comp[v]];
  }

  forn(c, comps) {
    ans[c] = Sz[c] - 1;
  }

  forn(v, n) {
    if  (cycle[v]) {
      ans[comp[v]] = Sz[comp[v]];
    }
  }

  int sum = 0;
  for (int a : ans) sum += a;
  cout << sum;
  return 0;
}