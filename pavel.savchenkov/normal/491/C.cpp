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
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
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
const int MAXN = 2e6 + 5;

int code(char c) {
  if  ('a' <= c && c <= 'z') {
    return c - 'a';
  }
  return (c - 'A') + 26;
}

char decode(int c) {
  if  (c < 26) {
    return 'a' + c;
  }
  return 'A' + (c - 26);
}

int k;

struct Edge {
  int v, to, cap, cost, flow;
};

struct Graph {
  vector<Edge> e;
  vector<vi> g;
  int n;

  Graph() {}

  Graph(int n) : n(n) {
    g.resize(n);
  }

  void AddE(int v, int to, int cost) {
//    printf("%d -> %d, c = %d\n", v, to, cost);
    g[v].pb(sz(e));
    e.pb({v, to, 1, cost, 0});

    g[to].pb(sz(e));
    e.pb({to, v, 0, -cost, 0});
  }

  int AddFlow() {
    vi dist(n, (int)2e9);
    vi prev(n, -1);

    dist[0] = 0;

    forn(_, n + 5) {
      forn(id, sz(e)) {
        auto E = e[id];

        if  (E.cap > E.flow) {
          if  (dist[E.v] + E.cost < dist[E.to]) {
            dist[E.to] = dist[E.v] + E.cost;
            prev[E.to] = id;
          }
        }
      } 
    }

    if  (prev[n - 1] == -1) {
      return 0;
    }

    int add = 2e9;
    int v = n - 1;
    while (prev[v] != -1) {
      int id = prev[v];
      add = min(add, e[id].cap - e[id].flow);
      v = e[id].v;   
    }

//    printf("add = %d\n", add);
    v = n - 1;
    while (prev[v] != -1) {
      int id = prev[v];
      e[id].flow += add;
      e[id ^ 1].flow -= add;
      v = e[id].v;
    }

    return add;
  }

  void Go() {
    int F = 0;
    while (1) {
      int add = AddFlow();
      if  (!add) break;
      F += add;  
    }

    int res = 0;

    for (int v = 1; v <= k; ++v) {
      for (int id : g[v]) {
        if  (e[id].to && e[id].flow) {
          res += -e[id].cost;
//          printf("ok %d -> %d\n", v, e[id].to);
//          printf("%c", decode(e[id].to - k - 1));
          break;
        }
      }
    }

    cout << res << endl;

    for (int v = 1; v <= k; ++v) {
      for (int id : g[v]) {
        if  (e[id].to && e[id].flow) {
          printf("%c", decode(e[id].to - k - 1));
          break;
        }
      }
    }

    puts("");
  }
};

int n;
char s[MAXN];
char t[MAXN];

int cost[60][60];

Graph G;

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  cin >> n >> k;
  scanf("\n");

  gets(s);
  gets(t);

  G = Graph(1 + k + k + 1);

  for (int i = 1; i <= k; ++i) {
    G.AddE(0, i, 0);
  }

  for (int i = k + 1; i <= k + k; ++i) {
    G.AddE(i, 1 + k + k, 0);
  }

  forn(i, n) {
    ++cost[code(s[i])][code(t[i])];  
  }

  forn(i, k) {
    forn(j, k) {
      G.AddE(1 + i, 1 + k + j, -cost[i][j]);
    }
  }

  G.Go();

  return 0;
}