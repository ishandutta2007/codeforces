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

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
vector <int> g[100500];
vector <int> gt[100500];
int f[100500];
bool used1[100500];
bool used2[100500];
int n,m;

void dfs1(int v)
{
 used1[v] = 1;
 if (f[v] == 1) return;
 forn(i,(int)g[v].size())
 {
   int to = g[v][i];
   if (used1[to]) continue;
   dfs1(to);
 }
}

void dfs2(int v)
{
 used2[v] = 1;
 forn(i,(int)gt[v].size())
 {
   int to = gt[v][i];
   if (used2[to]) continue;
   dfs2(to);
 }
}

int main() {
  cin >> n >> m;
  forn(i,n) scanf("%d",&f[i+1]);
  memset(used1,0,sizeof(used1));
  memset(used2,0,sizeof(used2));
  
  forn(i,m)
  {
   int a,b;
   scanf("%d%d",&a,&b);
   g[b].pb(a);
   gt[a].pb(b);
  }
  
  forn(i,n)
   if (!used1[i+1] && f[i+1] == 2) dfs1(i+1);
  forn(i,n)
   if (!used2[i+1] && f[i+1] == 1) dfs2(i+1);
   
  forn(i,n)
   if (used1[i+1] && used2[i+1]) puts("1"); else puts("0");
  return 0;
}