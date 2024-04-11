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
const int MAXN = 1e5 + 5;
namespace Flow{
    struct Edge{
        int to,w,nxt;
    }e[MAXN<<1];
    int head[MAXN],cur[MAXN],cnt=1;
    int dep[MAXN];
    int S,T,N;

    inline void add(int u,int v,int w){
        e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
        e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
    }

    inline bool bfs(){
        FOR(i,0,N) cur[i] = head[i],dep[i] = 0;
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

    inline int dfs(int v,int flow=1e9){
        if(v == T) return flow;
        if(!flow) return 0;
        int ans = 0;
        for(int &i = cur[v];i;i = e[i].nxt){
            if(e[i].w > 0 && dep[e[i].to] == dep[v] + 1){
                int t = dfs(e[i].to,std::min(flow,e[i].w));
                if(t>0){
                    ans += t;flow -= t;
                    e[i].w -= t;e[i^1].w += t;
                }
            }
        }
        return ans;
    }

    inline int Dinic(){
        int ans = 0,t = 0;
        while(bfs()) while((t=dfs(S))) ans += t;
        return ans;
    }
};
using namespace Flow;
int n,a[MAXN];
bool p[MAXN];
int prime[MAXN],tot;

inline void prework(){
    FOR(i,2,MAXN-1){
        if(!p[i]) prime[++tot] = i;
        for(int j = 1;j <= tot && i*prime[j] < MAXN;++j){
            p[i*prime[j]] = 1;
            if(!(i%prime[j])) break;
        }
    }
}

std::vector<std::vector<int> >  ans;
std::vector<int> t;
bool vis[MAXN];
inline void Dfs(int v){
    if(v <= n)t.pb(v);vis[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(!vis[e[i].to] && e[i|1].w == 1) Dfs(e[i].to);
    }
}

inline void check(std::vector<int> x){
    if(x.size() <= 2){
        puts("Check Failed!");exit(231);
    }
    FOR(i,1,(int)x.size()-1) if(p[a[x[i]]+a[x[i-1]]]){
        puts("Check Failed!");exit(232);
    }
    if(p[a[x[0]]+a[x[(int)x.size()-1]]]) {puts("Check Failed!");exit(233);}
}

int main(){
    prework();
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    N = n;S = ++N;T = ++N;
    FOR(i,1,n){
        if(a[i]&1) add(S,i,2);
        else add(i,T,2);
    }
    FOR(i,1,n){
        FOR(j,1,n){
            if(a[i]&1) if(!p[a[i]+a[j]]) add(i,j,1);
        }
    }
    int res = Dinic();
//    DEBUG(res);
    if(res != n){
        puts("Impossible");
        return 0;
    }
    FOR(i,1,n) if(!vis[i]){
        t.clear();
        Dfs(i);
        ans.pb(t);
    }
    printf("%lu\n",ans.size());
    for(auto x:ans){
        printf("%lu ",x.size());
        for(auto y:x) printf("%d ",y);puts("");
        check(x);
    }
    return 0;
}