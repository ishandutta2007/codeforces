//#pragma comment (linker, "/STACK:200000000") 
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
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
using namespace std;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  int n; int a[200];
  scanf("%d",&n); foran(i,1,n+1) scanf("%d",&a[i]);
  int sum[200]; memset(sum,0,sizeof(sum));
  sum[0] = 0; a[0] = 0;
  sort(a,a+n+1);
  foran(i,1,n+1) sum[i] = sum[i-1] + a[i];
  
  int s = 0;
  for (int i=n;i>=1;i--)
  {
	s += a[i];
	if (s > sum[i-1]) { printf("%d",n-i+1); return 0; }
  }
  return 0;
}