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

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000ll;
const double pi = acos(-1.0);

using namespace std;
int n;
bool a[6000][6000];
vector <int> g[6000];
bool was[6000];
int a1 = -1, a2 = -1, a3 = -1;

void dfs(int v, int p = -1)
{
    was[v] = 1;
    forn(i, g[v].size())
    {
        int to = g[v][i];
        if (!was[to]) { dfs(to, v); continue; }
        if (p == -1) continue;
        if (a[to][p]) a1 = v, a2 = to, a3 = p;
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  scanf("\n");
  forn(i, n)
  {
    char c;
    forn(j, n)
        { c = getchar(); a[i][j] = c - '0'; if (c == '1') g[i].pb(j); }
    scanf("\n");
  }
  
  memset(was,0,sizeof(was));
  forn(i, n)
    if (!was[i]) dfs(i);
  
  if (a1 == -1) cout << a1 << endl; else
   cout << a1 + 1 << " " << a2 + 1 << " " << a3 + 1 << endl;
  return 0;
}