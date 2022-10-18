#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define ui64 unsigned long long
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

const double EPS = 1e-9;
const int INT_INF = 0x7FFFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFF;
const double PI = acos(-1.0);
const i64 MOD = (i64)1e9 + 7;

using namespace std;

i64 c[110][110];
i64 d[110][10010];
int n, k; i64 m;
i64 POW[110];
i64 POW1[110];

i64 mmul(i64 a, i64 b)
{
    return (a * b) % MOD;
}

i64 pow(i64 a, i64 p)
{
    if  (p == 0) return 1LL;
    i64 res = 1LL;

    while (p > 0)
    {
        if  (p & 1LL) res = (res * a) % MOD;
        a = mmul(a, a);
        p /= 2LL;
    }

    return res;
}

void add(i64 & a, i64 b)
{
    a += b;
    while  (a > MOD) a -= MOD;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m >> k;

  forn(i, n + 1) c[0][i] = 1, c[i][i] = 1;

  for (int i = 1; i <= n; i++)
   for (int j = 1; j < i; j++)
    c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % MOD;

  i64 P = m / (1LL * n); P++;
  i64 M = (m % (1LL * n));

  forn(i, n + 1)
   POW[i] = pow(c[i][n], P), POW1[i] = pow(c[i][n], P - 1LL);

  forn(i, n + 1)
   if  (M != 0)
    d[1][i] = POW[i];
   else
    d[1][i] = POW1[i];

  for (int len = 2; len <= n; len++)
   for (int sum = 0; sum <= min(k, len * n); sum++)
   {
    d[len][sum] = 0;
    for (int last = 0; sum - last >= 0 && last <= n; last++)
     if  (len <= M)
        add(d[len][sum], mmul(d[len - 1][sum - last], POW[last]));
     else
        add(d[len][sum], mmul(d[len - 1][sum - last], POW1[last]));
   }

  printf("%I64d\n", d[n][k]);
  return 0;
}