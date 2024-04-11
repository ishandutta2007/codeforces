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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
 
using namespace std;

vi g[60000];
int n;
int r1, r2;
int p[60000];

void dfs(int v, int par)
{
 p[v] = par;
 forn(i, g[v].size())
  if  (g[v][i] != par) dfs(g[v][i], v);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> r1 >> r2; r1--; r2--;

  forn(i, n)
  {
   if  (i == r1) continue;
   int p; scanf("%d", &p);
   p--;
   g[p].pb(i);
   g[i].pb(p);
  }
  dfs(r2, -1);
  
  forn(i, n)
   if  (i != r2) printf("%d ",p[i] + 1);
  return 0;
}