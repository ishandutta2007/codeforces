/*
 * Author: RainAir
 * Time: 2020-03-03 10:34:42
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
const int MAXM = 17;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int dep[MAXN],f[MAXN][MAXM+1];

inline void dfs(int v,int fa=0){
    f[v][0] = fa;dep[v] = dep[fa]+1;
    FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);
    }
}

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x]-dep[y];
        FOR(i,0,MAXM){
            if((d>>i)&1) x = f[x][i];
        }
    }
    if(x == y) return x;
    ROF(i,MAXM,0){
        if(f[x][i] == f[y][i]) continue;
        x = f[x][i],y = f[y][i];
    }
    return f[x][0];
}

inline int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
int n;
int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);add(u,v);
    }
    dfs(1);
    int q;scanf("%d",&q);
    while(q--){
        int x,y,a,b,k;scanf("%d%d%d%d%d",&a,&b,&x,&y,&k);
        int t1 = dis(x,y);
        if(k >= t1 && (t1&1) == (k&1)){
            puts("YES");
            continue;
        }
        int t2 = dis(x,a)+dis(b,y)+1;
        if(k >= t2 && (t2&1)==(k&1)){
            puts("YES");
            continue;
        }
        int t3 = dis(x,b)+dis(a,y)+1;
        if(k >= t3 && (t3&1)==(k&1)){
            puts("YES");
            continue;
        }
puts("NO");
    }
    return 0;
}