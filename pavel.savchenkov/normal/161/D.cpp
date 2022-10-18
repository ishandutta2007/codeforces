#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <memory.h>
#define pb push_back
#define i64 long long
#define forn(i,n) for (int i=0;i<(int)n;i++)
using namespace std;
i64 d[51000][600];
vector <int> g[51000];
int n,k;
i64 res = 0;

void dfs(int v,int p = -1)
{
    memset(d[v],0,sizeof(d[v]));
    d[v][0] = 1;
    
    forn(i,(int)g[v].size())
    {
        int to = g[v][i];
        if (to == p) continue;
        dfs(to,v);
        for (int j=1; j<k; j++)
         res += d[v][k - j] * d[to][j-1];
         // ,    to  j , 
         //    k - j      
        for (int j=1; j<=k; j++) d[v][j] += d[to][j-1];
        //      v
    }
    res += d[v][k];
    // ,    v   
}

int main() {
  scanf("%d%d",&n,&k);
  forn(i,n-1)
  {
      int a,b; scanf("%d%d",&a,&b);
      g[b].pb(a); g[a].pb(b);
  }
  
  dfs(1);
  
  cout << res << endl;
  return 0;
}