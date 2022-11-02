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

const int MAXN = 3000+5;

struct Edge{
    int to,w,nxt;
}e[600000+5];
int head[MAXN],cur[MAXN],cnt=1;

inline void add(int u,int v,int w){
    e[++cnt] = {v,w,head[u]};head[u] = cnt;
    e[++cnt] = {u,0,head[v]};head[v] = cnt;
}

int dep[MAXN];
int S,T,N;

inline bool bfs(){
    FOR(i,0,N) dep[i] = 0,cur[i] = head[i];
    std::queue<int> q;q.push(S);dep[S] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i].w > 0 && !dep[e[i].to]){
                dep[e[i].to] = dep[v]+1;
                q.push(e[i].to);
            }
        }
    }
    return dep[T];
}

inline int dfs(int v,int lim=1e9){
    if(v == T) return lim;
    if(!lim) return 0;
    int ans = 0;
    for(int &i = cur[v];i;i = e[i].nxt){
        if(dep[e[i].to] == dep[v]+1){
            int w = dfs(e[i].to,std::min(lim,e[i].w));
            if(w){
                lim -= w;ans += w;e[i].w -= w;e[i^1].w += w;
                if(!lim) break;
            }
        }
    }
    return ans;
}

inline int Dinic(){
    int ans = 0,flow = 0;
    while(bfs()) while((flow=dfs(S))) ans += flow;
    return ans;
}

int n,a[MAXN],b[MAXN],ans;
bool vis[MAXN];

int main(){
//    DEBUG(sizeof(e)/1024/1024);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) scanf("%d",b+i);
    S = n+1;T = N = n+2;
    FOR(i,1,n){
        if(b[i] > 0){
            ans += b[i];
            add(S,i,b[i]);
        }
        else{
            add(i,T,-b[i]);
        }
    }
    ROF(i,n,1){
        FOR(j,1,100) vis[j] = 0;
        ROF(j,i-1,1){
            if(a[i]%a[j] || vis[a[j]]) continue;
            vis[a[j]] = 1;add(i,j,1e9);
        }
    }
    ans -= Dinic();
    printf("%d\n",ans);
    return 0;
}