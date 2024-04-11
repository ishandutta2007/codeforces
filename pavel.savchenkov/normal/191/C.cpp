//HACK ME, PLEASE! ^_^
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>

#define pb push_back
#define i64 long long
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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

struct tree
{
  vector <int> t;
  int sz;

  tree(int _sz)
  {
      for (int i = 1; ; ++i)
       if  (1 << i >= _sz)
       {
           sz = 1 << i; break;
       }
      t.assign(sz + sz, 0);
  };

  void inc(int v, int tl, int tr, int l, int r)
  {
       if  (l == tl && r == tr) { t[v]++; return; }
       int tm = (tl + tr) >> 1;
       if  (tm >= r) inc(v + v, tl, tm, l, r); else
        if (tm < l) inc(v + v + 1, tm + 1, tr, l, r);
         else
         {
             inc(v + v, tl, tm, l, tm);
             inc(v + v + 1, tm + 1, tr, tm + 1, r);
         }
  };

  int get(int v, int tl, int tr, int id)
  {
      if  (tl == tr) return t[v];
      int tm = (tl + tr) >> 1;
      if  (id <= tm) return get(v + v, tl, tm, id) + t[v];
      return get(v + v + 1, tm + 1, tr, id) + t[v];
  };

  int get(int id)
  {
      return get(1, 0, sz - 1, id);
  };

  void inc(int l, int r)
  {
      inc(1, 0, sz - 1, l, r);
  };

};

vi g[100500];
vi num[100500];
int numb[100500];
int ans[100500];
int sz[100500];
int par[100500];
bool heavy[100500];
int id[100500];
int path[100500];
int last[100500];
int tin[100500];
int tout[100500];
int pr[100500][30];
int LogN = 1;

int timer = 0;

vector <tree> paths;

int n;

void dfs(int v, int p = -1)
{
    par[v] = p;
    sz[v] = 1;
    tin[v] = timer++;

    if (p == -1) pr[v][0] = 0; else pr[v][0] = p;
    for (int i = 1; i <= LogN; i++)
     pr[v][i] = pr[ pr[v][i-1] ][i - 1];
    
    int msz = -1; int SZ = 0;
    
    forn(i, g[v].size())
    {
        int to = g[v][i];
        if  (to == p) continue;
        dfs(to, v);
        numb[to] = num[v][i];
        sz[v] += sz[to];
        if  (sz[to] > SZ) msz = i, SZ = sz[to];
    }
    tout[v] = timer++;
    
    if  (msz == -1) return;
    int to = g[v][msz];
    heavy[to] = 1;
}

void build_path(int i)
{
   int len = 0;
   path[i] = (int)paths.size();
   int j = i;
   int Last;

   while (j != -1)
   {
    if  (heavy[j])
    {
      path[j] = path[i], id[j] = len;
      if  (par[j] == 0) Last = j, j = -1; else  j = par[j], len++;
    } else
              path[j] = path[i], id[j] = len, Last = j, j = -1;
   }

   paths.pb( tree(len + 2) );

   last[i] = Last;
   j = i;
   while (j != -1)
   {
     if  (heavy[j])
     {
       last[j] = Last;
       if  (!par[j]) j = -1; else j = par[j];
     } else last[j] = Last, j = -1;
   }

}


void build_paths(int v, int p = -1)
{
 forn(i, g[v].size())
  if  (g[v][i] != p) build_paths(g[v][i], v);
 
 if  (path[v] == -1 && v) build_path(v);
}

bool upper(int a, int b)
{
  return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b)
{
 if  (upper(a, b)) return a;
 if  (upper(b, a)) return b;

 for (int i = LogN; i>=0; i--)
  if  ( ! upper(pr[a][i], b) )
   a = pr[a][i];

 return pr[a][0];
}

void inc(int a, int b)
{
 if  (a == b) return;
 if  (!b || a == b) return;

 if  (path[a] == path[b] && a != 0)
 {
     int p = path[a];
     paths[p].inc(id[b], id[a] - 1);
     return;
 }


 int p = path[b];
 paths[p].inc(id[b], (int)paths[p].sz - 1);
 inc(a, par[last[b]]);
}

int main() {
  memset(heavy, 0, sizeof heavy);
  memset(path, -1, sizeof path);
  memset(pr, 0, sizeof pr);
  heavy[0] = 0;

  cin >> n;
  while (1 << LogN <= n) LogN++;
  forn(i, n - 1)
  {
      int u, v; scanf("%d%d", &u, &v); u--; v--;
      g[u].pb(v);
      g[v].pb(u);
      num[u].pb(i);
      num[v].pb(i);
  }

  dfs(0);
  build_paths(0);

  int k; cin >> k;

  forn(i, k)
  {
      int a, b;
      scanf("%d%d", &a, &b); a--; b--;
      int LCA = lca(a, b);
      inc(LCA, a);
      inc(LCA, b);
  }

  foran(i, 1, n)
   ans[numb[i]] = paths[ path[i] ].get( id[i] );

  forn(i, n - 1)
   printf("%d ", ans[i]);
  return 0;
}