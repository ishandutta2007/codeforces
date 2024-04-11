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

i64 b;

int a[100500];
int n, k;

int r[100500];
i64 sum[100500];

bool can(int id)
{
    i64 res = sum[k - 1];
    int L = 0; int R = k;
    while (L != R - 1)
    {
     int m = (L + R) >> 1;
     if  (r[m] >= a[id]) L = m; else R = m;
    }
    if  (r[L] != a[id]) res -= r[k - 1], res += a[id];
    return res > b;
}

int main() {
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k >> b;
  forn(i, n) scanf("%d", &a[i]);
  forn(i, n - 1) r[i] = -a[i];
  sort(r, r + n - 1);
  forn(i, n - 1) r[i] = -r[i];

//  forn(i, n - 1)
//   cout << r[i] << " "; cout << endl;

  sum[0] = r[0];

  foran(i, 1, n - 1)
   sum[i] = sum[i - 1] + r[i];


  forn(i, n - 1)
   if  (can(i))
   {
       cout << i + 1 << "\n"; return 0;
   }

  cout << n << "\n";
  return 0;
}