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
i64 dp[10];
int n;
i64 ans = 0;

int d(int a)
{
 if (a <= 9) return a;
 int sum = 0;
 while (a !=0 ) sum += a%10, a/= 10;
 return d(sum);
}

i64 solve(int a)
{
 i64 A = a;
 int sa = d(A);
 i64 res = 0;
 for (int sb=1; sb<=9; sb++)
  res += dp[d(sa*sb)] * dp[sb];
 i64 l = 1ll; i64 r = n + 1;
 
 while (l != r - 1)
 {
  i64 m = (l + r) >> 1ll;
  if ( A*m <= n ) l = m; else r = m; 
 }
 res -= l;
 return res;
}

int main() {
  cin >> n;
  memset(dp,0,sizeof(dp));
  for (int i=1; i<=n; i++)
   dp[d(i)]++;
  
  for (int i=1; i<=n; i++)
   ans += solve(i);
   
  cout << ans << endl;
  return 0;
}