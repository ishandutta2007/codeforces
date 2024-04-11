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

int k;
bool g[110][110];
vi r[110];
int szr = 0;
int n;

void add(int a, int b)
{
    g[a][b] = g[b][a] = 1;
}

int C(int c)
{
    return (c * (c - 1) * (c - 2)) / 6;
}

int calc(int a, int b)
{
    int r = 0;
    if  (g[a][b]) return 0;
    forn(i, n)
     if  (i != a && i != b && g[i][a] && g[i][b]) r++;
    return r;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> k;
  memset(g, 0, sizeof g);

  int c = 0; int i = 0; n = 0;
  for (; i <= 99 && k > 0; i++)
  {
      c++;
      if  (C(c + 1) > k || k - C(c) >= 0 && i == 99)
      {
       k -=  C(c);
       for (int j = i - c + 1; j <= i; j++)
        r[szr].pb(j), n = max(n, j + 1);
       szr++;
       c = 0;
      }
  }
  
  /*
  forn(i, szr)
  {
      forn(j, r[i].size())
       printf("%d ", r[i][j]);
      puts("");
  }*/
  forn(z, szr)
   forn(i, r[z].size())
    foran(j, i + 1, r[z].size())
     add(r[z][i], r[z][j]);

  foran(z, 1, szr)
    forn(i, r[z].size())
       for (int ii = 0; ii < (int)r[z - 1].size() && k > 0; ii++)
           if  (calc(r[z][i], r[z - 1][ii]) <= k)
            k -= calc(r[z][i], r[z - 1][ii]), add(r[z][i], r[z - 1][ii]);

  int cnt = 0;
  forn(i, n)
   foran(j, i + 1, n)
    foran(z, j + 1, n)
     cnt += (g[i][j] && g[j][z] && g[z][i]);

 // printf("cnt = %d n = %d\n", cnt, n); return 0;
  printf("%d\n", n);
  forn(i, n)
  {
      forn(j, n)
       printf("%d", g[i][j]);
      puts("");
  }

  return 0;
}