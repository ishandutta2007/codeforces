#include <cstdio>
#include <iostream>
#include <cstring>
#include <memory.h>
#include <algorithm>
#include <math.h>
#define forn(i, n) for (int i=0; i<(int)n; i++)

using namespace std;
int n, t1, t2, k;
pair <double, int> r[10000];

bool cmp(pair <double, int> a, pair <double, int> b)
{
 if (fabs(a.first - b.first) > 1e-9) return (a.first + 1e-9 > b.first);
 return a.second < b.second; 
}

int main() {
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
 cin >> n >> t1 >> t2 >> k; 
 
 forn(i, n)
 {
  int a, b;
  scanf("%d%d",&a,&b);
  double aa = a; double bb = b;
  double d1 = t1 * (100 - k); d1 /= 100.0;
  double d2 = t2;
  r[i].first = max(d1 * aa + d2 * bb, d1 * bb + d2 * aa);
  r[i].second = i + 1;
 }
 
 sort(r, r + n, cmp);
 
 forn(i, n)
  printf("%d %.2lf\n",r[i].second,r[i].first);
 return 0;
}