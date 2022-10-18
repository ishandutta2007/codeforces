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

using namespace std;

int n, k;
int a[100500];
i64 sum[100500];

i64 getsum(int l, int r)
{
    return sum[r + 1] - sum[l];
}

bool can(int l, int r, int val)
{
    return 1LL * val * (r - l + 1) - getsum(l, r) <= 1LL * k;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k;

  sum[0] = 0;
  forn(i, n) scanf("%d", &a[i]);
  sort(a, a + n);
  forn(i, n) sum[i + 1] = sum[i] + 1LL * a[i];

  int ma = 1;
  int id = 0;

  foran(i, 1, n)
  {
      int L = 0; int R = i;

      while (L != R - 1)
      {
          int M = (L + R) / 2;
          if  (can(M, i - 1, a[i])) R = M; else L = M;
      }
      if  (!can(L, i - 1, a[i])) L++;

      if  (i - L + 1 > ma)
       { ma = i - L + 1; id = i; }
      else
      if  (i - L + 1 == ma && a[i] < a[id])
       id = i;
  }

  printf("%d %d\n", ma, a[id]);
  return 0;
}