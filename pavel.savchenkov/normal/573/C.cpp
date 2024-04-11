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
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 1e5 + 10;

vi g[MAXN];
bool dp1[MAXN];
bool dp2[MAXN];
bool line[MAXN];
int n;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) g[i].clear();
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(b);
    g[b].pb(a);  
  }
  return true;
}

void dfs(int v, int p) {
  vi G;
  for (int to : g[v]) {
    if  (to == p) {
      continue;
    }
    G.pb(to);
    dfs(to, v);
  }

  // line
  line[v] = false;
  if  (sz(G) <= 1) {
    line[v] = true;
    for (int to : G) {
      if  (!line[to]) {
        line[v] = false;
      }
    }
  }

  // dp1
  dp1[v] = false;
  if  (sz(G) <= 2) {
    dp1[v] = true;
    for (int to : G) {
      if  (!line[to]) {
        dp1[v] = false;
      }
    }   
  }

  // dp2
  dp2[v] = false;
  int sum_dp1 = 0;
  for (int to : G) {
    sum_dp1 += dp1[to];
  } 

  for (int to : G) {
    sum_dp1 -= dp1[to];
    if  (dp2[to] && sum_dp1 == sz(G) - 1) {
      dp2[v] = true;
    }
    sum_dp1 += dp1[to];
  }

  dp2[v] |= dp1[v];

//  printf("v=%d, line=%d, dp1=%d, dp2=%d\n", v+1, line[v], dp1[v], dp2[v]);
}

bool is_root(int v, int p) {
  vi G;
  for (int to : g[v]) {
    if  (to != p) {
      G.pb(to);
    }
  }

  if  (!sz(G)) {
    return true;
  }

  if  (sz(G) == 1) {
    return is_root(G[0], v);  
  }

  sort(all(G), [](int a, int b) { return (dp1[a] < dp1[b]); });

  bool ok = true;
  forn(i, sz(G)) {
    int to = G[i];
    if  (i <= 1) {
      if  (!dp2[to]) {
        ok = false;
      }
    } else {
      if  (!dp1[to]) {
        ok = false;
      }
    }
  }

  if  (ok) {
    return true;
  }

  if  (sz(G) == 2) {
    sort(all(G), [](int a, int b) { return line[a] > line[b]; });
    if  (line[G[0]]) {
      return is_root(G[1], v);
    }
  }

  if  (sz(G) >= 4) {
    return false;
  }

  sort(all(G), [](int a, int b) { return line[a] > line[b]; });

  ford(i, sz(G) - 1) {
    int to = G[i];
    if  (!line[to]) {
      return false;
    }
  }

  int u = G.back();
  vi Gu;
  for (int to : g[u]) {
    if  (to != v) {
      Gu.pb(to);
    }
  }

  sort(all(Gu), [](int a, int b) { return dp1[a] < dp1[b]; });

  while (!Gu.empty() && dp1[Gu.back()]) Gu.pop_back();

  if  (sz(Gu) > 2) {
    return false;
  }

  for (int to : Gu) {
    if  (!dp2[to]) {
      return false;
    }
  }

  return true;
}

bool solve() {
  dfs(0, -1);

  return is_root(0, -1);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    puts(solve() ? "Yes" : "No");
  }

  return 0;
}