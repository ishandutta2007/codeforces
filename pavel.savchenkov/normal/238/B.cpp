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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

int n, h;
pii a[100500];
bool A[100500];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> h;

  if  (n == 2) {
    printf("0\n1 2\n");
    return 0;
  }

  forn(i, n) scanf("%d", &a[i].f), a[i].s = i;
  sort(a, a + n);

  int res = INT_INF;
  int ri = -1;
  forn(i, n - 1) {
    int ma;
    int mi;

    if  (i < n - 2)
        ma = a[n - 2].f + a[n - 1].f;
    else ma = a[i].f + a[i - 1].f;
    ma = max(a[i].f + a[n - 1].f + h, ma);

    if  (i > 0)
        mi = a[0].f + a[1].f;
    else
        mi = a[1].f + a[2].f;
    mi = min(mi, a[0].f + a[i + 1].f + h);

    if  (ma - mi < res) {
          res = ma - mi;
          ri = i;
    }
  }

  if  (a[n - 1].f + a[n - 2].f - (a[0].f + a[1].f) < res) {
    ri = n - 1;
    res = a[n - 1].f + a[n - 2].f - (a[0].f + a[1].f);
  }

  memset(A, 0, sizeof A);
  forn(i, ri + 1)
    A[ a[i].s ] = 1;
  
  printf("%d\n", res);
  forn(i, n)
    printf("%d ", A[i] + 1);    
  return 0;
}