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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int MAXN = 50 + 10;

struct Edge {
  int v, to, cap, flow;
};

const int INF = 1e9;

int dist[2 * MAXN];
int Q[MAXN * MAXN * MAXN];
int ql, qr;
int prev[MAXN * MAXN * MAXN];

struct Graph {
  vvi g;
  int n;
  vector<Edge> es;

  Graph(int n = 0) : n(n) {
    g.assign(n, vi());
  }

  int addE(int v, int to, int cap) {
    int id = sz(es);
    g[v].pb(sz(es));
    es.pb(Edge{v, to, cap, 0});
    g[to].pb(sz(es));
    es.pb(Edge{to, v, 0, 0});
    return id;
  }

  void change(int id, int cap) {
    assert(id < sz(es));
    es[id].cap = cap;
    es[id ^ 1].cap = 0;
  } 

  int add_flow() {
    forn(i, n) {
      dist[i] = INF;
      prev[i] = -1;
    }
    ql = qr = 0;
    dist[0] = 0;
    Q[qr++] = 0;
    while (ql != qr) {
      int v = Q[ql++];
      for (int id : g[v]) {
        if  (es[id].cap - es[id].flow > 0 && dist[es[id].to] > dist[v] + 1) {
          dist[es[id].to] = dist[v] + 1;
          Q[qr++] = es[id].to;
          prev[es[id].to] = id;
        }
      }
    } 

    if  (prev[n - 1] == -1) return 0;

    int add = INF;
    int v = n - 1;
    while (v) {
      int id = prev[v];
      add = min(add, es[id].cap - es[id].flow);
      v = es[id].v;
   //   printf("v = %d\n", v + 1);
    }
  //  printf("add = %d\n", add);

    v = n - 1;
    while (v) {
      int id = prev[v];
      es[id].flow += add;
      es[id ^ 1].flow -= add;
      v = es[id].v;
    }

    return add;
  }

  bool max_flow(int lim) {
    forn(i, sz(es)) es[i].flow = 0;

    int f = 0;
    while (1) {
      int cur = add_flow();
    //  printf("cur = %d\n", cur);
      f += cur;
      if  (f >= lim) return true;
      /*
      printf("f = %d\n", f);
      forn(i, sz(es)) {
        printf("%d->%d, cap=%d, flow=%d\n", es[i].v + 1, es[i].to + 1, es[i].cap, es[i].flow);
      }
      */
      if  (!cur) return false;
    }
  }
};

vii g[MAXN];
int n, m, x;

bool read() {
  if  (scanf("%d%d%d", &n, &m, &x) < 3) {
    return false;
  } 
  forn(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    g[a].pb(mp(b, c));
  }
  return true;
}

int id[MAXN][MAXN];
Graph G;

bool can(ld M) {
  forn(i, n) for (auto e : g[i]) {
    G.change(id[i][e.fst], min(floor(e.snd / M), (ld) x));
//    printf("%d->%d ---> %d\n", i + 1, e.fst + 1, (int) floor(e.snd / M));
  } 
  return G.max_flow(x);
}

void precalc() {
  memset (id, -1, sizeof id);
  G = Graph(n);
  forn(i, n) for (auto e : g[i]) {
    id[i][e.fst] = G.addE(i, e.fst, 0);
  }
}

ld solve() {
  precalc();

  ld L = 1 / 1e6;
  ld R = 1e6 + 10;
  forn(it, 60) {
    ld M = (L + R) / 2;
    if  (can(M)) {
      L = M;
    } else {
      R = M;
    }
  }
  return L * x;
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    printf("%.10f\n", (double) solve());
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}