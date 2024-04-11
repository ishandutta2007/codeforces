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

using namespace std;

int g[110][110];
int gt[110][110];
int n, m;
int comp[110];

bool used[110];
bool was[110];
bool was_comp[110];

void dfs_comps(int v)
{
  was[v] = 1;

  forn(i, n)
   if  (g[v][i] != -1 && !was[i])
    comp[i] = comp[v], dfs_comps(i);
}

void dfs(int v)
{
  was[v] = 1;

  forn(to, n)
   if  (g[v][to] != -1)
   {
       if  (was[to]) continue;
       if  (g[v][to] == 0)
        used[to] = !used[v], dfs(to);
       else
        used[to] = used[v], dfs(to);
   }
}

bool go(int v, int use)
{
  memset(was, 0, sizeof was);
  used[v] = use;

  dfs(v);

  forn(i, n)
   forn(j, n)
    gt[i][j] = g[i][j];

  forn(i, n)
   if  (comp[i] == comp[v] && used[i])
    forn(j, n)
     if  (gt[i][j] == 0)
      gt[i][j] = gt[j][i] = 1;
     else
      if  (gt[i][j] == 1)
       gt[i][j] = gt[j][i] = 0;

  bool ok = 1;

  forn(i, n)
   if  (comp[i] == comp[v])
    forn(j, n)
     if  (gt[i][j] == 0) ok = 0;

  return ok;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  memset(g, -1, sizeof g);

  forn(i, m)
  {
      int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
      g[a][b] = c; g[b][a] = c;
  }

  memset(was, 0, sizeof was);
  memset(was_comp, 0, sizeof was_comp);
  int comps = 0;

  forn(i, n)
   if  (!was[i]) { comp[i] = comps++; dfs_comps(i); }

  forn(i, n)
   if  (!was_comp[comp[i]])
    {
        was_comp[comp[i]] = 1;
        if  (!go(i, 0) && !go(i, 1))  { puts("Impossible"); return 0; }
    }

  int r = 0;
  forn(i, n)
   r += used[i];

  printf("%d\n", r);
  forn(i, n)
   if  (used[i]) printf("%d ", i + 1);
  return 0;
}