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

int t;

i64 solve(i64 n)
{
  i64 i = 0;
  while (1)
  {
      i++;
      if  ((i * (n + 1)) % (4ll * n) == 0) return i + 1;
  }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> t;
  forn(tt, t)
  {
      i64 n;
      scanf("%I64d", &n);
     // cout << solve(n) << " ";
       if  ((n + 1) % 4ll == 0) printf("%I64d\n", n + 1); else
        if  ((n + 1) % 2ll == 0) printf("%I64d\n", 2ll * n + 1); else printf("%I64d\n", 4ll * n + 1ll);
  }

  return 0;
}