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
const int INF = 1e9;

vii g[MAXN];
int n, m;

bool good[MAXN];
int D[MAXN];

int Q[MAXN * 5];
int ql, qr;

bool read() {
  if  (scanf("%d%d", &n, &m) < 2) {
    return false;
  } 
  forn(i, m) {
    int a, b, len;
    scanf("%d%d%d", &a, &b, &len);
    g[a].pb(mp(b, len));
    g[b].pb(mp(a, len));
  }
  return true;
}

int Dn[MAXN];
int prev[MAXN];

inline bool have_edge(int a, int b) {
  int pos = lower_bound(all(g[a]), mp(b, -1)) - g[a].begin();
  return (pos < sz(g[a]) && g[a][pos].fst == b);
}

void solve() {
  forn(i, n) {
    sort(all(g[i]));
  }

  ql = qr = 0;
  good[n - 1] = true;
  Q[qr++] = n - 1;
  while (ql != qr) {
    int v = Q[ql++];
    for (auto e : g[v]) {
      int to = e.fst;
      if  (e.snd == 0 && !good[to]) {
        good[to] = true;
        Q[qr++] = to;
      }
    }
  }

  ql = qr = 0;
  forn(v, n) D[v] = INF;
  D[0] = 0;
  Q[qr++] = 0;

  while (ql != qr) {
    int v = Q[ql++];
    for (auto e : g[v]) {
      int to = e.fst;
      if  (D[to] > D[v] + 1) {
        D[to] = D[v] + 1;
        Q[qr++] = to;
      }
    }
  }

  vi digs;
  vi lay;
  
  int mn = INF;
  forn(i, n) if  (good[i]) {
    mn = min(mn, D[i]);
  }
  forn(i, n) if  (good[i] && D[i] == mn) {
    lay.pb(i);
  }

  forn(v, n) Dn[v] = INF;
  Dn[n - 1] = 0;
  ql = qr = 0;
  Q[qr++] = n - 1;
  while (ql != qr) {
    int v = Q[ql++];
    for (auto e : g[v]) {
      int to = e.fst;
      if  (Dn[to] > Dn[v] + 1 && e.snd == 0) {
        Dn[to] = Dn[v] + 1;
        Q[qr++] = to;
      }
    }
  }

  memset (prev, -1, sizeof prev);

  forn(it, mn) {
    int min_d = 10;
    for (int v : lay) {
      for (auto e : g[v]) {
        int to = e.fst;
        if  (D[to] == D[v] - 1) {
          min_d = min(min_d, e.snd);
        }
      }
    }  
    assert(min_d < 10);

    digs.pb(min_d);
    vi nlay;
    for (int v : lay) {
      for (auto e : g[v]) {
        int to = e.fst;
        if  (D[to] == D[v] - 1 && e.snd == min_d) {
          nlay.pb(to);
          if  (prev[to] == -1 || Dn[prev[to]] > Dn[v]) {
            prev[to] = v;
          }
        }
      }
    }  

    sort(all(nlay));
    nlay.resize(unique(all(nlay)) - nlay.begin());

    lay.swap(nlay);
  }

  bool was = false;
  for (int v : lay) {
    was |= v == 0;
  }
  assert(was);

  vi ans;
  int V = 0;
  while (1) {
    ans.pb(V);
    if  (D[V] == mn) {
      break;
    }
    V = prev[V];  
  }

  assert(good[V]);

  forn(it, Dn[V]) {
    int v = ans.back();
    bool was = false;
    for (auto e : g[v]) {
      int to = e.fst;
      if  (Dn[to] == Dn[v] - 1 && e.snd == 0) {
        ans.pb(to);
        was = true;
        break;
      }
    }
    assert(was);
  }

  assert(Dn[ans.back()] == 0);

  forn(i, sz(ans) - 1) {
    assert(have_edge(ans[i], ans[i + 1]));
  }

  if  (digs.empty()) digs.pb(0);
  forn(i, sz(digs)) {
    printf("%d", digs[i]);
  }
  puts("");
  printf("%d\n", sz(ans));
  for (int v : ans) {
    printf("%d ", v);
  }
  puts("");
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();
    break;
  }

  return 0;
}