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
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int wstb[1010];
int wstr[1010];
int a[1010][1010];
int n, m, k;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m >> k;
  forn(i, n)
  {
   wstr[i] = i;
   forn(j, m)
   {
    wstb[j] = j;
    scanf("%d", &a[i][j]);
   }
  }

  scanf("\n");
  forn(i, k)
  {
      char s = getchar(); int x, y;
      scanf("%d%d\n", &x, &y);
      x--; y--;
      if  (s == 'c') swap(wstb[x], wstb[y]); else
       if  (s == 'r') swap(wstr[x], wstr[y]); else
        printf("%d\n", a[ wstr[x] ][ wstb[y] ]);
  }

  return 0;
}