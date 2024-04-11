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
i64 a[200500];
int n; i64 k,sum = 0;

i64 f(i64 steps)
{
 i64 s = 0;
 forn(i,n)
  s += min(a[i],steps);
 return s;
}

int main() {
  cin >> n >> k;
  forn(i,n) scanf("%I64d",&a[i]), sum += a[i], a[i+n] = a[i];
  if (sum < k) { puts("-1"); return 0; }
  if (sum == k) { puts(""); return 0; }
   
  i64 l = 0; i64 r = k + 1ll;
  while (l != r-1)
  {
   i64 m = (l + r) >> 1ll;
   if (f(m) <= k) l = m; else r = m;
  }
  
  forn(i,n)
   k-= min(a[i],l), a[i+n] -= min(a[i+n],l), a[i] -= min(a[i],l);
  int i = 0;
  
  while (k > 0)
  {
   if (a[i] > 0) a[i]--, k--,a[i+n]--; i++;
  }

  foran(j,i,i+n)
   if (a[j] != 0) printf("%d ",(j%n)+1);
   
  return 0;
}