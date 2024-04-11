/*
 * Author: RainAir
 * Time: 2019-10-09 20:20:00
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

const int MAXN = 5e5 + 5;
const int MAXM = 19;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int n;
int head[MAXN],f[MAXN][MAXM+1],dep[MAXN],dfn[MAXN],cnt;
std::vector<int> G[MAXN];

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

inline void dfs(int v,int fa=0){
    static int ts = 0;
    dfn[v] = ++ts;
    FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
    G[dep[v]].pb(v);
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dep[e[i].to] = dep[v] + 1;
        f[e[i].to][0] = v;dfs(e[i].to,v);
    }
}

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y),std::swap(dep[x],dep[y]);
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

LL ans[MAXN];
int a[MAXN],b[MAXN],c[MAXN],top;
// a: point b: dep c: id

inline void Solve(std::vector<int> &v){
    top = 0;LL res = 0;
    FOR(i,0,(int)v.size()-1){
        int x = v[i];
        if(!i) a[++top] = x,b[top] = 0,c[top] = 0;
        else{
            while("Sqytxdy"){
                int l = lca(a[top],x);
                if(b[top] <= dep[l]){
                    a[++top] = x;b[top] = dep[l];c[top] = i;
                    break;
                }
                res -= 1ll*(c[top]-c[top-1])*b[top];
                --top;
            }
            res += 1ll*(c[top]-c[top-1])*b[top];
        }
        ans[x] += res;
    }
}

int main(){
    scanf("%d",&n);int root = 0;
    FOR(i,1,n){
        int f;scanf("%d",&f);
        if(f) add(f,i);
        else root = i;
    }
    dep[root] = 1;dfs(root);
    FOR(d,1,n){
        for(auto x:G[d]) ans[x] += ans[f[x][0]] + d;
        Solve(G[d]);
        std::reverse(all(G[d]));
        Solve(G[d]);
    }
    FOR(i,1,n) printf("%lld ",ans[i]-dep[i]);puts("");
    return 0;
}