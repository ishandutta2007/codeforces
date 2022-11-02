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
    int to;LL w;int nxt;
}e[MAXN<<4];
int head[MAXN],cur[MAXN],dep[MAXN],cnt = 1;
int S,T,N;

inline void add(int u,int v,LL w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
}

inline bool bfs(){
    std::queue<int> q;FOR(i,1,N) cur[i] = head[i],dep[i] = 0;
    q.push(S);dep[S] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int i = head[v];i;i = e[i].nxt){
            if(!dep[e[i].to] && e[i].w > 0){
                dep[e[i].to] = dep[v]+1;
                q.push(e[i].to);
            }
        }
    }
    return dep[T];
}

inline LL dfs(int v,LL flow=1e18){
    if(v == T) return flow;
    if(!flow) return 0;
    LL res = 0;
    for(int &i = cur[v];i;i = e[i].nxt){
        if(e[i].w > 0 && dep[e[i].to] == dep[v]+1){
            LL t = dfs(e[i].to,std::min(flow,e[i].w));
            if(t > 0){
                res += t;e[i].w -= t;e[i^1].w += t;
                flow -= t;
                if(!flow) break;
            }
        }
    }
    return res;
}

inline LL Dinic(){
    LL res = 0,t = 0;
    while(bfs()) while((t=dfs(S))) res += t;
    return res;
}

int n,m;
LL c[MAXN];

inline int id(int x,int y){
    return (x-1)*(n+1)+y;
}

bool vis[MAXN];

inline void dfs1(int v){
    vis[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(!vis[e[i].to] && e[i].w > 0) dfs1(e[i].to);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    S = n*(n+1)+1;T = N = n*(n+1)+2;
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        c[u] += w;c[v] -= w;
        FOR(j,1,n){
            add(id(v,j),id(u,j+1),1e15);
        }
    }
    FOR(i,1,n){
        add(S,id(i,1),1e15);
        add(id(i,n+1),T,1e15);
        FOR(j,1,n){
            add(id(i,j),id(i,j+1),(j-1)*c[i]+1e10);
        }
    }
    LL ans = Dinic()-1e10*n;
    dfs1(S);
    FOR(i,1,n){
        ROF(j,n+1,1){
            if(vis[id(i,j)]){printf("%d ",j-1);break;}
        }
    }
    puts("");
    return 0;
}