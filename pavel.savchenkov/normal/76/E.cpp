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

i64 res  = 0;

i64 a[2][100500];
int n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n)
   forn(j, 2)
    scanf("%I64d", &a[j][i]);

  forn(j, 2)
  {
      i64 sum = 0;
      i64 sum_sqr = 0;
      forn(i, n)
       sum += a[j][i], sum_sqr += sqr(a[j][i]) * n;

    //  printf("sum = %I64d, sum_sqr = %I64d\n", sum, sum_sqr);
      res += 2ll * sum_sqr;
      forn(i, n)
       res -= 2ll * a[j][i] * sum;
  }

  res = res / 2ll;
  cout << res << endl;
  return 0;
}