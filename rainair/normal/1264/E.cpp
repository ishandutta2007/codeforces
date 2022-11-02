#include<bits/stdc++.h>

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

const int MAXN = 5e5 + 5;
const int MAXM = 100+5;

namespace MCMF{
    struct Edge{
        int fr,to,w,c,nxt;
    }e[MAXN<<1];
    int head[MAXN],cnt=1;

    inline void add(int u,int v,int w,int c){
        e[++cnt] = (Edge){u,v,w,c,head[u]};head[u] = cnt;
        e[++cnt] = (Edge){v,u,0,-c,head[v]};head[v] = cnt;
    }

    int dis[MAXN],pre[MAXN];
    bool inq[MAXN];
    int N,S,T;

    inline bool spfa(){
        std::queue<int> q;
        FOR(i,0,N) dis[i] = 1e9,pre[i] = -1;
        dis[S] = 0;pre[S] = 0;q.push(S);inq[S] = 1;
        while(!q.empty()){
            int v = q.front();q.pop();
            inq[v] = 0;
            for(int i = head[v];i;i = e[i].nxt){
                if(e[i].w > 0 && dis[e[i].to] > dis[v]+e[i].c){
//                    DEBUG(e[i].to);DEBUG(e[i].c);
                    dis[e[i].to] = dis[v]+e[i].c;pre[e[i].to] = i;
                    if(!inq[e[i].to]) q.push(e[i].to),inq[e[i].to] = 1;
                }
            }
        }
        return pre[T]!=-1;
    }
    
    int maxFlow,minCost;

    inline void work(){
        while(spfa()){
            int flow = 1e9;
            for(int v = T;v != S;v = e[pre[v]].fr){
                flow = std::min(flow,e[pre[v]].w);
            }
            maxFlow += flow;
            for(int v = T;v != S;v = e[pre[v]].fr){
                minCost += flow*e[pre[v]].c;
                e[pre[v]].w -= flow;
                e[pre[v]^1].w += flow;
            }
        }
    }
}
using namespace MCMF;

int n,m;
int a[MAXM][MAXM];
int bh[MAXM][MAXM];
int p[MAXN][2];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,n) a[i][j] = 2;
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        a[u][v] = 1;a[v][u] = 0;
    }
    N = n;
    FOR(i,1,n){
        FOR(j,1,i-1){
            bh[i][j] = bh[j][i] = ++N;
        }
    }
    S = ++N;T = ++N;
    FOR(i,1,n){
        FOR(j,1,i-1){
            add(S,bh[i][j],1,0);
            if(a[i][j] != 0) add(bh[i][j],j,1,0),p[bh[i][j]][0] = cnt-1;
            if(a[i][j] != 1) add(bh[i][j],i,1,0),p[bh[i][j]][1] = cnt-1;
        }
    }
    FOR(i,1,n) FOR(j,0,n-1) add(i,T,1,j);
    work();
//    printf("%d\n",n*(n-1)*(n-2)/6-minCost);
    FOR(i,1,n){
        FOR(j,1,i-1){
            if(a[i][j] == 2){
                a[j][i] = !(a[i][j] = e[p[bh[i][j]][0]].w?0:1);
            }
        }
    }
    FOR(i,1,n) FOR(j,1,n){
        printf("%d",i==j?0:a[i][j]);
        if(j==n)puts("");
    }
    return 0;
}