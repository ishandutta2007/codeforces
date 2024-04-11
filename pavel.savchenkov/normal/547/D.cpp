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
const int MAXN = 4e5 + 10;

vii g[2 * MAXN + 10];
int n, m;
int comp[2 * MAXN + 10];
bool was[2 * MAXN + 10];

void dfs1(int v) {
  was[v] = true;
  for (const auto& e : g[v]) {
    int to = e.fst;
    if  (!was[to]) {
      comp[to] = comp[v];
      dfs1(to);
    }
  }
}

int ans[2 * MAXN + 10];
int ptr[2 * MAXN + 10];
bool done[2 * MAXN + 10];

void dfs(int v, vi& E) {
//  printf("in %d\n", v);

  for (; ptr[v] < sz(g[v]); ++ptr[v]) {
    auto e = g[v][ptr[v]];
    int to = e.fst;
    int id = e.snd;

    if  (was[id]) {
      continue;
    }
  
    was[id] = true;
    dfs(to, E);
  }

  E.pb(v);
  done[v] = true;
}

void addE(int v, int u, int id) {
//  printf("%d -> %d, id=%d\n", v, u, id);
  g[v].pb(mp(u, id));
  g[u].pb(mp(v, id));
}

int one_side(int v, int u) {
  return (v < MAXN) == (u < MAXN);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    addE(x, y + MAXN, i);
  }

  memset (was, false, sizeof was);
  int c = 0;
  forn(i, MAXN) {
    if  (!was[i] && !g[i].empty()) {
      comp[i] = c++;
      dfs1(i);
    }
  }

  vi perm;
  forn(i, MAXN) if  (!g[i].empty()) perm.pb(i);
  forn(i, MAXN) if  (!g[i + MAXN].empty()) perm.pb(i + MAXN);

  sort(all(perm), [&](int v, int u) { return mp(comp[v], sz(g[v]) % 2) < mp(comp[u], sz(g[u]) % 2); });

  int id = n;
  forn(i, sz(perm) - 1) {
    int v = perm[i];
    int u = perm[i + 1];
    if  (sz(g[v]) & 1) {
      assert(sz(g[u]) % 2 == 1 && comp[u] == comp[v]);
      addE(v, u, id++);
//      printf("aux\n");
    }
  }

  forn(v, MAXN) {
    assert(sz(g[v]) % 2 == 0);
    assert(sz(g[v + MAXN]) % 2 == 0);
  }

  forn(i, MAXN) sort(all(g[i]));
  forn(i, MAXN) sort(all(g[i + MAXN]));

  memset (done, false, sizeof done);
  memset (was, false, sizeof was);
  forn(i, MAXN) {
    if  (!done[i] && !g[i].empty()) {
//      printf("from %d\n", i);
      vi E;
      dfs(i, E);

      /*
      for (int& v : E) {
        cout << "v = " << v << endl;
      }
      continue;
      */

      int par = 0;
      forn(j, sz(E) - 1) {
        int v = E[j];
        int to = E[j + 1];
//        printf("%d -> %d\n", v, to);
        int pos = lower_bound(all(g[v]), mp(to, -1)) - g[v].begin();
        assert(g[v][pos].fst == to);
        ans[g[v][pos].snd] = par % 2;
        if  (!one_side(v, to)) {
          ++par;
        }
      }
    }
  }

  forn(i, n) putchar(ans[i] ? 'b' : 'r');
  return 0;
}