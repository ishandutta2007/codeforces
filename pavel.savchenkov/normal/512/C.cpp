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
const int INF = 1e9;

struct Edge {
  int v, to, cap, flow;
};

struct Graph {
  vector<Edge> es;
  vvi g;
  int n;

  Graph(int n) : n(n) {
    g.resize(n);
  }

  void addE(int v, int to, int cap) {
    g[v].pb(sz(es));
    es.pb({ v, to, cap, 0 });

    g[to].pb(sz(es));
    es.pb({ to, v, 0, 0 });
  }

  int push() {
    vi dist(n, INF);
    vi prev(n, -1);
    
    vi q(3 * n);
    int ql = 0;
    int qr = 0;
    dist[0] = 0;
    q[qr++] = 0;

    while (ql < qr) {
      int v = q[ql++];

      for (int id : g[v]) {
        int to = es[id].to;
        int rest = es[id].cap - es[id].flow;

        if  (rest > 0 && dist[to] > dist[v] + 1) {
          dist[to] = dist[v] + 1;
          prev[to] = id;
          q[qr++] = to;
        }
      }
    }

    if  (dist[n - 1] >= INF) {
      return 0;
    }

    int f = INF;
    int v = n - 1;
    while (v) {
      int id = prev[v];
      f = min(f, es[id].cap - es[id].flow);
      v = es[id].v;  
    }

    v = n - 1;
    while (v) {
      int id = prev[v];
      
      es[id].flow += f;
      es[id ^ 1].flow -= f;

      v = es[id].v;
    }

    return f;
  }

  int max_flow() {
    int F = 0;

    while (1) {
      int cur = push();
      if  (!cur) {
        break;
      }
      F += cur;
    }      

    return F;
  }

  void dfs(int v, vector<char>& used, vi& who) {
    used[v] = true;
    who.pb(v);

    for (int id : g[v]) {
      int to = es[id].to;
      int rest = v <= (n - 2) / 2 ? es[id].cap - es[id].flow : es[id ^ 1].cap - es[id ^ 1].flow;

      if  (to == 0 || to == n - 1) {
        continue;
      }

      if  (rest == 0 && !used[to]) {
        dfs(to, used, who);
      }
    }
  }

  vvi restore() {        
    vector<char> used(n, false);
    vvi res;
    for (int v = 1; v <= (n - 2) / 2; ++v) {
      vi cur;
      dfs(v, used, cur);
      if  (sz(cur) >= 3) {
        res.pb(cur);
      }
    }
    return res;
  }                       
};

vi a;
int n;

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  a = vi(n);
  forn(i, n) {
    scanf("%d", &a[i]);
  }

  Graph G(2 * n + 2);

  forn(i, n) {
    if  (a[i] & 1) {
      G.addE(0, i + 1, 2);
    } else {
      G.addE(1 + n + i, 1 + n + n, 2);
    }
  }

  const int MAX = 3e4;
  vector<char> pr(MAX, true);
  for (int i = 2; i < MAX; ++i) {
    if  (pr[i]) {
      for (int j = i + i; j < MAX; j += i) {
        pr[j] = false;
      }
    }
  }

  forn(i, n) {
    if  (a[i] & 1) {
      forn(j, n) {
        if  (pr[a[i] + a[j]]) {
          G.addE(1 + i, 1 + n + j, 1);  
        } 
      }
    }
  }

  int Flow = G.max_flow();
  if  (Flow != n) {
    puts("Impossible");
    return 0;
  }

  auto paths = G.restore();
  printf("%d\n", sz(paths));
  forn(i, sz(paths)) {
    printf("%d ", sz(paths[i]));
    for (int x : paths[i]) {
      if  (x >= 1 + n) {
        x -= 1 + n;
      } else {
        --x;
      }
      printf("%d ", x + 1);
    }
    puts("");
  }


  return 0;
}