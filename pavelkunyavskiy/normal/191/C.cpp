#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 110000;
const int MAXLOG = 20;

vector<int> g[MAXN];
vector<int> id[MAXN];
int up[MAXN][MAXLOG];
int h[MAXN];
int ans[MAXN];
int sum[MAXN];
int n;

void dfs(int v,int p,int h){
    ::up[v][0] = p;
    ::h[v] = h;

    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p)
            dfs(g[v][i],v,h+1);
}

int dfs2(int v,int p){
    int sum = ::sum[v];
    for (int i = 0; i < (int)g[v].size(); i++)
        if (g[v][i] != p)
            sum += (ans[id[v][i]] = dfs2(g[v][i],v));
    return sum;
}

void initlca(){
    for (int i = 1; i < MAXLOG; i++)
        for (int j = 0; j < MAXN; j++)
            up[j][i] = up[up[j][i-1]][i-1];
}

int getup(int v,int h){
    for (int i = 0; i < MAXLOG; i++)
        if (h & (1<<i))
            v = up[v][i];
    return v;
}

int lca(int v,int u){
    if (h[v] > h[u])
        swap(v,u);
    u = getup(u,h[u] - h[v]);
    if (u == v)
        return u;
        
    for (int i = MAXLOG-1; i >= 0; i--)
        if (up[v][i] != up[u][i])
            v = up[v][i], u = up[u][i];
    return up[v][0];
}


int main(){
  #ifdef LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++){
        int a,b;       
        scanf("%d %d",&a,&b);
        --a,--b;
        g[a].pb(b);
        g[b].pb(a);
        id[a].pb(i);
        id[b].pb(i);
    }
    dfs(0,-1,0);
    int m;
    scanf("%d",&m);
    initlca();
    for (int i = 0; i < m; i++){
        int u,v;
        scanf("%d %d",&u,&v);
        --u,--v;
        sum[u]++;
        sum[v]++;
        sum[lca(u,v)] -= 2;
    }

    dfs2(0,-1);

    for (int i = 0; i < n-1; i++)
        printf("%d ",ans[i]);
  return 0;
}