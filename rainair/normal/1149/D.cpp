#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 70+5;
const int MAXM = 9175040+5;

struct Edge{
    int to,w,nxt;
}e[MAXN<<4];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int n,m,a,b;

bool vis[MAXN];
int bel[MAXN],tot;
std::vector<int> G[MAXN];
int id[MAXN],c;

inline void dfs(int v){
    vis[v] = 1;G[tot].pb(v);bel[v] = tot;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].w == b || vis[e[i].to]) continue;
        dfs(e[i].to);
    }
}

inline int calc(int i,int j){
    return ((i-1)<<c)|j;
}

inline int get(int x){
    return id[bel[x]] == -1 ? 0 : (1<<id[bel[x]]);
}

int dis[MAXM];
bool used[MAXM];

int main(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    FOR(i,1,n) if(!vis[i]) ++tot,dfs(i);
    FOR(i,1,tot){
        if(G[i].size() >= 4) id[i] = c++;
        else id[i] = -1;
    }
    std::priority_queue<P,std::vector<P>,std::greater<P> > q;
    FOR(i,0,MAXM-1) dis[i] = 1e9;
    dis[calc(1,get(1))] = 0;
    q.push(MP(0,calc(1,get(1))));
    while(!q.empty()){
        int v = (q.top().se>>c)+1,S = q.top().se&((1<<c)-1);q.pop();
        if(used[calc(v,S)]) continue;
        used[calc(v,S)] = 1;
        for(int i = head[v];i;i = e[i].nxt){
            if(bel[v] == bel[e[i].to] && e[i].w == b) continue;
            if(e[i].w == b && (S&get(e[i].to))) continue;
            int nxt = calc(e[i].to,S|get(e[i].to));
            if(dis[nxt] > dis[calc(v,S)]+e[i].w){
                dis[nxt] = dis[calc(v,S)] + e[i].w;
                q.push(MP(dis[nxt],nxt));
            }
        }
    }
    FOR(i,1,n){
        int ans = 1e9;
        FOR(S,0,(1<<c)-1) ans = std::min(ans,dis[calc(i,S)]);
        printf("%d ",ans);
    }
    puts("");
    return 0;
}