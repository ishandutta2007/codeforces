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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 6e5 + 5;
struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int sz[MAXN],n;
int fe[MAXN];

inline void dfs(int v,int fa=0){
    sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);
        sz[v] += sz[e[i].to];
        fe[e[i].to] = i;
    }
}

inline void Solve(){
    scanf("%d",&n);n<<=1;FOR(i,0,n) sz[i] = head[i] = 0;cnt = 0;
    FOR(i,2,n){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    dfs(1);
    LL G=0,B=0;
    FOR(i,2,n){
        if(sz[i]&1) G += e[fe[i]].w;
        B += 1ll*e[fe[i]].w*std::min(sz[i],n-sz[i]);
    }
    printf("%lld %lld\n",G,B);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}