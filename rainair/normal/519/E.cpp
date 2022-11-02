/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-19 16:02:34
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

const int MAXN = 1e5 + 5;
const int MAXM = 19;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int f[MAXN][MAXM+1],dep[MAXN],sz[MAXN],n;

inline void dfs(int v,int fa=0){
    sz[v] = 1;
    FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dep[e[i].to] = dep[v] + 1;
        f[e[i].to][0] = v;
        dfs(e[i].to,v);sz[v] += sz[e[i].to];
    }
}

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x] - dep[y];
        FOR(i,0,MAXM) if((1<<i)&d) x = f[x][i];
    }
    if(x == y) return x;
    ROF(i,MAXM,0){
        if(f[x][i] == f[y][i]) continue;
        x = f[x][i],y = f[y][i];
    }
    return f[x][0];
}

inline int jump(int x,int k){
    ROF(i,MAXM,0) if((1<<i)&k) x = f[x][i];
    return x;
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    dep[1] = 1;dfs(1);int m;
    scanf("%d",&m);
    FOR(i,1,m){
        int x,y;scanf("%d%d",&x,&y);
        if(dep[x] < dep[y]) std::swap(x,y);
        int l = lca(x,y),dis = dep[x]+dep[y]-2*dep[l];
        if(dis&1){
            puts("0");
            continue;
        }
        int mid = dis>>1;
        if(dep[x] == dep[y]){
            int xx = jump(x,mid-1),yy = jump(y,mid-1);
            printf("%d\n",n-sz[xx]-sz[yy]);
            continue;
        }// dep[xx] > dep[yy]
        int p = jump(x,mid),xx = jump(x,mid-1);
        printf("%d\n",sz[p]-sz[xx]);
    }
    return 0;
}