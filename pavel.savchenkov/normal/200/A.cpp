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
#define left Fuck
#define right FuckFuck
#define rotate FuckFuckFuck

const double eps = 1e-9;
const int int_inf = 1 << 30 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

struct DSU
{
    int par[2001];
    int sz[2001];
    int left[2001];
    int right[2001];

    DSU(int n = 0) { forn(i, n) sz[i] = 1, left[i] = right[i] = par[i] = i; };

    int get_set(int x)
    {
        return (par[x] == x) ? x : par[x] = get_set(par[x]);
    }

    void union_set(int x, int y)
    {
        x = get_set(x);
        y = get_set(y);
        if  (x == y) return;
        if  (sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        left[y] = min(left[y], left[x]);
        right[y] = max(right[y], right[x]);
    }
};

int n, m, k;
bool used[2000][2000];
DSU a[2000];
bool rotate;

void upd(int x, int y, int newx, int newy, int & resx, int & resy)
{
  if  (newx < 0 || newx >= n || used[newx][newy]) return;
  int newd = abs(x - newx) + abs(y - newy);
  int oldd = abs(x - resx) + abs(y - resy);
  if  (newd < oldd) { resx = newx; resy = newy; }
  if  (newd != oldd) return;

  if  (!rotate)
  {
   if  (newx < resx) { resx = newx; resy = newy; }
   if  (newx != resx) return;
   if  (newy < resy) { resx = newx; resy = newy; }
   return;
  }

   if  (newy < resy) { resx = newx; resy = newy; }
   if  (newy != resy) return;
   if  (newx < resx) { resx = newx; resy = newy; }
}


pii go(int x, int y)
{
    int resx = int_inf; int resy = int_inf;
    int maxd = max(n - x, x);

    for (int d = 0; d <= maxd; d++)
    {
        int newx = x + d;
        if  (newx - x > abs(resx - x) + abs(resy - y)) break;
        upd(x, y, newx, y, resx, resy);
        if  (newx >= 0 && newx < n && used[newx][y] && a[newx].left[ a[newx].get_set(y) ] != 0)
         upd(x, y, newx, a[newx].left[ a[newx].get_set(y) ] - 1, resx, resy);
        if  (newx >= 0 && newx < n &&used[newx][y] && a[newx].right[ a[newx].get_set(y) ] != m - 1)
         upd(x, y, newx, a[newx].right[ a[newx].get_set(y) ] + 1, resx, resy);

        newx = x - d;
        if  (x - newx > abs(resx - x) + abs(resy - y)) break;
        upd(x, y, newx, y, resx, resy);
        if  (newx >= 0 && newx < n && used[newx][y] && a[newx].left[ a[newx].get_set(y) ] != 0)
         upd(x, y, newx, a[newx].left[ a[newx].get_set(y) ] - 1, resx, resy);
        if  (newx >= 0 && newx < n && used[newx][y] && a[newx].right[ a[newx].get_set(y) ] != m - 1)
         upd(x, y, newx, a[newx].right[ a[newx].get_set(y) ] + 1, resx, resy);
    }

    assert(resx != int_inf && resy != int_inf);
    used[resx][resy] = 1;
    if  (resy != m - 1 && used[resx][resy + 1]) a[resx].union_set(resy, resy + 1);
    if  (resy != 0 && used[resx][resy - 1]) a[resx].union_set(resy, resy - 1);

    return mp(resx, resy);
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  memset(used, 0, sizeof used);

  rotate = (n > m);
  if  (rotate) swap(n, m);

  forn(i, n)
   a[i] = DSU(m);

  forn(i, k)
  {
      int x, y; scanf("%d%d", &x, &y); --x; --y;
      if  (rotate) swap(x, y);
      pii r = go(x, y);
      if  (rotate) swap(r.f, r.s);
      printf("%d %d\n", r.f + 1, r.s + 1);
  }

  return 0;
}