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
double d[210][210][500];
int n,l,k;
double p[300];
int a[300];

int main() {
  cin >> n >> l >> k;
  foran(i,1,n+1) { int P; scanf("%d",&P); p[i] = (double)P/100.0; }
  foran(i,1,n+1) scanf("%d",&a[i]);
  
  for (int i=0; i<=n; i++)
   for (int j=0; j<=i; j++)
    for (int z=0; z<=n+n; z++)
        d[i][j][z] = 0.0;
  if (k > n) k = n;
  d[0][0][k+n] = 1.0;
  
  for (int i=0; i<n; i++)
  for (int j=0; j<=i; j++)
  for (int z=0; z<=n+n; z++)
  {
   d[i+1][j][z] += d[i][j][z] * (1 - p[i+1]);
   int nz = z + a[i+1] - n;
   if (nz > n) nz = n;
   if (nz < -n) nz = -n;
   nz += n;
   d[i+1][j+1][nz] += d[i][j][z] * p[i+1];
  }

  double res = 0.0;
  for (int j=l; j<=n; j++)
    for (int z=0; z<=n; z++)
        res += d[n][j][z+n];
        
  printf("%.10lf",res);
  return 0;
}