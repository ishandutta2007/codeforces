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

double a, b, m, vx, vy, vz;
double x0, z0;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> a >> b >> m >> vx >> vy >> vz;
  double d =  -m / vy;
  x0 = a * 0.5 + vx * d;
  z0 = vz * d;

  while (x0 < 0 || x0 > a + EPS)
   if  (x0 < 0) x0 = -x0; else x0 = a - (x0 - a);

  while (z0 < 0 || z0 > b + EPS)
   if  (z0 < 0) z0 = -z0; else z0 = b - (z0 - b);


  printf("%.10lf %.10lf\n", x0, z0);
  return 0;
}