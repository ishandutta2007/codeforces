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

bool a[510][510];
bool g[2][2];
int sum[510][510];
int n, m;

bool d[510][510][10];

int dx[4] = { 1, 0, 1, 0 };
int dy[4] = { 0, 1, 1, 0 };

int getsum(int x1, int y1, int x2, int y2)
{
  return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
}

set <int> s;

int go()
{
    memset(d, 0, sizeof d);

    forn(i, n - 1)
     forn(j, m - 1)
      {
          bool ok = 1;
          forn(z, 4)
           if  (a[i + dx[z]][j + dy[z]] != g[dx[z]][dy[z]]) ok = 0;

          d[i][j][1] = ok;
      }

    int res = 0;

    for (int L = 2; L <= 9; L++)
     forn(i, n)
      forn(j, m)
      {
          int len = (1 << L);
          if  (i + len > n || j + len > m) continue;

          d[i][j][L] = 1;

          forn(I, 2)
           forn(J, 2)
            if  (g[I][J])
            {
                int x = J * len / 2;
                int y = I * len / 2;
                x += j;
                y += i;

                if  (getsum(y, x, y + len / 2 - 1, x + len / 2 - 1) != (len / 2) * (len / 2)) d[i][j][L] = 0;
            }
            else
            {
                int x = J * len / 2;
                int y = I * len / 2;
                x += j;
                y += i;
                if  (!d[y][x][L - 1]) d[i][j][L] = 0;
            }

          res += d[i][j][L];
      }


    return res;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(sum, 0, sizeof sum);
  scanf("%d%d\n", &n, &m);

  forn(i, n)
  {
      char c;
      forn(j, m)
       {
           c = getchar();
           a[i][j] = (c == '*');
       }

      scanf("\n");
      forn(j, m)
       sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
  }

  int ans = 0;
  forn(i1, 2)
   forn(i2, 2)
    forn(i3, 2)
     forn(i4, 2)
     {
         g[0][0] = i1;
         g[0][1] = i2;
         g[1][0] = i3;
         g[1][1] = i4;

         ans += go();
     }

  cout << ans << '\n';
  return 0;
}