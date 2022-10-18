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
const int INT_INF = 2*(int)1e9;
const i64 I64_INF = (i64)1e18;
const double PI = acos(-1.0);

using namespace std;

vii g[100500];
int n;
vii e;
int V[100500][2];

void dfs ( int v, int p = -1, int num = -1 ) {

 if  (v > 0)
  V[num][0] = p, V[num][1] = v;

 int prev = -1;

 forn(i, g[v].size()) {
  int to = g[v][i].f;
  if  (to == p) continue;

  if  (v > 0 && prev == -1)
   e.pb(mp(num, g[v][i].s));
  
  if  (prev != -1)
   e.pb(mp(g[v][prev].s, g[v][i].s));
  prev = i;

  dfs(to, v, g[v][i].s);  
 }

}
 
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  forn(i, n - 1) {
   int a, b; scanf("%d%d", &a, &b); a--; b--;
   g[a].pb(mp(b, i)); g[b].pb(mp(a, i));
  }

  dfs(0);

  printf("%d\n", n - 1);
  forn(i, n - 1) {
   printf("2 ");
   forn(j, 2) printf("%d ", V[i][j] + 1);
   puts("");
  }

  forn(i, e.size())
   printf("%d %d\n", e[i].f + 1, e[i].s + 1);
  return 0;
}