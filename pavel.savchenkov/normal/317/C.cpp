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

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 310;

int n, maxV, e;
vi G[MAXN];
set <int> g[MAXN];
int a[MAXN];
int b[MAXN];
bool was[MAXN];
int to_push[MAXN];
bool ready[MAXN];
vi top;

vector < pair <pii, int> > ans;

void dfs (int v) {
  was[v] = true;

  forn(i, sz(G[v])) {
    int to = G[v][i];

    if  (!was[to]) {
      g[v].insert(to);
      g[to].insert(v);
      dfs(to);
    } 
  }
}

void prepare () {
  memset (was, false, sizeof was);

  forn(i, n)
    if  (!was[i])
      dfs(i);
}

void push (int v, int to) {
  int d = min(a[v], maxV - a[to]);

  if  (d == 0)
    return;

  a[v] -= d;
  a[to] += d;
  ans.pb(mp(mp(v, to), d));
}

void push (int v, int to, int d) {
  if  (d == 0 || a[v] - d < 0 || a[to] + d > maxV)
    return;

  a[v] -= d;
  a[to] += d;
  ans.pb(mp(mp(v, to), d));
}

void dfsUp (int v, int p = -1) {
  for (set <int> :: iterator it = g[v].begin(); it != g[v].end(); it++) {
    int to = *it;

    if  (to == p)
      continue;

    dfsUp(to, v);
    push(to, v);
  } 
}

void dfsDown (int v, int p = -1) {
  for (set <int> :: iterator it = g[v].begin(); it != g[v].end(); it++) {
    int to = *it;

    if  (to == p)
      continue;

    dfsDown(to, v);
    push(v, to);
  } 
}

void solve (int leaf) {
  ready[leaf] = true;

  int st = *g[leaf].begin();
  g[st].erase(leaf);

  if  (a[leaf] < b[leaf]) {
    dfsUp(st);
    push(st, leaf, b[leaf] - a[leaf]);
  } else {
    dfsDown(st);
    push(leaf, st, a[leaf] - b[leaf]);
  }
}

int main() {
  scanf("%d %d %d", &n, &maxV, &e);

  forn(i, n)
    scanf("%d", &a[i]);

  forn(i, n)
    scanf("%d", &b[i]);

  forn(i, e) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    G[a].pb(b);
    G[b].pb(a);
  }

  prepare();

  memset (ready, false, sizeof ready);
  while (true) {
    bool wasr = false;
    forn(i, n)
      if  (!ready[i] && sz(g[i]) == 1) {
        solve(i);
        wasr = true;
      }

    if  (!wasr)
      break; 
  }

  forn(i, n)
    if  (a[i] != b[i]) {
      puts("NO");
      return 0;
    }

  printf("%d\n", sz(ans));
  forn(i, sz(ans))
    printf("%d %d %d\n", ans[i].f.f + 1, ans[i].f.s + 1, ans[i].s);
  return 0;
}