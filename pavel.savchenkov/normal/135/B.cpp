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

bool norm_angle(int x1, int y1, int x2, int y2, int x3, int y3)
{
  x1 -= x2;
  y1 -= y2;
  x3 -= x2;
  y3 -= y2;
  return !( x1 * x3 + y1 * y3 );
}

bool isREC(vii v)
{
    forn(i, 4)
     if  (!norm_angle(
                      v[i].f, v[i].s,
                      v[(i + 1) % 4].f, v[(i + 1) % 4].s,
                      v[(i + 2) % 4].f, v[(i + 2) % 4].s
                      )
         ) return 0;

    return 1;
}

int len(pii a, pii b)
{
 int x1 = a.f; int y1 = a.s;
 int x2 = b.f; int y2 = b.s;
 return sqr(x2 - x1) + sqr(y2 - y1);
}

bool isSQR(vii v)
{
    if  (!isREC(v)) return 0;
    int len1 = len(v[1], v[2]);
    int len2 = len(v[2], v[3]);
    return len1 == len2;
}

pii a[10];
int b[10];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  forn(i, 8)
   scanf("%d%d", &a[i].f, &a[i].s);

  forn(i, 8) b[i] = i;

  do
  {
      vii v1;
      forn(i, 4) v1.pb(a[b[i]]);
      vii v2;
      foran(i, 4, 8) v2.pb(a[b[i]]);
      if  (isSQR(v1) && isREC(v2))
       {
           puts("YES");
           forn(i, 4) printf("%d ", b[i] + 1); puts("");
           foran(i, 4, 8) printf("%d ", b[i] + 1);
           return 0;
       }
  } while (next_permutation(b, b + 8));

  puts("NO");
  return 0;
}