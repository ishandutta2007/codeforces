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
const int MAXN = 2e5 + 10;
const int INF = 1e9;

struct SegmTree {
  vi t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(sz * 2, INF);
  }

  void insert(int i) {
//    printf("insert %d\n", i);
    int v = sz + i;
    t[v] = i;
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  void erase(int i) {
//    printf("erase %d\n", i);
    int v = sz + i;
    t[v] = INF;
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  vi get_mn(int cnt) {
    vi res;
    forn(it, cnt) {
      int i = t[1];
      if  (i == INF) {
        break;
      }
      erase(i);
      res.pb(i);
    }
    for (int i : res) insert(i);
    return res;
  }
};

struct Query {
  int v, u, a, id;

  void read(int _id) {
    id = _id;
    scanf("%d%d%d", &v, &u, &a);
    --v;
    --u;
  }
};

vi who_live[MAXN];
vi pars[MAXN];
vi g[MAXN];
bool was[MAXN];
vector<Query> qs_for_v[MAXN];
vector<Query> qs;
int n, m, q;
vi ans[MAXN];
int sz[MAXN];
vi pref_mn[MAXN];

bool read() {
  if  (scanf("%d%d%d", &n, &m, &q) < 3) {
    return false;
  }
  forn(i, n) {
    g[i].clear();
    pars[i].clear();
    qs_for_v[i].clear();
    who_live[i].clear();
    pref_mn[i].clear();
  }
  qs.clear();
  forn(i, q) {
    ans[i].clear();
  }
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  forn(i, m) {
    int c;
    scanf("%d", &c);
    --c;
    who_live[c].pb(i);
  }
  forn(i, q) {
    Query cur;
    cur.read(i);
    qs.pb(cur);
  } 
  return true;
}

/*
void dfs_prec(int v, int p, SegmTree& T) {
  for (int i : who_live[v]) {
    T.insert(i);
  }
  pref_mn[v] = T.get_mn(10);
  for (int to : g[v]) {
    if  (to == p || was[to]) {
      continue;
    }
    dfs_prec(to, v, T);
  }
  for (int i : who_live[v]) {
    T.erase(i);
  }
}
*/

void insert(vi& arr, int i) {
  arr.pb(i);
  for (int j = sz(arr) - 1; j > 0; --j) {
    if  (arr[j] < arr[j - 1]) {
      swap(arr[j], arr[j - 1]);
    } else {
      break;
    }
  }
  while (sz(arr) > 10) arr.pop_back();
}

void dfs_prec(int v, int p, vi& arr) {
  vi mem = arr;
  for (int i : who_live[v]) insert(arr, i);
  pref_mn[v] = arr;
  for (int to : g[v]) {
    if  (to == p || was[to]) {
      continue;
    }
    dfs_prec(to, v, arr);
  }
  arr = mem;
}

void precalc_mn(int r) {
  /*
  SegmTree T(m); // INF
  dfs_prec(r, -1, T);
  */
  vi arr;
  dfs_prec(r, -1, arr);
}

void dfs_sz(int v, int p) {
  sz[v] = 1;
  for (int to : g[v]) {
    if  (to == p || was[to]) {
      continue;
    }
    dfs_sz(to, v);
    sz[v] += sz[to];
  }
}

int dfs_root(int v, int p, int S) {
  int mx_to = -1;
  for (int to : g[v]) {
    if  (to == p || was[to]) {
      continue;
    }
    if  (mx_to == -1 || sz[to] > sz[mx_to]) {
      mx_to = to;
    }
  }

  if  (mx_to == -1 || sz[mx_to] * 2 < S) {
    return v;
  }
  return dfs_root(mx_to, v, S);
}

int get_root(int v) {
  dfs_sz(v, -1);
  return dfs_root(v, -1, sz[v]);
}

void dfs_pars(int v, int p, int r) {
//  printf("dfs_pars v=%d, p=%d, r=%d\n", v, p, r);
  pars[v].pb(r);
  for (int to : g[v]) {
    if  (to == p || was[to]) {
      continue;
    }
    dfs_pars(to, v, r);
  }
}

void go(int v, bool init) {
//  printf("go %d %d\n", v, init);
      
  int r = get_root(v);
  if  (init) {
    dfs_pars(r, -1, r);
  } else {
    precalc_mn(r);
    for (auto Q : qs_for_v[r]) {
      vi res(sz(pref_mn[Q.u]) + sz(pref_mn[Q.v]));
      merge(all(pref_mn[Q.u]), all(pref_mn[Q.v]), res.begin());
      res.resize(unique(all(res)) - res.begin());
      forn(i, min(sz(res), Q.a)) {
        ans[Q.id].pb(res[i]);
      }
    }
  }

  was[r] = true;
  for (int to : g[r]) {
    if  (!was[to]) {
      go(to, init);
    }
  }
}

void solve() {
  // fill qs_for_v
  memset (was, false, sizeof was);
  go(0, true);

  for (auto Q : qs) {
    int r = -1;
    forn(i, min(sz(pars[Q.u]), sz(pars[Q.v]))) {
      if  (pars[Q.u][i] == pars[Q.v][i]) {
        r = pars[Q.u][i];
      }
    }
    assert(r != -1);
    qs_for_v[r].pb(Q);
  }

  /*
  forn(i, n) {
    printf("pars[%d]:", i);
    for (int x : pars[i]) printf("%d ", x);
    puts("");
  }
  */

  memset (was, false, sizeof was);
  go(0, false);

  forn(i, q) {
    printf("%d ", sz(ans[i]));
    for (int v : ans[i]) printf("%d ", v + 1);
    puts("");
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();
  }

  return 0;
}