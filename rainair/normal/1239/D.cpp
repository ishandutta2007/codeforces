/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-20 18:40:43
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
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e6 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],n,m,cnt;
int dfn[MAXN],low[MAXN],stk[MAXN],col[MAXN],sz[MAXN],du[MAXN],tp,tot;
bool ins[MAXN];
int ts = 0;

inline void add(int u,int v){
    if(u != v) e[++cnt] = (Edge){v,head[u]},head[u] = cnt;
}

inline void dfs(int v){
    dfn[v] = low[v] = ++ts;ins[v] = true;stk[++tp] = v;
    for(int i = head[v];i;i = e[i].nxt){
        if(!dfn[e[i].to]){
            dfs(e[i].to);low[v] = std::min(low[v],low[e[i].to]);
        }
        else if(ins[e[i].to]) low[v] = std::min(low[v],dfn[e[i].to]);
    }
    if(low[v] == dfn[v]){
        int t = -1;++tot;
        do{
            t = stk[tp--];ins[t] = false;
            col[t] = tot;++sz[tot];
        }while(t != v);
    }
}

inline void clear(){
    FOR(i,0,n) head[i] = dfn[i] = low[i] = stk[i] = col[i] = sz[i] = du[i] = ins[i] = 0;
    tp = tot = ts = 0;cnt = 0;
}

inline void Solve(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    FOR(i,1,n) if(!dfn[i]) dfs(i);
    FOR(v,1,n){
        for(int i = head[v];i;i = e[i].nxt){
            if(col[v] != col[e[i].to]) ++du[col[v]];
        }
    }
    if(sz[col[1]] == n){
        puts("No");
        clear();
        return;
    }
    FOR(i,1,tot){
        if(sz[i] && !du[i]){
            std::vector<int> ans1,ans2;
            FOR(j,1,n){
                if(col[j] == i) ans1.pb(j);
                else ans2.pb(j);
            }
            puts("Yes");
            printf("%lu %lu\n",ans1.size(),ans2.size());
            for(auto x:ans1) printf("%d ",x);puts("");
            for(auto x:ans2) printf("%d ",x);puts("");
            clear();return;
        }
    }
    puts("No");
    clear();
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}