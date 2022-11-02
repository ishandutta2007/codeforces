/*
 * Author: RainAir
 * Time: 2020-03-01 21:31:30
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

const int MAXN = 2e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;
std::vector<int> G[MAXN];
inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

int dis[MAXN];

inline void dij(int S){
    std::queue<int> q;q.push(S);dis[S] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int i = head[v];i;i = e[i].nxt){
            if(!dis[e[i].to]){
                dis[e[i].to] = dis[v] + 1;q.push(e[i].to);
            }
            if(dis[e[i].to] == dis[v] + 1) G[e[i].to].pb(v);
        }
    }
}

int n,m,k;
int p[MAXN];

inline bool chk(int a,int b){
    int p = std::lower_bound(all(G[a]),b)-G[a].begin();
    if(p == (int)G[a].size()) return false;
    if(G[a][p] == b) return true;
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(v,u);
    }
    scanf("%d",&k);
    FOR(i,1,k) scanf("%d",p+i);
    dij(p[k]);
    int ans1 = 0,ans2 = 0;
    FOR(i,1,n) std::sort(all(G[i]));
    FOR(i,1,k-1){
        if(!chk(p[i],p[i+1])) ans1++,ans2++;
        else if(G[p[i]].size() > 1) ans2++;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}