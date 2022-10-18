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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

int n;
vector <int> g[MAXN];
LL V[MAXN];
LL up[MAXN];
LL down[MAXN];

LL x[MAXN];
int szx;

void dfs(int v, int p = -1) {
  up[v] = down[v] = 0;

  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];

    if  (to != p)
      dfs(to, v);
  }

  szx = 0;
  for (int i = 0; i < sz(g[v]); i++)
    if  (g[v][i] != p) x[szx++] = up[g[v][i]];

  sort(x, x + szx);

  LL cur = 0;
  for (int i = 0; i < szx; i++) {
    up[v] += x[i] - cur;
    cur = x[i];
  }


  szx = 0;
  for (int i = 0; i < sz(g[v]); i++)
    if  (g[v][i] != p) x[szx++] = down[g[v][i]];

  sort(x, x + szx);

  cur = 0;
  for (int i = 0; i < szx; i++) {
    down[v] += x[i] - cur;
    cur = x[i];
  }


  V[v] += up[v] - down[v];

  if  (V[v] > 0)
    down[v] += V[v];
  else
    up[v] += -V[v];

//  printf("in %d up = %I64d down = %I64d\n", v, up[v], down[v]);
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int a, b; scanf("%d%d", &a, &b);
    a--; b--;
    g[a].pb(b); g[b].pb(a);
  }

  for (int i = 0; i < n; i++)
    scanf("%I64d", &V[i]);

  dfs(0);

  printf("%I64d\n", up[0] + down[0]);
  return 0;
}