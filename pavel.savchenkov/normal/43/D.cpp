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

vii path;
int telep[] = {-1, -1, 0, 0};

void build(int n, int m)
{
//  printf("n = %d m = %d\n", n, m);
  if  (((n & 1) || n == 1) && !(m == 2 && n == 1)) telep[0] = 0, telep[1] = m - 1;

  forn(i, n) path.pb(mp(i, 0));
  foran(i, 1, m) path.pb(mp(n - 1, i));

  int i = n - 2; int j = m - 1;
  while (i > -1)
  {
      if  (j == m - 1)
      {
       for (; j > 0; j--)
        path.pb(mp(i, j));
       j = 1;
       i--;
      }
      else
      {
          for (; j < m; j++)
           path.pb(mp(i, j));
          j = m - 1;
          i--;
      }
  }
}

int n, m;
bool rev = 0;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  if  ((m == 1 || (n & 1)) && (n != 1)) { rev = 1; swap(n, m); }

  build(n, m);

  path.pb(mp(0, 0));

  if  (telep[0] == -1) puts("0");
   else
    if  (!rev)
     { puts("1"); forn(i, 4)  printf("%d ", telep[i] + 1); puts(""); }
    else printf("1\n%d %d %d %d\n", telep[1] + 1, telep[0] + 1, telep[3] + 1, telep[2] + 1);

  forn(i, path.size())
   if  (rev) printf("%d %d\n", path[i].s + 1, path[i].f + 1); else
    printf("%d %d\n", path[i].f + 1, path[i].s + 1);
  return 0;
}