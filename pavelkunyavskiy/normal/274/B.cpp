//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "B"

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;

vector<int> g[MAXN];

int val[MAXN];

ll dp[MAXN][2];

void dfs(int v,int p){
    ll u,d;
    u = d = 0;
                   
    for (int i = 0; i < (int)g[v].size(); i++){
        int to = g[v][i];
        if (to == p) continue;
        dfs(to,v);
        u = max(u,dp[to][0]);
        d = max(d,dp[to][1]);
    }

    ll tmp = val[v] + u - d;

    if (tmp > 0)
        d += tmp;
    else
        u -= tmp;

//  eprintf("%d %I64d %I64d\n",v,u,d);

    dp[v][0] = u;
    dp[v][1] = d;
}



int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

    int n;
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for (int i = 0; i < n; i++)
        scanf("%d",&val[i]);

    dfs(0,-1);

    printf(LLD"\n",dp[0][0] + dp[0][1]);
      
  return 0;
}