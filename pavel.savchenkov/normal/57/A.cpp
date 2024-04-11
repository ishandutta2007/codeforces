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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;

int n;

vector <pii> g[20];
int sz = 0;

int x[20];
int y[20];

void adde (int a, int b, int w) {
  g[a].pb(mp(b, w)); g[b].pb(mp(a, w));
}

int d[20];

void dfs (int v) {
  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i].f;
    int w = g[v][i].s;

    if  (d[to] > d[v] + w) {
      d[to] = d[v] + w;
      dfs(to);
    }
  }
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);

  x[0] = 0; y[0] = 0;
  x[1] = 0; y[1] = n;
  x[2] = n; y[2] = n;
  x[3] = n; y[3] = 0;

  adde(0, 1, n);
  adde(1, 2, n);
  adde(2, 3, n);
  adde(3, 0, n);

  for (int i = 4; i <= 5; i++)
    scanf("%d %d", &x[i], &y[i]);

  for (int j = 4; j <= 5; j++)
    for (int i = 0; i < 4; i++) {
      if  (x[i] != x[j] && y[i] != y[j]) continue;

      adde(i, j, abs(x[i] - x[j]) + abs(y[i] - y[j]));
    }

  if  (x[4] == x[5] && (x[4] == 0 || x[4] == n)) {
    printf("%d\n", abs(y[4] - y[5]));
    return 0;
  }

  if  (y[4] == y[5] && (y[4] == 0 || y[4] == n)) {
    printf("%d\n", abs(x[4] - x[5]));
    return 0;
  }

  for (int i = 0; i < 6; i++)
    d[i] = (int) 1e9;

  d[4] = 0;
  dfs(4);

  printf("%d\n", d[5]);
  return 0;      
}