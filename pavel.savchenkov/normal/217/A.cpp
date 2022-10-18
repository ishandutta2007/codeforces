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

vi g[110];
int n;
int x[110]; int y[110];
bool was[110];

void dfs(int v)
{
    was[v] = 1;
    forn(i, g[v].size())
     if  (!was[ g[v][i] ]) dfs(g[v][i]);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n) cin >> x[i] >> y[i];
  forn(i, n)
   forn(j, n)
    if  (i != j && (x[i] == x[j] || y[i] == y[j])) g[i].pb(j), g[j].pb(i);

  memset(was, 0, sizeof was);
  int Riga = 0;
  forn(i, n)
   if  (!was[i]) { dfs(i); Riga++; }

  printf("%d\n", Riga - 1);
  return 0;
}