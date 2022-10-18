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
const int mod = 1000000007;

using namespace std;
int n,m;
bool c[20][40];
int r[20];
int res = 0;
int g[10];
bool d[40];

void gen(int id, int len)
{
 if (len == r[id])
 {
  forn(i,n) d[i] = !c[id][i];
  forn(i,len)
   d[g[i]] = !d[g[i]];
  forn(i,m)
  {
   int yes = 0;
   forn(j,n)
    if (c[i][j] == d[j]) yes++;
   if (yes != r[i]) return;
  }
  res++;
  return;
 }
 
 int prev=-1; if (len > 0) prev = g[len-1];
 foran(i,prev+1,n)
  g[len] = i, gen(id,len+1); 
}

int main() {
  cin >> n >> m; scanf("\n");
  forn(i,m)
  {
   char cc;
   forn(ii,n) { cc=getchar(); c[i][ii]=cc-'0'; }
   scanf("%d\n",&r[i]);
  }
  int mi = 0;
  forn(i,m)
   if (r[i] < r[mi]) mi = i;
   
  gen(mi,0);
  
  cout << res << endl;
  return 0;
}