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
struct point
{
    int x, y, id;
    point() {};
    friend bool operator <(const point & a, const point & b)
    {
        return (i64)a.x * 1ll * b.y - (i64)a.y * 1ll * b.x > 0;
    }
};

vi g[1510];
point p[1510];
int n;
int res[1510];
int sz[1510];
int par[1510];

void dfs(int v, int p = -1)
{
    par[v] = p;
    sz[v] = 1;
    forn(i, g[v].size())
    {
        int to = g[v][i];
        if  (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
    }
}

void go(int l, int r, int v)
{
  int maxy = r;
  for (int i = l; i < r; i++)
   if  (p[i].y > p[maxy].y) maxy = i;
  res[ p[maxy].id ] = v;

  swap(p[l], p[maxy]);

  for (int i = l + 1; i <= r; i++)
   p[i].x -= p[l].x, p[i].y -= p[l].y;

  ++l;
  sort(p + l, p + r + 1);

  forn(i, g[v].size())
  {
      int to = g[v][i];
      if  (to == par[v]) continue;
      go(l, l + sz[to] - 1, to);
      l += sz[to];
  }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n - 1)
  {
      int u, v; scanf("%d%d", &u, &v); u--; v--;
      g[u].pb(v); g[v].pb(u);
  }
  forn(i, n)
   scanf("%d%d", &p[i].x, &p[i].y), p[i].id = i;

  dfs(0);
  go(0, n - 1, 0);

  forn(i, n)
   printf("%d ", res[i] + 1);
  return 0;
}