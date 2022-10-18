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
const int ITER = 1000;

using namespace std;

int a[10000];
int n, sum = 0;
double k;

bool can(double x)
{
  double res = sum - k * x; res /= (double)n;
  double cursum = 0.0;
  forn(i, n)
   x -= max(0.0, a[i] - res);

  return x >= 0;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%lf", &n, &k); k *= 0.01;
  forn(i, n) scanf("%d", &a[i]), sum += a[i];

  double l = 0.0; double r = sum; int it = 0;
  while (it < ITER)
  {
      double m = (l + r) * 0.5;
      if  (can(m)) r = m; else l = m;
      it++;
  }

  double res = sum - k * r;
  res /= (double)n;

  printf("%.10lf\n", res);
  return 0;
}