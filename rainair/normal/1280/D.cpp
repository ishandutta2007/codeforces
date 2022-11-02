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
#define P std::pair<int,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3000+5;

P f[MAXN][MAXN];

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n,m;
int val[MAXN],_[MAXN],__[MAXN],sz[MAXN];
P tmp[MAXN];

inline void merge(int x,int y){
    FOR(i,0,sz[x]) tmp[i] = f[x][i];
    FOR(i,0,sz[x]+sz[y]) f[x][i] = MP(-1e9,-1e18);
    FOR(i,1,sz[x]){
        FOR(j,1,sz[y]){
            f[x][i+j] = std::max(f[x][i+j],MP(tmp[i].fi+f[y][j].fi+(f[y][j].se>0),tmp[i].se));
            f[x][i+j-1] = std::max(f[x][i+j-1],MP(tmp[i].fi+f[y][j].fi,tmp[i].se+f[y][j].se));
        }
    }
    sz[x] += sz[y];
}

inline void dfs(int v,int fa=0){
    f[v][1] = MP(0,val[v]);sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);merge(v,e[i].to);
    }
}

inline void Solve(){
    cnt = 0;
    scanf("%d%d",&n,&m);
    FOR(i,0,n) head[i] = 0;
    FOR(i,1,n) scanf("%d",_+i),sz[i] = 0;
    FOR(i,1,n) scanf("%d",__+i),val[i] = __[i]-_[i];
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    FOR(i,0,n) FOR(j,0,n) f[i][j] = MP(-1e9,-1e18);
    dfs(1);
    printf("%d\n",f[1][m].fi+(f[1][m].se>0));
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}