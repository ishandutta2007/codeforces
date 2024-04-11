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

#define pb push_back
#define i64 long long
#define ui64 unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 0x7FFFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFF;
const double PI = acos(-1.0);
const i64 MOD = (i64)1e9 + 7;

using namespace std;

struct graph
{
  vi g[100500];
  int cntgood[100500];
  bool good[100500];

  int tin[100500];
  int tout[100500];
  int up[100500][20];
  int n;
  int timer;
  int Log;

  graph() { memset(good, 0, sizeof good); }

  void addE(int a, int b) { if  (a != b) g[a].pb(b); if  (a != b) g[b].pb(a); }

  void make_good(int a) { good[a] = 1; }

  bool upper(int a, int b)
  {
    return tin[a] <= tin[b] && tout[b] <= tout[a];
  }

  void dfs(int v, int p = -1)
  {
//    printf("in %d\n", v);
    cntgood[v] = good[v];
    if  (p != -1) cntgood[v] += cntgood[p];

    tin[v] = timer++;
    up[v][0] = max(p, 0);
    for (int i = 1; i <= Log; i++)
     up[v][i] = up[ up[v][i - 1] ][i - 1];

    forn(i, g[v].size())
    {
        int to = g[v][i];
        if  (to == p) continue;
        dfs(to, v);
    }
    tout[v] = timer++;
  }

  void precalc()
  {
      n = 1;
      forn(i, 100400)
       if  (!g[i].empty()) n = i + 1;


      forn(i, n)
      {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
      }

      Log = 1;
      while ((1 << Log) < n) Log++;

      timer = 0;
      dfs(0);
  }

  int lca(int a, int b)
  {
      if  (a == b) return a;
      if  (upper(a, b)) return a;
      if  (upper(b, a)) return b;

      for (int L = Log; L >= 0; L--)
       if  (!upper(up[a][L], b)) a = up[a][L];

      return up[a][0];
  }

  int get(int a, int b)
  {
 //   printf("(a, b) %d %d\n", a, b);
    int v = lca(a, b);
    int pow = cntgood[a] + cntgood[b] - 2 * cntgood[v] + good[v];

    i64 res = 1LL; i64 c = 2LL;
    while (pow)
    {
        if  (pow & 1) res = (res * c) % MOD;
        c = (c * c) % MOD;
        pow /= 2;
    }

    return (int)res;
  }
};

vi g[100500];
int color[100500];
int nums = 0;
int num[100500];
int par[100500];
bool good[100500];
int n, m, k;

void dfs(int v, int p = -1)
{
  color[v] = 1;
  par[v] = p;
  num[v] = -1;

  forn(i, g[v].size())
  {
      int to = g[v][i];
      if  (to == p) continue;

      if  (color[to] == 0)
       dfs(to, v);
      else
      if  (color[to] == 1)
      {
          num[to] = nums; good[nums] = 1;
          int u = v;
          while (u != to) { num[u] = nums; u = par[u]; }
          nums++;
      }
  }

  color[v] = 2;
  if  (num[v] == -1) num[v] = nums++;
}

graph G;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  forn(i, m)
  {
      int a, b; scanf("%d%d", &a, &b); --a; --b;
      g[a].pb(b); g[b].pb(a);
  }

  memset(color, 0, sizeof color);
  memset(good, 0, sizeof good);
  dfs(0);


  forn(i, n)
   forn(j, g[i].size())
    G.addE(num[i], num[ g[i][j] ]);

  forn(i, nums)
   if  (good[i]) G.make_good(i);


  G.precalc();

  cin >> k;
  forn(i, k)
  {
      int a; int b; scanf("%d%d", &a, &b); --a; --b;
      printf("%d\n", G.get(num[a], num[b]));
  }
  return 0;
}