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
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

struct segm_tree
{
  vector <vi> t;
  int sz;

  segm_tree() {}

  segm_tree(const vi & a)
  { 
   sz = 1; while (sz < (int)a.size()) sz *= 2;
   
   t.assign(sz * 2 + 10, vi());
   build(a, 1, 0, sz - 1);
  }

  void build(const vi & a, int v, int tl, int tr)
  {
   if  (tl == tr) { if  (tl < (int)a.size()) t[v].pb(a[tl]); else t[v].pb(-1); return; }
   int tm = (tl + tr) / 2;
   build(a, v * 2, tl, tm);
   build(a, v * 2 + 1, tm + 1, tr);

   t[v * 2].pb(INT_INF);
   t[v * 2 + 1].pb(INT_INF);
   int t1 = 0, t2 = 0;
   while (t1 != (int)t[v * 2].size() - 1 || t2 != (int)t[v * 2 + 1].size() - 1)
    if  (t[v * 2][t1] < t[v * 2 + 1][t2]) t[v].pb(t[v * 2][t1++]); else t[v].pb(t[v * 2 + 1][t2++]);

   t[v * 2].pop_back();
   t[v * 2 + 1].pop_back();
  }

  int get(int v, int tl, int tr, int l, int r, int val)
  {
   if  (l == tl && r == tr) 
   {
    int pos1 = lower_bound(t[v].begin(), t[v].end(), val) - t[v].begin();
    if  (pos1 == (int)t[v].size()) return 0;
    return upper_bound(t[v].begin(), t[v].end(), val) - t[v].begin() - pos1;
   }

   int tm = (tl + tr) / 2;
   if  (r <= tm) 
    return get(v * 2, tl, tm, l, r, val);
   else
    if  (l > tm) return get(v * 2 + 1, tm + 1, tr, l, r, val);
   else
    return get(v * 2, tl, tm, l, tm, val) + get(v * 2 + 1, tm + 1, tr, tm + 1, r, val);
  }

  int get(int l, int r, int val)
  {
  // printf("get(%d, %d, %d)\n", l, r, val);
   return get(1, 0, sz - 1, l, r, val);
  }
};

int n, m;
vi g[100500];
int first[100500];
int last[100500];
int depth[100500];
vi depths;
int pr[100500][20];
int Log = 1;
vi roots;
segm_tree t;

void dfs(int v, int de = 0, int p = 0)
{
 depths.pb(de);
 depth[v] = de;
 first[v] = (int)depths.size() - 1;
 pr[v][0] = p;
// printf("in %d\n", v);

 for (int i = 1; i <= Log; i++)
  pr[v][i] = pr[ pr[v][i - 1] ][i - 1];

 forn(i, g[v].size())
 {
  int to = g[v][i];
  if  (to == p) continue;
  dfs(to, de + 1, v);
 }

// printf("out %d\n", v);
 depths.pb(de);
 last[v] = (int)depths.size() - 1;
}

int get(int v, int p)
{
 int de = depth[v] - p;

 for (int l = Log; l >= 0; l--)
  if  (depth[ pr[v][l] ] > de) v = pr[v][l];

 return pr[v][0]; 
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  forn(i, n)
   {
    int r; scanf("%d", &r);
    if  (r) g[r - 1].pb(i); else roots.pb(i);
   }
  
  while ((1 << Log) < n) Log++;
  forn(i, roots.size())
   dfs(roots[i]); 


  t = segm_tree(depths);

  cin >> m; puts("");
  forn(i, m)
  {
   int v, p; scanf("%d%d", &v, &p); --v;
   if  (depth[v] < p) { printf("0 "); continue; }
   v = get(v, p);
   printf("%d ", t.get(first[v], last[v], depth[v] + p) / 2 - 1);
  }

  return 0;
}