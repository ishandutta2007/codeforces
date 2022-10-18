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
const int INF = 1e9;
const int MAXN = 12345 + 10;

struct Edge {
  int v, to, cap, flow;
};

int d[MAXN];
int Q[MAXN];
int ql, qr;
int prev[MAXN];

struct Graph {
  vector<Edge> es;
  vvi g;
  int n;

  Graph(int n = 0) : n(n) {
    g.resize(n);
  }

  void addE(int v, int to, int cap) {
    g[v].pb(sz(es));
    es.pb({ v, to, cap, 0 });

    g[to].pb(sz(es));
    es.pb({ to, v, 0, 0 });
  }

  int add_flow() {
    forn(v, n) {
      d[v] = INF;
    }
    d[0] = 0;
    ql = qr = 0;
    Q[qr++] = 0;
    while (ql != qr) {
      int v = Q[ql++];
      for (int id : g[v]) {
        if  (es[id].cap > es[id].flow && d[es[id].to] > d[v] + 1) {
          d[es[id].to] = d[v] + 1;
          Q[qr++] = es[id].to;
          prev[es[id].to] = id;
        }
      }
    }

    if  (d[n - 1] >= INF) {
      return 0;
    }

    int v = n - 1;
    int add = INF;
    while (v) {
      int id = prev[v];
      add = min(add, es[id].cap - es[id].flow);
      v = es[id].v;
    }

    v = n - 1;
    while (v) {
      int id = prev[v];
      es[id].flow += add;
      es[id ^ 1].flow -= add;
      v = es[id].v;
    }

    return add;
  }

  int max_flow() {
    int f = 0;
    while (1) {
      int cur = add_flow();
      if  (!cur) {
        break;
      }
      f += cur;
    }
    return f;
  }

  vvi restore() {
    int N = (n - 2) / 2;
    vvi ans(N, vi(N, 0));
    forn(v, n) {
      if  (!(1 <= v && v <= N)) {
        continue;
      }
      for (int id : g[v]) {
        int to = es[id].to;
        if  (!(1 + N <= to && to < 1 + N + N)) {
          continue;
        }
        int add = es[id].flow;
        ans[v - 1][to - N - 1] += add;
      }
    }

    return ans;
  }
};

int a[MAXN];
int b[MAXN];

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int n, m;
  scanf("%d%d", &n, &m);

  forn(i, n) {
    scanf("%d", &a[i]);
  }
  forn(i, n) {
    scanf("%d", &b[i]);
  }

  Graph g(2 * n + 2);
  forn(v, n) {
    g.addE(0, v + 1, a[v]);
    g.addE(n + v + 1, n + n + 1, b[v]);
  }

  forn(i, m) {
    int p, q;
    scanf("%d%d", &p, &q);
    --p;
    --q; 
    g.addE(p + 1, q + n + 1, INF);
    g.addE(q + 1, p + n + 1, INF);
  }
  forn(v, n) {
    g.addE(v + 1, v + n + 1, INF);
  }

  int f = g.max_flow();
  if  (f != accumulate(b, b + n, 0) || accumulate(a, a + n, 0) != accumulate(b, b + n, 0)) {
    puts("NO");
    return 0;
  }

  auto ans = g.restore();
  forn(i, n) {
    int in = 0;
    int out = 0;
    forn(j, n) {
      in += ans[j][i];
      out += ans[i][j];
    }

    //assert(a[i] - out + in == b[i]);
//    ans[i][i] = a[i] - out;
    /*
    if  (ans[i][i] < 0) {
      puts("NO");
      return 0;
    }
    */
  }

  puts("YES");
  forn(i, n) {
    forn(j, n) printf("%d ", ans[i][j]);
    puts("");
  }


  return 0;
}