/*
 * Author: RainAir
 * Time: 2019-08-23 08:47:03
 */
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
#define P std::pair<int,int>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5000+5;

struct Edge{
    int to,nxt;
}e[MAXN<<2];

P edge[MAXN];

int head[MAXN],low[MAXN],dfn[MAXN],col[MAXN],du[MAXN],tot,cnt;
bool ins[MAXN];
std::stack<int> S;
int n,m,s;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

int ts = 0;

inline void dfs(int v,int fa=0){
    S.push(v);ins[v] = true;
    dfn[v] = low[v] = ++ts;
    for(int i = head[v];i;i = e[i].nxt){
        if(!dfn[e[i].to]){
            dfs(e[i].to,v);low[v] = std::min(low[v],low[e[i].to]);
        }
        else if(ins[e[i].to]) low[v] = std::min(low[v],dfn[e[i].to]);
    }
    if(low[v] == dfn[v]){
        tot++;int u;
        do{
            u = S.top();S.pop();
            ins[u] = false;
            col[u] = tot;
        }while(v != u);
    }
}

inline void rebuild(){
    for(auto x:edge){
        int u = col[x.fi],v = col[x.se];
        if(u == v) continue;
        du[v]++;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    FOR(i,1,m){
        scanf("%d%d",&edge[i].fi,&edge[i].se);
        add(edge[i].fi,edge[i].se);
    }
    FOR(i,1,n) if(!dfn[i]) dfs(i);
    rebuild();int ans = 0;
//    FOR(i,1,n) DEBUG(col[i]);
    FOR(i,1,tot) if(!du[i]) ans++;
    if(!du[col[s]]) ans--;
    printf("%d\n",ans);
    return 0;
}