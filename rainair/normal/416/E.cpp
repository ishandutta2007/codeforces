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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 500+5;
int dis[MAXN][MAXN];
int n,m;

inline void Floyd(){
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) dis[i][j] = std::min(dis[i][j],dis[i][k]+dis[k][j]);
}

struct Edge{
    int u,v,w;
}e[MAXN*MAXN];
int cnt[MAXN];

inline void pre(int s){
    CLR(cnt,0);
    FOR(i,1,m){
        int u = e[i].u,v = e[i].v,w = e[i].w;
        if(dis[s][u]+w == dis[s][v]) cnt[v]++;
        if(dis[s][v]+w == dis[s][u]) cnt[u]++;
    }
}

int main(){
    scanf("%d%d",&n,&m);
    CLR(dis,0x3f);
    FOR(i,0,n) dis[i][i] = 0;
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        dis[u][v] = dis[v][u] = w;e[i] = (Edge){u,v,w};
    }
    Floyd();
    FOR(i,1,n){// 
        pre(i); // O(nm) -> O(n^3)
        FOR(j,i+1,n){
            int ans = 0;
            FOR(k,1,n){
                if(dis[i][k]+dis[k][j] == dis[i][j]) ans += cnt[k];
            }
            printf("%d ",ans);
        }
    }
    return 0;
}