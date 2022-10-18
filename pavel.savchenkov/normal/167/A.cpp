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
/*----------------------------------------------------------------------------------------------*/

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);

using namespace std;
int n; double a,d;
double t[100500]; double v[100500];
double ans[100500];

double go(double v)
{
  double res; 
  double s = (v*v)/(2.0*a);
  res = v / a;
  if (d < s + eps) res = sqrt(2*d/a); else res += (d - s) / v;
  return res;
}


int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  cin >> n >> a >> d;
  forn(i,n)
   scanf("%lf%lf",&t[i],&v[i]);
  ans[0] = t[0] + go(v[0]);
  printf("%.10lf\n",ans[0]);
  
  foran(i,1,n)
  {
    if (t[i]+go(v[i]) + eps > ans[i-1]) 
     ans[i] = t[i]+go(v[i]); else ans[i] = ans[i-1];
    printf("%.10lf\n",ans[i]);
  }
  return 0;
}