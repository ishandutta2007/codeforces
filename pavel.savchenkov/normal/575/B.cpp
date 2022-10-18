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
const int MAXL = 19;
const int MOD = 1e9 + 7;
const int MAXC = 1e6 + 10;

inline void add(int& x, int y) {
  ((x += y) >= MOD) && (x -= MOD);
}

inline int mul(int x, int y) {
  return x * 1ll * y % MOD;
}

int pow2[MAXC];

void precalc() {
  pow2[0] = 1;
  for (int i = 1; i < MAXC; ++i) {
    pow2[i] = mul(pow2[i - 1], 2);
  }
}

struct Edge {
  int a, b, x;

  int get_to(int v) const {
    assert(v == a || v == b);
    return (v == a) ? b : a;
  }

  void read() {
    assert(scanf("%d%d%d", &a, &b, &x) == 3);
    --a;
    --b;
  }
};

vector<Edge> es;
vi g[MAXN];
int n, k;
vi s;

int tin[MAXN];
int tout[MAXN];
int par[MAXN][MAXL];
int timer;

inline bool upper(int a, int b) {
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b) {
  if  (upper(a, b)) {
    return a;
  }
  if  (upper(b, a)) {
    return b;
  }
  for (int l = MAXL - 1; l >= 0; --l) {
    if  (!upper(par[a][l], b)) {
      a = par[a][l];
    }
  }
  assert(upper(par[a][0], b));
  return par[a][0];
}

void dfs(int v, int p) {
  assert(0 <= v && v < n);
  assert(0 <= p && p < n);

  tin[v] = timer++;

  par[v][0] = p;
  for (int i = 1; i < MAXL; ++i) {
    par[v][i] = par[par[v][i - 1]][i - 1];
  }

  for (int id : g[v]) {
    int to = es[id].get_to(v);
    assert(to != v);
    if  (to == p) {
      continue;
    }
    //cerr << to << endl;
    dfs(to, v);
  }

  tout[v] = timer++;
}

int s_down[MAXN];
int s_up[MAXN];

int ans;

void dfs2(int v, int p, int Id) {
  for (int id : g[v]) {
    int to = es[id].get_to(v);
    if  (to == p) {
      continue;
    }
    dfs2(to, v, id);
    s_up[v] += s_up[to];
    s_down[v] += s_down[to];
  }

  if  (Id == -1) {
    return;  
  }

  assert(0 <= Id && Id < sz(es));

  if  (es[Id].x == 0) {
    return;
  }

  if  (es[Id].a == v) {
    int coef = s_down[v];
    // 1 + 2 + 4 + ... + 2^{coef - 1}
    if  (!(0 <= coef && coef < MAXC)) {
      cerr << coef << endl;
      exit(0);
    }
    add(ans, pow2[coef]);
    add(ans, -1 + MOD);
  } else {
    int coef = s_up[v];
    assert(0 <= coef && coef < MAXC);
    add(ans, pow2[coef]);
    add(ans, -1 + MOD);
  }
}

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) g[i].clear();
  es.clear();
  forn(i, n - 1) {
    Edge e;
    e.read();
    assert(0 <= e.b && e.b < MAXN);
    g[e.a].pb(sz(es));
    g[e.b].pb(sz(es));
    es.pb(e);
  }
  assert(scanf("%d", &k) == 1);
  s.resize(k);
  forn(i, k) {
    assert(scanf("%d", &s[i]) == 1);
    --s[i];
  }
  return true;
}

void solve() {
  timer = 0;
  
  dfs(0, 0);

  s.insert(s.begin(), 0);
  assert(s[0] == 0);

  forn(i, n) {
    s_down[i] = s_up[i] = 0;
  }

  // down
  forn(i, sz(s) - 1) {
    int v = s[i];
    int to = s[i + 1];
    int c = lca(v, to);
    if  (c == v) {
      ++s_down[to];
      --s_down[v];
      continue; 
    }
    if  (c == to) {
      ++s_up[v];
      --s_up[to];
      continue;
    }
    ++s_up[v];
    --s_up[c];
    ++s_down[to];
    --s_down[c];
  }

  ans = 0;
  dfs2(0, 0, -1);

  cout << ans << endl;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  precalc();

  while (read()) {
    solve();
  //  break;
  }

  return 0;
}