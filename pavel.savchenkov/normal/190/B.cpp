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

int x[2];
int y[2];
int r[2];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  forn(i, 2)
    cin >> x[i] >> y[i] >> r[i];
  
  if (r[0] < r[1]) { swap(x[0], x[1]); swap(y[0], y[1]); swap(r[0], r[1]); }
  
  if ( sqr(x[0] - x[1]) + sqr(y[0] - y[1]) <= sqr(r[0]) - 2 * r[0] * r[1] + sqr(r[1]))
   {
    double d = sqr(x[0] - x[1]) + sqr(y[0] - y[1]);
    d = sqrt(d);
    d = r[0] - d;
    d -= r[1];
    d *= 0.5;
    printf("%.20lf\n",d);
    return 0;
   }
  if ( sqr(x[0] - x[1]) + sqr(y[0] - y[1]) <= sqr(r[0]) + 2 * r[0] * r[1] + sqr(r[1]))
    { puts("0.000000000"); return 0; }
  
  double d = sqr(x[0] - x[1]) + sqr(y[0] - y[1]);
  d = sqrt(d);
  d -= r[0] + r[1];
  d *= 0.5;
  
  printf("%.20lf\n",d);
  return 0;
}