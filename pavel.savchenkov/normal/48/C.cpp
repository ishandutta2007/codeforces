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

int a[1000];
int n;
double b, c;

int go(double d)
{
    int r = 0;
    double x = (double) n * d - (double)a[n - 1] + d;
    while (x > 1.0 - 1e-9) r++, x -= 1.0;
    return r;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);
  b = (double)a[0]; c = b + 1.0;

  for (int i = 1; i < n; i++)
  {
   b = max(b, (double)a[i] / (i + 1));
   c = min(c, (double)(a[i] + 1) / (i + 1));
  }

//  printf("%.10lf %.10lf\n", b, c);

  int r1 = go(b);
  int r2 = go(c - 1e-9);
  if  (r1 == r2)
  {
      puts("unique");
      printf("%d\n", a[n - 1] + r1);
  } else puts("not unique");

  return 0;
}