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
#include <assert.h>

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
#define y1 fucking_y1

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int n; i64 k;
int res = 0;
int a[20];
int b[20];
i64 fac[20];
vi L;

void gen(int a = 0, int len = 0)
{
  L.pb(a);
  if  (len == 9) return;
  gen(a * 10 + 4, len + 1);
  gen(a * 10 + 7, len + 1);
}

int lucky(int a)
{
    if  (a < 4) return 0;
    int l = 0; int r = L.size();
    while (l != r - 1)
    {
        int m = (l + r) >> 1;
        if  (L[m] <= a) l = m; else r = m;
    }
    return l;
}

bool isluck(int a)
{
    return *lower_bound(L.begin(), L.end(), a) == a;
}

int main() {
  fac[1] = 1ll;
  for (int i = 2; i < 15; i++)
   fac[i] = fac[i - 1] * 1ll * (i64)i;
  gen(); sort(L.begin(), L.end());

  cin >> n >> k;
  if  (n <= 13 && fac[n] < k) { puts("-1"); return 0; }

  int sz = min(n, 13);

  for (int i = sz - 1; i >= 0; i--)
   a[i] = n - (sz - i - 1);


  for (int i = 0; i < sz; i++)
  {
      sort(a + i, a + sz);
      for (int j = i; j < sz; j++)
      {
          i64 m = j - i;
          if  (k <= fac[sz - i - 1] * (m + 1))
          {
              swap(a[i], a[j]);
              k -= fac[sz - i - 1] * m;
              break;
          }
      }
  }



  for (int i = sz - 1; i >= 0; i--)
   b[i] = n - (sz - i - 1);

  res = lucky(n - 13);
  for (int i = 0; i < sz; i++)
   res += isluck(a[i]) && isluck(b[i]);

  cout << res << "\n";
  return 0;
}