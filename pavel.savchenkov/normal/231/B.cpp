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

int l;

bool can(vi & res, int n, int d)
{
    if  (abs(d) > n * (l - 1) / 2) return 0;

    bool sw = d < 0;
    d = abs(d);

    forn(i, n / 2)
    {
        if  (d >= l - 1)
         res.pb(l), res.pb(1), d -= l - 1;
        else
         res.pb(d + 1), res.pb(1), d = 0;
    }

    if  (sw)
     for (int i = 0; i < n; i += 2)
      swap(res[i], res[i + 1]);

    return 1;
}

int n, d;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> d >> l;

  if  (n % 2 == 0)
  {
      vi r;
      if  (can(r, n, d))
       forn(i, n)
        printf("%d ", r[i]);
      else
       puts("-1");
  }

  else
  {
    vi r;
    int last = 1;
    for (; last <= l; last++)
     if  (can(r, n - 1, d - last)) break;

    if  (last == l + 1)
     puts("-1");
    else
    {
     forn(i, n - 1)
      printf("%d ", r[i]);
     printf("%d\n", last);
    }
  }

  return 0;
}