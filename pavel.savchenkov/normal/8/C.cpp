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

int d[ 1 << 24 ];
bool was[ 1 << 24 ];
int n;
int x[25]; int y[25]; int xs, ys;
int dist[25][25];
int dists[25];

vii res;

int calc(int mask)
{
   if  (was[mask]) return d[mask];
   was[mask] = 1;

   int i;
   for (i = 0; i < n; i++)
    if  (!((1 << i) & mask)) break;

   if  (i == n) return d[mask] = 0;
   d[mask] = 2 * dists[i] + calc(mask | (1 << i));

    for (int j = i + 1; j < n; j++)
     if  (!((1 << j) & mask))
      d[mask] = min(d[mask], calc(mask | (1 << i) | (1 << j)) + dists[i] + dists[j] + dist[i][j]);

   if  (d[mask] == INT_INF)
       d[mask] = 0;

   return d[mask];
}

void restore(int mask)
{
   bool was = 0;

   int i;
   for (i = 0; i < n && !was; i++)
    if  (!((1 << i) & mask))
    {
        if  (d[mask] == 2 * dists[i] + d[mask | (1 << i)])
        {
            was = 1;
            res.pb(mp(i, -1));
            restore(mask | (1 << i));
        }
        break;
    }

    for (int j = i + 1; j < n && !was; j++)
     if  (!((1 << j) & mask) && d[mask] == d[mask | (1 << i) | (1 << j)] + dists[i] + dists[j] + dist[i][j])
      {
          was = 1;
          res.pb(mp(i, j));
          restore(mask | (1 << i) | (1 << j));
      }

}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(was, 0, sizeof was);
  scanf("%d%d", &xs, &ys);
  scanf("%d", &n);
  forn(i, n)
   scanf("%d%d", &x[i], &y[i]);

  forn(i, n)
   forn(j, n)
    dist[i][j] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
  forn(i, n) dists[i] = sqr(xs - x[i]) + sqr(ys - y[i]);

  calc(0);
  restore(0);

  printf("%d\n", d[0]);
  printf("0 ");
  forn(i, res.size())
   if  (res[i].s == -1)
    printf("%d 0 ", res[i].f + 1);
     else
      printf("%d %d 0 ", res[i].f + 1, res[i].s + 1);

  return 0;
}