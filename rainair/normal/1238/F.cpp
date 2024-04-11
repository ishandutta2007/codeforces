/*
 * Author: RainAir
 * Time: 2019-10-11 09:09:36
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

const int MAXN = 3e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n;
int f[MAXN][2],d[MAXN];
// 0  1

inline void clear(){
    FOR(i,0,n) head[i] = d[i] = f[i][0] = f[i][1] = 0;
    cnt = 0;
}

inline void dfs(int v,int fa=0){
    int deg = d[v];
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);
    }
    f[v][1] = deg - 1;
    int mx = 0,cmx = 0;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        int x = f[e[i].to][1];
        f[v][0] = std::max(f[v][0],f[e[i].to][0]);
        if(d[e[i].to] == 1) continue;
        f[v][1] = std::max(f[v][1],f[e[i].to][1]+deg-1);
        if(x > mx) cmx = mx,mx = x;
        else if(x > cmx) cmx = x;
    }
    f[v][0] = std::max(deg+mx+cmx+1,f[v][0]);
    f[v][1] = std::max(f[v][1],deg-1+mx);
}

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);d[u]++;d[v]++;
    }
    if(n <= 2){
        printf("%d\n",n);
        clear();
        return;
    }
    int rt = 0;
    FOR(i,1,n) if(d[i] != 1) rt = i;
    dfs(rt);
    int ans = 0;
    printf("%d\n",f[rt][0]);
    clear();
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}