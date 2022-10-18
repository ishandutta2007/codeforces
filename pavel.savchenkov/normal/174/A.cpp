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

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
double a[200];
int n; double b;
double c[200];
double ma = -1.0 ,mi = 100.0;


int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> b;
  forn(i,n) { cin >> a[i]; ma = max(ma,a[i]); mi = min(mi,a[i]); }
  
  forn(i,n) { c[i] = ma - a[i]; b -= c[i]; }
  
  if (b < 0) { puts("-1"); return 0; }
  
  double de = (double) b / n;
  
  forn(i,n)
    printf("%.10lf\n",c[i] + de);
  return 0;
}