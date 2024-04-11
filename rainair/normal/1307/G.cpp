#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

struct Edge{
    int to,w,c,nxt;
}e[MAXN<<2];
int head[MAXN],cnt=1;

inline void add(int u,int v,int w,int c){
    e[++cnt] = (Edge){v,w,c,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,-c,head[v]};head[v] = cnt;
}

int pre[MAXN],dis[MAXN],S,T,N;bool inq[MAXN];

inline bool spfa(){
    FOR(i,1,N) dis[i] = 1e9;
    dis[S] = 0;std::queue<int> q;q.push(S);
    while(!q.empty()){
        int v = q.front();q.pop();inq[v] = 0;
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i].w > 0 && dis[e[i].to] > dis[v]+e[i].c){
                dis[e[i].to] = dis[v]+e[i].c;
                pre[e[i].to] = i;
                if(!inq[e[i].to]){
                    inq[e[i].to] = 1;
                    q.push(e[i].to);
                }
            }
        }
    }
    return dis[T] != 1e9;
}

std::vector<int> ans;

inline void work(){
    ans.pb(0);
    int Flow = 0,Cost = 0;
    while(spfa()){
        int flow = 1e9;
        for(int v = T;v != S;v = e[pre[v]^1].to) flow = std::min(flow,e[pre[v]].w);
        Flow += flow;
        for(int v = T;v != S;v = e[pre[v]^1].to) Cost += flow*e[pre[v]].c,e[pre[v]].w -= flow,e[pre[v]^1].w += flow;
        assert(flow==1);
        ans.pb(Cost);
    }
}

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,1,w);
    }
    S = 1;T = N = n;work();
    int q;scanf("%d",&q);
    while(q--){
        int x;scanf("%d",&x);
        DB res = 1e18;
        FOR(i,1,SZ(ans)-1) res = std::min(res,1.0*(ans[i]+x)/i);
        printf("%.10f\n",res);
    }
    return 0;
}