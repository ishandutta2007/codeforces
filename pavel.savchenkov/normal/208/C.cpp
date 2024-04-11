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

i64 cnt[2][110];//cnt of shortest paths from 0 or n - 1 to i
int len[2][110];

int n, m;
vi g[110];

void calc(int from)
{
  queue <int> q;

  int V = (from == n - 1);

  memset(cnt[V], 0, sizeof cnt[V]);
  forn(i, n) len[V][i] = INT_INF;
  cnt[V][from] = 1;
  len[V][from] = 0;
  
  q.push(from);

  while (!q.empty())
  {

   int v = q.front(); q.pop();
   
   forn(i, g[v].size())
   {
    int to = g[v][i];
    if  (len[V][to] > len[V][v] + 1)
     {
      len[V][to] = len[V][v] + 1;
      cnt[V][to] = cnt[V][v];
      q.push(to);
     }
    else
    if  (len[V][to] == len[V][v] + 1) cnt[V][to] += cnt[V][v];
   }

  } 

}

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  
  forn(i, m)
  {
   int u, v; scanf("%d%d", &u, &v); u--; v--;
   g[u].pb(v); g[v].pb(u);
  }

  calc(0); calc(n - 1); 
  
  i64 all = cnt[0][n - 1];
  int L = len[0][n - 1];
  double res = 0.0;

  forn(v, n)
  {
    double cur = 0.0;

    forn(i, g[v].size())
    {
     int v1 = v; int v2 = g[v][i];
     if  (len[0][v1] > len[0][v2]) swap(v1, v2);
     if  (len[0][v1] + len[1][v2] + 1 != L) continue;
     cur += (double)cnt[0][v1] * cnt[1][v2] / all;
    }

    if  (cur > res) res = cur;
  }

  printf("%.10lf\n", res);
  return 0;
}