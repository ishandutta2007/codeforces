#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;

struct Data{
    int v,k,i;
};
int dfn[MAXN],low[MAXN],cnt;
int st[MAXN],top;
bool vis[MAXN];
int ans[MAXN*MAXN],N,M,Q;
std::vector<Data> q[MAXN];
std::vector<Data> to[MAXN];
std::vector<int> G[MAXN];

inline void add(int u,int v){
    G[u].push_back(v);
}

void dfs(int v,bool flag){
    static int ts = 0;
    dfn[v] = ++ts;vis[v] = true;st[++top] = v;
    if(flag){
        FOR(i,0,(int)to[v].size()-1) ans[to[v][i].i] = st[to[v][i].k];
    }
    FOR(i,0,(int)G[v].size()-1){
        if(!dfn[G[v][i]]){
            dfs(G[v][i],flag && low[v] > dfn[v]);
            low[v] = std::min(low[v],low[G[v][i]]);
        }
        else if(vis[G[v][i]]) low[v] = std::min(low[v],dfn[G[v][i]]);
    }
    vis[v] = false;
    st[top--] = 0;
}

int main(){
    //CLR(ans,-1);
    scanf("%d%d%d",&N,&M,&Q);
    FOR(i,1,M){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    FOR(i,1,Q){
        int u,v,k;scanf("%d%d%d",&u,&v,&k);
        q[u].push_back((Data){v,k,i});
    }
    FOR(i,1,N) std::sort(G[i].begin(),G[i].end());
    FOR(i,1,N){
        if(q[i].empty()) continue;
        CLR(low,0x3f3f3f3f);CLR(dfn,0);CLR(vis,false);
        FOR(j,1,N) to[j].clear();
        for(auto v:q[i]) to[v.v].push_back(v);top = 0;
        dfs(i,true);
    }
    FOR(i,1,Q) printf("%d\n",!ans[i] ? -1 : ans[i]);
    return 0;
}