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
const int INT_INF = (1 << 30) - 1;
const i64 I64_INF = (1ll << 62) - 1ll;
const double PI = acos(-1.0);

using namespace std;

int d[1010][1010][2];
int n, m, x, y;

int c[1010][2];

char s[1010][1010];

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m >> x >> y; scanf("\n");

  forn(i, n) gets(s[i]);

  forn(i, m)
  {
   int cnt = 0;
   forn(j, n)
    cnt += (s[j][i] == '.');
   c[i][0] = cnt;
   c[i][1] = n - cnt;
  }

  forn(i, m)
   for (int len = 1; len <= i + 1; len++)
    for (int color = 0; color < 2; color++)
     d[i][len][color] = INT_INF;

//  printf("ok\n");

  d[0][1][0] = c[0][0];
  d[0][1][1] = c[0][1];
  
  int ans = INT_INF;

  for (int i = 0; i < m; i++)
   for (int len = 1; len <= i + 1; len++)
    for (int color = 0; color < 2; color++)
    {
      if  (d[i][len][color] == INT_INF) continue;
      
      if  (i == m - 1)
      {
    //   printf("%d %d %d %d\n", i, len, color, d[i][len][color]);
       if  (!(len < x) && !(len > y)) ans = min(ans, d[i][len][color]);
       continue;
      }

      for (int next = 0; next < 2; next++)
       if  (next == color)
        { if  (len < y) d[i + 1][len + 1][color] = min(d[i + 1][len + 1][color], d[i][len][color] + c[i + 1][color]); }
       else
        if  (len >= x) d[i + 1][1][next] = min(d[i + 1][1][next], d[i][len][color] + c[i + 1][next]);
    }

  printf("%d\n", ans);
  return 0;
}