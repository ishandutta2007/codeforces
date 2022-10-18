#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define all(A) A.begin(), A.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;
const int INF = int(1e9);

class my_dsu {
  vi par;
  vi leader;
  vi sz;

  public:
  my_dsu (int n = 0) {
    par.assign(n, 0);
    leader.assign(n, 0);
    sz.assign(n, 0);

    forn(i, n) {
      par[i] = leader[i] = i;
      sz[i] = 1;
    }
  }

  int get_set (int x) {
    return par[x] == x ? x : par[x] = get_set(par[x]);
  }

  void union_set (int x, int y, int newLeader) {
    x = get_set(x);
    y = get_set(y);

    if  (x == y)
      return;

    if  (sz[x] > sz[y])
      swap(x, y);

    par[x] = y;
    sz[y] += sz[x];
    leader[y] = newLeader;
  }

  int get_leader (int x) {
    return leader[get_set(x)];
  }
};

vi g[MAXN];
int n, m;
int ans[MAXN];
int down[MAXN];
bool red[MAXN];
int depth[MAXN];
bool inq[MAXN];
queue <int> q;

int fast_min (int a, int b) {
  return (((b - a) >> (32-1)) & (a ^ b)) ^ a;
}

void dfs (int v, int p, int dist) {
  ans[v] = fast_min(dist, down[v]);
  if  (red[v])
    dist = 0;
  
  int min1 = INF;
  int min2 = INF;
  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to == p)
      continue;

    if  (down[to] < min1) {
      min2 = min1;
      min1 = down[to];
    } else if  (down[to] < min2) {
      min2 = down[to];
    }
  }

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to == p)
      continue;

    if  (down[to] == min1)
      dfs(to, v, fast_min(dist + 1, min2 + 2));
    else
      dfs(to, v, fast_min(dist + 1, min1 + 2));
  }  
}

void down_dfs (int v, int p) {
  down[v] = red[v] ? 0 : INF;

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to != p) {
      down_dfs(to, v);
      down[v] = fast_min(down[v], down[to] + 1);
    }
  }
}

void push (int v) {
  if  (inq[v])
    return;

  q.push(v);
  inq[v] = true;
}

int pop () {
  int v = q.front();
  q.pop();
  inq[v] = false;
  return v;  
}

void recalc () {
  while (!q.empty()) {
    int v = pop();

    forn(i, sz(g[v])) {
      int to = g[v][i];

      if  (ans[to] > ans[v] + 1) {
        ans[to] = ans[v] + 1;
        push(to);
      }
    }
  }
}

void pre_dfs (int v, int p, int de) {
  depth[v] = de;

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to != p)
      pre_dfs(to, v, de + 1);
  }
}

int query[MAXN];
my_dsu dsu;
bool was[MAXN];
vector <pii> toLca[MAXN];

void addE (int a, int b, int id) {
  toLca[a].pb(mp(b, id));
  toLca[b].pb(mp(a, id));
}

void lca_dfs (int v, int p) {
  was[v] = true;

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to == p)
       continue;

    lca_dfs(to, v);
    dsu.union_set(v, to, v);
  }

  forn(i, sz(toLca[v])) {
    int u = toLca[v][i].f;
    int id = toLca[v][i].s;

    if  (was[u]) {
      int lca = dsu.get_leader(u);

      query[id] = fast_min(query[id], (depth[v] - depth[lca]) + (depth[u] - depth[lca]));
    }
  } 
}

int t[MAXN];
int v[MAXN];

int main() {
  scanf("%d%d", &n, &m);

  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  memset (inq, 0, sizeof inq);
  pre_dfs(0, 0, 0);

  forn(i, n)
    ans[i] = INF;

  push(0);
  ans[0] = 0;
  recalc();
 
  int first = 0;
  int sqrtM = 1;
  while (sqrtM * sqrtM <= m) sqrtM++;

  forn(i, m) {
    scanf("%d%d", &t[i], &v[i]);
    v[i]--;

    if  (i == m - 1 || i - first + 1 == sqrtM) {
      for (int jj = first; jj <= i; jj++)
        if  (t[jj] == 2) {
          query[jj] = ans[v[jj]];

          for (int ii = first; ii < jj; ii++)
            if  (t[ii] == 1) {
              int q_v = v[jj];
              int red_v = v[ii];

              addE(q_v, red_v, jj);
            }
        }

      for (int ii = first; ii <= i; ii++)
        if  (t[ii] == 1) {
          ans[v[ii]] = 0;
          push(v[ii]);
        }

      first = i + 1;

      recalc();
    }
  }


  dsu = my_dsu(n);
  memset (was, 0, sizeof was);

  lca_dfs(0, 0);

  forn(i, m)
    if  (t[i] == 2)
      printf("%d\n", query[i]);
  return 0;
}