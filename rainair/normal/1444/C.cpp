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

const int MAXN = 1e6 + 5;

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

std::vector<int> G[MAXN],GG[MAXN];
std::vector<P> GGG[MAXN];
std::vector<int> T[MAXN];
int n,m,k;
int bel[MAXN];
bool can[MAXN],vis[MAXN],col[MAXN],flag,br[MAXN];
int id[MAXN],tot,f[MAXN],dis[MAXN],c[MAXN];

int S[MAXN<<2],top;

inline void undo(int x){
    while(top > x){
        if(S[top] < 0) dis[-S[top]]--;
        else{
            f[S[top]] = S[top];
            c[S[top]] = 0;
        }
        top--;
    }
}

inline int find(int x){
    return x == f[x] ? x : find(f[x]);
}

inline int D(int x){
    if(f[x] == x || !f[x]) return 0;
    return c[x]^D(f[x]);
}

inline void merge(int x,int y,int w){
    if(dis[x] > dis[y]) std::swap(x,y);
    if(dis[x] == dis[y]){
        S[++top] = -y;
        dis[y]++;
    }
    S[++top] = x;
    f[x] = y;c[x] = w;
}

inline void dfs(int v){
    id[v] = tot;vis[v] = 1;
    for(auto x:G[v]){
        if(!can[x]) continue;
        if(!vis[x]){
            col[x] = col[v]^1;
            dfs(x);
        }
        else flag &= (col[v]^col[x]);
    }
}

inline bool cmp(int x,int y){
    return bel[x] < bel[y];
}

int main(){
    read(n);read(m);read(k);
    FOR(i,1,n){
        read(bel[i]);
        T[bel[i]].pb(i);
    }
    FOR(i,1,MAXN-1) f[i] = i;
    FOR(i,1,m){
        int u,v;read(u);read(v);
        G[u].pb(v);G[v].pb(u);
    }
    int c = 0;
    FOR(i,1,k){
        for(auto x:T[i]) can[x] = 1;
        for(auto x:T[i]) if(!vis[x]){
            flag = 1;++tot;
            dfs(x);
            if(!flag) br[i] = 1,++c;
        }
        for(auto x:T[i]) can[x] = 0;
    }
    FOR(i,1,k){
        if(br[i]) continue;
        for(auto x:T[i]){
            for(auto y:G[x]){
                if(bel[y] == bel[x]){
                    int fx = find(x),fy = find(y);
                    if(fx != fy){
                        int w = D(x)^D(y)^1;
                        merge(fx,fy,w);
                    }
                }
                if(bel[y] != bel[x] && !br[bel[y]]){
                    GG[i].pb(bel[y]);
                }
            }
        }
    }
    std::map<P,int> S;
    FOR(i,1,k){
        if(br[i]) continue;
        std::sort(all(GG[i]));GG[i].erase(std::unique(all(GG[i])),GG[i].end());
        for(auto x:T[i]){
            for(auto y:G[x]) if(bel[y] != i && !br[bel[y]]) GGG[bel[y]].pb(MP(x,y));
        }
        for(auto x:GG[i]){
            int st = top;
            for(auto y:GGG[x]){
                    int fx = find(y.fi),fy = find(y.se);
                    if(fx != fy){
                        int w = D(y.fi)^D(y.se)^1;
                        merge(fx,fy,w);
                    }
                    else{
                        int w = D(y.fi)^D(y.se);
                        if(!(w&1)){
                            int a = i,b = x;
                            if(a > b) std::swap(a,b);
                            S[MP(a,b)] = 1;
                        }
                    }
            }
            undo(st);
        }
        for(auto x:GG[i]) GGG[x].clear();
    }
    LL ans = 0;
    ans = 1ll*c*(k-c)+1ll*c*(c-1)/2;
    ans += S.size();
    ans = 1ll*k*(k-1)/2-ans;
    printf("%lld\n",ans);
    return 0;
}