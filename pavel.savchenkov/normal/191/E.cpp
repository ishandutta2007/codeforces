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
int n;
i64 k;
int a[100500];
i64 sum[400500];

vector <i64> t[400500];
int SZ = 0;

void build(int v, int tl, int tr)
{
 if  (tl == tr) { t[v].pb(sum[tl]);  return; }
 int tm = (tl + tr) >> 1;
 build(v + v, tl, tm);
 build(v + v + 1, tm + 1, tr);

 t[v + v].pb(i64_inf); t[v + v + 1].pb(i64_inf);

 int t1 = 0; int t2 = 0;
 while (t[v + v][t1] != i64_inf || t[v + v + 1][t2] != i64_inf)
  if  (t[v + v][t1] < t[v + v + 1][t2]) t[v].pb(t[v + v][t1]), t1++; else
   t[v].pb(t[v + v + 1][t2]), t2++;

 t[v + v].pop_back(); t[v + v + 1].pop_back();
}

i64 get(int v, int tl, int tr, int l, int r, i64 d)
{
 if  (tl == l && tr == r) return upper_bound(t[v].begin(), t[v].end(), d) - t[v].begin();
 int tm = (tr + tl) >> 1;

 if  (tm >= r) return get(v + v, tl, tm, l, r, d); else
  if  (tm < l) return get(v + v + 1, tm + 1, tr, l, r, d); else
   return get(v + v, tl, tm, l, tm, d) + get(v + v + 1, tm + 1, tr, tm + 1, r, d);
}

i64 get(int l, int r, i64 d)
{
    if  (l <= r) return get(1, 0, SZ - 1, l, r, d); else return 0;
}

i64 getcnt(i64 Sum)// >= Sum
{
    i64 res = 0;
    forn(i, n)
     {
         if  (sum[i] >= Sum) res++;
         res += get(0, i - 1, sum[i] - Sum);
     }

    return res;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k;

  forn(i, n)
   scanf("%d", &a[i]);
  sum[0] = a[0];

  while ((1 << SZ) < n) SZ++;
  SZ = 1 << SZ;

  foran(i, n, SZ) sum[i] = -i64_inf;

  foran(i, 1, n)
   sum[i] = (i64)(sum[i - 1] + a[i]);

  build(1, 0, SZ - 1);

  i64 L = -100000000000009ll; i64 R = -L;
  while (L != R - 1ll)
  {
      i64 M = (L + R) >> 1ll;
      if  (getcnt(M) >= k) L = M; else R = M;
  }

  cout << L << "\n";
  return 0;
}