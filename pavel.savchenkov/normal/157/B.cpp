//#pragma comment (linker, "/STACK:200000000") 
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
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int inf = 2000000000;
const double pi = acos(-1.0);
using namespace std;
double res = 0.0;
int n;
double r[200];

int main() {
  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d",&n);
  forn(i,n) { scanf("%lf",&r[i]); r[i] *= r[i]; }
  sort(r,r+n);
  
  bool w = true;
  for (int i=n-1;i>=1;i--) if (w) { res += r[i] - r[i-1]; w = !w; } else w = !w;
  if (w) res += r[0];
  
  printf("%.7lf",pi*res);
  return 0;
}