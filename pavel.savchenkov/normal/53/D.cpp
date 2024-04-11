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

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int a[300];
int b[300];
int n;
vii r;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d", &n);
  forn(i, n) scanf("%d", &a[i]);
  forn(i, n) scanf("%d", &b[i]);

  forn(i, n)
  {
      int j = i;
      for (; j < n; j++)
       if  (a[i] == b[j]) break;
      for (j--; j >= i; j--)
       r.pb(mp(j, j + 1)), swap(b[j], b[j + 1]);
  }

  printf("%d\n", (int)r.size());
  forn(i, r.size())
   printf("%d %d\n", r[i].f + 1, r[i].s + 1);
  return 0;
}