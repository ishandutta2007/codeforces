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

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

vii g[100500];
int n, m;
i64 d[100500];
set < pair <i64, int> > s;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d", &n, &m);
  forn(i, m)
  {
      int a, b, w; scanf("%d%d%d", &a, &b, &w);
      a--; b--; g[a].pb(mp(b, w)); g[b].pb(mp(a, w));
  }
  forn(i, n) d[i] = I64_INF;
  d[0] = 0; s.insert(mp(0, 0));

  while (!s.empty())
  {
      int v = s.begin() -> s;
      s.erase(s.begin());
      forn(i, g[v].size())
       if  (d[g[v][i].f] > d[v] + g[v][i].s * 1LL)
       {
           int to = g[v][i].f;
           s.erase(mp(d[to], to));
           d[to] = d[v] + g[v][i].s * 1LL;
           s.insert(mp(d[to], to));
       }
  }

  if  (d[n - 1] == I64_INF) { puts("-1"); return 0; }

  vi res;
  int v = n - 1;
  while (v)
    forn(i, g[v].size())
     if  (d[ g[v][i].f ] == d[v] - g[v][i].s) { res.pb(v); v = g[v][i].f; break; }
  res.pb(0);

  ford(i, res.size())
   printf("%d ", res[i] + 1);
  return 0;
}