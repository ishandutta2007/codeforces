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
int n, u, r;
i64 res = -i64_inf;
int a[40], b[40], k[40], p[40];
int A[40];

void go(int len = 0, bool was = 0)
{
    if  ((u - len) % 2 == 0 )
    {
        i64 ans = 0;
        forn(i, n)
         ans += (i64)a[i] * k[i];
        res = max(res, ans);
    }
    if  (len == u) return;


    if  (len == u) return;
    forn(i, n)
     A[i] = a[ p[i] ] + r;
    forn(i, n)
     a[i] = A[i];

    go(len + 1, 0);

    forn(i, n)
     A[ p[i] ] = a[i] - r;
    forn(i, n)
     a[i] = A[i];


    if  (was) return;

    forn(i, n)
     a[i] ^= b[i];

    go(len + 1, 1);

    forn(i, n)
     a[i] ^= b[i];
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> u >> r;
  forn(i, n)
   cin >> a[i];
  forn(i, n)
   cin >> b[i];
  forn(i, n)
   cin >> k[i];
  forn(i, n)
   cin >> p[i], p[i]--;

  go();

  cout << res << endl;
  return 0;
}