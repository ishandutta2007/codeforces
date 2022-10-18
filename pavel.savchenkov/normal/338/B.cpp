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

vi g[MAXN];
int n, m, d;
bool good[MAXN];
int ans = 0;
int max_depth[MAXN];

void pre_dfs (int v, int p) {
  max_depth[v] = -1;

  if  (good[v])
    max_depth[v] = 0;

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to != p) {
      pre_dfs(to, v);
      if  (max_depth[to] != -1)
        max_depth[v] = max(max_depth[v], max_depth[to] + 1);
    }
  }
}

void dfs (int v, int p, int max_dist) {
  if  (max(max_depth[v], max_dist) <= d)
    ans++;

  int max_depth1 = -1;
  int max_depth2 = -1;
  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to == p)
      continue;

    if  (max_depth[to] > max_depth1) {
      max_depth2 = max_depth1;
      max_depth1 = max_depth[to];
    } else if  (max_depth[to] > max_depth2) {
      max_depth2 = max_depth[to];
    }
  }

  if  (max_dist == -1 && good[v])
    max_dist = 0;

  forn(i, sz(g[v])) {
    int to = g[v][i];

    if  (to == p)
      continue;

    int ndist = (max_dist == -1) ? -1 : max_dist + 1;

    if  (max_depth[to] == max_depth1) {
      if  (max_depth2 != -1)
        ndist = max(ndist, max_depth2 + 2);
    } else {
      if  (max_depth1 != -1)
        ndist = max(ndist, max_depth1 + 2);
    }

    dfs(to, v, ndist);
  }                    
}

int main() {
  scanf("%d%d%d", &n, &m, &d);
  
  memset (good, false, sizeof good);
  forn(i, m) {
    int p;
    scanf("%d", &p);
    p--;
    good[p] = true;
  }

  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  pre_dfs(0, -1);
  dfs(0, -1, -1);

  printf("%d\n", ans);
  return 0;
}