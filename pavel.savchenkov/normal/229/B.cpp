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

vii g[100010];
vi t[100010];
int n, m;
set < pair <i64, int> > s;
i64 d[100010];

int wait(int v, int ti)
{
  if  (t[v].empty()) return 0;
  int pos = lower_bound(t[v].begin(), t[v].end(), ti) - t[v].begin();
  if  (pos == (int)t[v].size() || t[v][pos] != ti) return 0;
  int sz = (int)t[v].size();

  if  (sz - pos + ti - 1 == t[v][sz - 1]) return sz - pos;
  if  (pos == sz - 1 || t[v][pos + 1] != ti + 1) return 1;

  int L = pos; int R = sz;
  while (L != R - 1)
  {
      int M = (L + R) / 2;
      if  (M - pos + ti == t[v][M]) L = M; else R = M;
  }

  return L - pos + 1;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> m;
  forn(i, m)
  {
      int a, b, c; scanf("%d%d%d", &a, &b, &c); --a; --b;
      g[a].pb(mp(b, c)); g[b].pb(mp(a, c));
  }

  forn(i, n)
  {
      d[i] = I64_INF;
      int k; scanf("%d", &k);
      t[i].assign(k, 0);
      forn(j, k)
       scanf("%d", &t[i][j]);
  }

  d[0] = 1LL * wait(0, 0);
  s.insert(mp(d[0], 0));

  while (!s.empty())
  {
      int v = s.begin() -> second;
      s.erase(s.begin());
      if  (d[v] == I64_INF) continue;
      
      forn(i, g[v].size())
      {
          int to = g[v][i].f;
          int w = g[v][i].s;
          if  (d[to] > d[v] + 1LL * w + 1LL * wait(to, d[v] + w))
          {
              s.erase(mp(d[to], to));
              d[to] = d[v] + 1LL * w + 1LL * wait(to, d[v] + w);
              s.insert(mp(d[to], to));
          }
      }
  }

  i64 res = I64_INF;

  forn(i, n)
   forn(j, g[i].size())
    if  (g[i][j].f == n - 1)
     if  (d[i] != I64_INF) res = min(res, d[i] + 1LL * g[i][j].s);

  if  (res == I64_INF)
   puts("-1");
  else
   printf("%I64d\n", res);
  return 0;
}