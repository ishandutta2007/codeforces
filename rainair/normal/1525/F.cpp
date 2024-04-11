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

const int MAXN = 100 + 5;
int n,m,k;

struct Edge{
    int to,w,nxt;
}e[MAXN*MAXN*10];

int cnt=1,head[MAXN],cur[MAXN];

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
}

int dep[MAXN],N,S,T;

inline bool bfs(){
    FOR(i,1,N) cur[i] = head[i],dep[i] = 0;
    std::queue<int> q;q.push(S);dep[S] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i].w > 0 && !dep[e[i].to]){
                dep[e[i].to] = dep[v] + 1;
                q.push(e[i].to);
            }
        }
    }
    return dep[T];
}

inline int dfs(int v,int lim=1e9){
    if(v == T) return lim;
    if(!lim) return 0;
    int res = 0;
    for(int &i = cur[v];i;i = e[i].nxt){
        if(e[i].w > 0 && dep[e[i].to] == dep[v] + 1){
            int t = dfs(e[i].to,std::min(lim,e[i].w));
            if(t){
                lim -= t;e[i].w -= t;
                e[i^1].w += t;res += t;
            }
        }
    }
    return res;
}

inline int Dinic(){
    int res = 0,t = 0;
    while(bfs()) while((t = dfs(S))) res += t;
    return res;
}

bool vis[MAXN];
int edge[MAXN];

inline void dfs1(int v){
    vis[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to <= 2*n && e[i].w && !vis[e[i].to]){
            dfs1(e[i].to);
        }
    }
}

LL f[MAXN][MAXN];int pre[MAXN][MAXN];
int x[MAXN],y[MAXN];
int req[MAXN];
//  i   j

int main(){
    scanf("%d%d%d",&n,&m,&k);
    S = 2*n+1;T = N = 2*n+2;
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v+n,1);
    }
    FOR(i,1,k) scanf("%d%d",x+i,y+i);
    FOR(i,1,n) edge[i] = cnt+1,add(S,i,1),edge[i+n] = cnt+1,add(i+n,T,1);
    int sz = Dinic();
    FOR(i,1,n) if(!e[edge[i]^1].w) dfs1(i);
    std::vector<int> vec;
    FOR(i,1,n) if(!vis[i] && e[edge[i]^1].w) vec.pb(i);
    FOR(i,n+1,2*n) if(vis[i] && e[edge[i]^1].w) vec.pb(i);
    CLR(f,-1);
    f[0][sz] = 0;
    FOR(i,1,k){
        FOR(j,0,sz){
            if(f[i-1][j] < 0) continue;
            FOR(k,0,j){
                LL gx = std::max(0ll,x[i]-1ll*k*y[i]);
                if(j-k >= n-i) gx = 0;
                if(f[i][j-k] < f[i-1][j]+gx){
                    f[i][j-k] = f[i-1][j]+gx;
                    pre[i][j-k] = k;
                }
            }
        }
    }
    int ps = 0;
    FOR(i,1,sz) if(f[k][i] > f[k][ps]) ps = i;
    ROF(i,k,1){
        req[i] = pre[i][ps];
        ps += pre[i][ps];
    }
    std::vector<int> ans;
    FOR(i,1,k){
        FOR(j,1,req[i]){
            int t = vec.back();vec.pop_back();
            if(t <= n) ans.pb(t);
            else ans.pb(n-t);
        }
        ans.pb(0);
    }
    printf("%d\n",SZ(ans));
    for(auto x:ans) printf("%d ",x);puts("");
    return 0;
}