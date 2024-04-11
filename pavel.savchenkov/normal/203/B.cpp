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

bool a[1100][1100];
int n, m;

bool go(int x, int y)
{
    bool ok = 1;
    for (int i = x; i < x + 3; i++)
     for (int j = y; j < y + 3; j++)
      if  (!a[i][j]) ok = 0;

    return ok;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(a, 0, sizeof a);
  scanf("%d%d", &n, &m);

  forn(I, m)
  {
      int x, y; scanf("%d%d", &x, &y);
      x--; y--; a[x][y] = 1;
      bool ok = 0;
      for (int i = max(0, x - 10); i <= min(n - 3, x + 10); i++)
       for (int j = max(0, y - 10); j <= min(n - 3, y + 10); j++)
        ok |= go(i, j);

      if  (ok) { printf("%d\n", I + 1); return 0; }
  }

  puts("-1");
  return 0;
}