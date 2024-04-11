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

int n, m;
int x[100500]; int y[100500]; int ans[100500];

int min1[200500];
int max1[200500];
int min2[200500];
int max2[200500];
int minh[200500];
int maxh[200500];
int minv[200500];
int maxv[200500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  forn(i, 200400)
   min1[i] = min2[i] = minh[i] = minv[i] = 200500,
   max1[i] = max2[i] = maxh[i] = maxv[i] = -200500;

  forn(i, m)
  {
   scanf("%d%d", &x[i], &y[i]);

   minh[x[i]] = min( minh[ x[i] ], y[i] );
   maxh[x[i]] = max( maxh[ x[i] ], y[i] );

   minv[y[i]] = min( minv[ y[i] ], x[i] );
   maxv[y[i]] = max( maxv[ y[i] ], x[i] );

   int g1 = x[i] - y[i] + 100100;
   min1[g1] = min(min1[g1], x[i]);
   max1[g1] = max(max1[g1], x[i]);

   int g2 = x[i] + y[i];
   min2[g2] = min(min2[g2], x[i]);
   max2[g2] = max(max2[g2], x[i]);
  }

  int t[10];
  memset(t, 0, sizeof t);

  forn(i, m)
  {
      ans[i] = 0;
      ans[i] += (x[i] != minv[ y[i] ]);
      ans[i] += (x[i] != maxv[ y[i] ]);
      ans[i] += (y[i] != minh[ x[i] ]);
      ans[i] += (y[i] != maxh[ x[i] ]);

      int g1 = x[i] - y[i] + 100100;
      ans[i] += (x[i] != min1[g1]);
      ans[i] += (x[i] != max1[g1]);

      int g2 = x[i] + y[i];
      ans[i] += (x[i] != min2[g2]);
      ans[i] += (x[i] != max2[g2]);

      t[ans[i]]++;
  }

  forn(i, 9)
   cout << t[i] << " ";
  return 0;
}