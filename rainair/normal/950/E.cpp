#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

std::vector<int> G[MAXN];
int n,m,h,tot;
int a[MAXN];
int dfn[MAXN],low[MAXN],col[MAXN],sz[MAXN],du[MAXN];
bool ins[MAXN],vis[MAXN];std::stack<int> S;

inline void dfs(int v,int fa=0){
    static int ts = 0;
    dfn[v] = low[v] = ++ts;
    S.push(v);ins[v] = vis[v] = true;
    for(auto x:G[v]){
        if(!vis[x]) dfs(x,v),low[v] = std::min(low[v],low[x]);
        else if(ins[x]) low[v] = std::min(low[v],dfn[x]);
    }
    if(dfn[v] == low[v]){
        ++tot;int u=0;
        while(u != v){
            u = S.top();S.pop();ins[u] = false;
            col[u] = tot;sz[tot]++;
        }
    }
}

inline void build(){
    FOR(i,1,n){
        for(auto x:G[i]){
            if(col[i] == col[x]) continue;
            du[col[i]]++;
        }
    }
}

std::vector<int> A;

int main(){
    scanf("%d%d%d",&n,&m,&h);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        if((a[u]+1)%h == a[v]) G[u].pb(v);
        if((a[v]+1)%h == a[u]) G[v].pb(u);
    }
    FOR(i,1,n) if(!vis[i]) dfs(i);
    build();
    int ans = INT_MAX,pos = 0;
    FOR(i,1,tot) if(!du[i] && ans > sz[i]) pos = i,ans = std::min(ans,sz[i]);
    FOR(i,1,n) if(col[i] == pos) A.pb(i);
    printf("%d\n",ans);
    for(auto x:A) printf("%d ",x);
    return 0;
}