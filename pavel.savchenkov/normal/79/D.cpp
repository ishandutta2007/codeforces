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
#include <assert.h>

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
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int n, k, l;
int x[20];
int a[110];

vi g[10010];
int d[25][25];
int dest[10010];

bool b[10010];
bool c[10010];

vi marks;

int dp[1 << 22];
bool was[1 << 22];

int calc(int mask)
{
  if  (was[mask]) return dp[mask];
  was[mask] = 1;
  if  (mask == 0) return dp[0] = 0;
  vi bit;
  for (int i = 0; i < 25; i++)
   if  (mask & (1 << i)) bit.pb(i);

  int res = int_inf;
  int v1 = 0;
  for (int v2 = 1; v2 < (int)bit.size(); v2++)
   {
       int nmask = mask;
       nmask ^= 1 << bit[v1];
       nmask ^= 1 << bit[v2];
       int ans = calc(nmask);
       if  (ans >= int_inf) continue;
       res = min(res, ans + d[bit[v1]][bit[v2]]);
   }
   return dp[mask] = res;
}

int main() {
  cin >> n >> k >> l;
  forn(i, k) scanf("%d", &x[i]);
  forn(i, l) scanf("%d", &a[i]);

  forn(i, l)
   for (int j = 0; j <= n - a[i]; j++)
    g[j].pb(j + a[i]), g[j + a[i]].pb(j);

  memset(c, 0, sizeof c);
  forn(i, k)
   c[x[i]] = 1;
  forn(i, n + 1)
   b[i] = (c[i] != c[i + 1]);
  forn(i, n + 1) if  (b[i]) marks.pb(i);

  forn(i, marks.size())
  {
      forn(j, n + 1) dest[j] = int_inf;
      dest[marks[i]] = 0;
      queue <int> q;
      q.push(marks[i]);
      while (!q.empty())
      {
          int v = q.front();
          q.pop();
          forn(j, g[v].size())
           if  (dest[ g[v][j] ] > dest[v] + 1) { dest[ g[v][j] ] = dest[v] + 1; q.push(g[v][j]); }
      }
      forn(j, marks.size())
       d[i][j] = dest[ marks[j] ];
  }

  memset(was, 0, sizeof was);

  int all = 1 << (int) marks.size(); all--;

  if  (calc(all) >= int_inf)
   puts("-1"); else printf("%d\n", calc(all));

  return 0;
}