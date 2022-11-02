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

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000000+5;

int head[MAXN],du[MAXN],ex[MAXN],cnt;
bool vis[MAXN];

struct Edge{
    int to,next;
}e[MAXN<<1];

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;du[v]++;
}

int n,m,flag;

inline void dfs(int v){
    vis[v] = true;
    flag |= (du[v]&1);
    for(Re int i = head[v];i;i = e[i].next){
        if(vis[e[i].to]) continue;
        dfs(e[i].to);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        ex[u] = ex[v] = 1;
        if(u == v) continue;
        add(u,v);add(v,u);
    }
    ex[1] = 1;int ans = 0,cnt = 0;bool odd = false;
    FOR(i,1,n){
        if(du[i] & 1){
            ans++;odd = true;
        }
        if(!vis[i]&&ex[i]){
            cnt++;flag = 0;
            dfs(i);
            if(!flag) ans += 2;
        }
    }
    if(cnt == 1 && odd == 0) ans -= 2;
    printf("%d\n",ans/2);
    return 0;
}