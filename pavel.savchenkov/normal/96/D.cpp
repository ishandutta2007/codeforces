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

int n, m, x, y;
vii g[1050];

vii gt[1050];

i64 d[1050];

set < pair<i64, int> > s;

int t[1050];
int c[1050];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m >> x >> y; x--; y--;
  forn(i, m)
  {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      u--; v--;
      g[u].pb(mp(v, w));
      g[v].pb(mp(u,w));
  }
  forn(i, n)
   scanf("%d%d", &t[i], &c[i]);

  forn(st, n)
  {

      forn(i, n) d[i] = i64_inf;
      d[st] = 0;
      s.insert( mp(0, st) );
      while (!s.empty())
      {
          int v = s.begin() -> s;
          s.erase(s.begin());
          forn(i, g[v].size())
          {
              int to = g[v][i].f;
              int len = g[v][i].s;
              if (d[to] > d[v] + len)
              {
                  s.erase(mp(d[to], to));
                  d[to] = d[v] + len;
                  s.insert(mp(d[to], to));
              }
          }
      }

      forn(i, n)
       if (d[i] <= t[st] && i != st) gt[st].pb( mp(i, c[st]) );
  }

  forn(i, n)
   d[i] = i64_inf;
  d[x] = 0;

  s.insert( mp(0, x) );

  while (!s.empty())
  {
      int v = s.begin() -> s;
      s.erase(s.begin());
      forn(i, gt[v].size())
      {
          int to = gt[v][i].f;
          int len = gt[v][i].s;
          if (d[to] > d[v] + len)
          {
              s.insert(mp(d[to], to));
              d[to] = d[v] + len;
              s.insert(mp(d[to], to));
          }
      }
  }

  if (d[y] == i64_inf)
   puts("-1"); else
    cout << d[y] << endl;
  return 0;
}