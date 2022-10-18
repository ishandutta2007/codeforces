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

int n, k;

vii g[400500];

char s[2][100500];

int d[400500];

void add(int v1, int v2, int w)
{
  g[v1].pb(mp(v2, w));
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> k; scanf("\n");
  gets(s[0]); gets(s[1]);

  for (int j = 0; j < 2; j++)
   for (int i = 0; s[0][i]; i++)
   {
       if  (s[j][i] == 'X') continue;
       if  (i + 1 < n && s[j][i + 1] == '-' || i + 1 == n) add(i + 2 * j * n, i + 1 + 2 * j * n, 0);
       if  (i > 0 && s[j][i - 1] == '-') add(i + 2 * j * n, i - 1 + 2 * j * n, 2);
       if  (i + k < n && s[1 - j][i + k] == '-' || i + k >= n) add(i + 2 * j * n, i + k + 2 * (1 - j) * n, -k + 1);
   }

  for (int i = 0; i <= 4 * n; i++)
   d[i] = int_inf;

  queue <int> q;
  d[0] = 0;
  q.push(0);
  
  while (!q.empty())
  {
   int v = q.front();
   q.pop();
   if  (d[v] > 0) continue;
   forn(i, g[v].size())
    if  (d[g[v][i].f] > d[v] + g[v][i].s)
    {
     q.push(g[v][i].f);
     d[g[v][i].f] = d[v] + g[v][i].s;
    }
  }
  
  bool ok = 0;
  for (int i = n; i < n + n; i++)
   ok |= d[i] <= 0 | d[i + n + n] <= 0;

  puts(ok ? "YES" : "NO");
  return 0;
}