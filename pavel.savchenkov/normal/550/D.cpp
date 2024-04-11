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
const int MAXN = (int) 1e6;

int k;
int V, E;
vii es;

bool build(const vii& degs) {
  set<pii> s;
  for (const auto& d : degs) {
    s.insert(d);
  }

  while (!s.empty()) {
    int v = s.rbegin()->snd;
    int deg = s.rbegin()->fst;
    s.erase(*s.rbegin());

    if  (deg == 0) {
      continue;
    }   

//    printf("v = %d\n", v);

    if  (deg > sz(s)) {
      es.clear();
      return false;
    }

    vii cur;
    while (deg && !s.empty()) {
      int u = s.rbegin()->snd;
      int deg_u = s.rbegin()->fst;
      s.erase(*s.rbegin());
      if  (deg_u == 0) {
        continue;
      }
      cur.pb(mp(--deg_u, u));
      --deg;
      es.pb(mp(v, u));
    //  printf("u = ");
    }

    if  (deg) {
      es.clear();
      return false;
    }

    for (auto it : cur) {
      s.insert(it);
    }
  }

  return true;
}

bool solve() {
  if  (k % 2 == 0) {
    return false;
  }

  if  (k == 1) {
    V = 2;
    E = 1;
    es.pb(mp(0, 1));
    return true;
  }

  int l = 0;
  int r = k + 1;
  vii degs;
  for (int i = l + 1; i + 2 <= r; ++i) {
    degs.pb(mp(k - 1, i));
  }
  degs.pb(mp(k, r - 1));
  degs.pb(mp(k, r));

  for (int i = l + 1; i + 2 <= r; ++i) {
    es.pb(mp(l, i));
  }

  if  (!build(degs)) {
    return false;
  }

  l += k + 2;
  r += k + 2;
  degs.clear();
  for (int i = l + 1; i + 2 <= r; ++i) {
    degs.pb(mp(k - 1, i));
  }
  degs.pb(mp(k, r - 1));
  degs.pb(mp(k, r));

  for (int i = l + 1; i + 2 <= r; ++i) {
    es.pb(mp(l, i));
  }

  if  (!build(degs)) {
    return false;
  }

  es.pb(mp(0, k + 2));

  V = (k + 2) * 2;
  E = sz(es);
  return true;
}

bool was[(int) 1e6];

void dfs(int v) {
  was[v] = true;

  forn(i, sz(es)) {
    int a = es[i].fst;
    int b = es[i].snd;
    
    if  (a == v) {
      if  (!was[b]) {
        dfs(b);
      }
    } else if  (b == v) {
      if  (!was[a]) {
        dfs(a);
      }
    } 
  }
}

int main() {
#ifdef LOCAL
//  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  cin >> k;

  if  (!solve()) {
    puts("NO");
    return 0;
  }
/*
  vi deg(V, 0);
  forn(i, sz(es)) {
    ++deg[es[i].fst];
    ++deg[es[i].snd];
  }

  forn(v, V) {
    assert(deg[v] == k);
  }

  memset (was, 0, sizeof was);
  dfs(0);

  forn(v, V) assert(was[v]);
*/
  puts("YES");
  printf("%d %d\n", V, E);
  forn(i, E) printf("%d %d\n", es[i].fst + 1, es[i].snd + 1);
  return 0;
}