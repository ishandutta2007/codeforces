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

int a[60][60];
int b[60][60];

int na, ma, nb, mb;

int go(int x, int y)
{
   int res = 0;
   forn(i, na)
    forn(j, ma)
     if  (i + x >= 0 && i + x < nb && j + y < mb && j + y >= 0)
      res += a[i][j] * b[i + x][j + y];

   return res;
}

int X = 1000, Y = 1000;
int ans = 0;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> na >> ma;
  forn(i, na)
   forn(j, ma)
    scanf("%1d", &a[i][j]);
  cin >> nb >> mb;
  forn(i, nb)
   forn(j, mb)
    scanf("%1d", &b[i][j]);

  for (int x = -60; x < 60; x++)
   for (int y = -60; y < 60; y++)
    if  (go(x, y) > ans) { X = x; Y = y; ans = go(x, y); }

  printf("%d %d\n", X, Y);
  return 0;
}