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

const int MAXN = 4e5 + 5;

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
int n;
std::vector<int> G[MAXN];
int f[MAXN],ff[MAXN];
int sz[MAXN];
bool isr[MAXN];
std::vector<P<int,int> > node;
int fa[MAXN];

inline void dfs(int v,int fa=0){
    sz[v] = 1;::fa[v] = fa;
    for(auto x:G[v]){
        if(x == fa || isr[x]) continue;
        dfs(x,v);sz[v] += sz[x];
    }
    node.pb(v,sz[v]);
}

inline bool work(int rt,int fa=0){
    node.clear();std::vector<P<int,int> > S;dfs(rt,fa);
    S = node;
    if(SZ(S) <= 2) return 1;
    int now = ff[SZ(S)];
    if(!now) return 0;
    int ps = -1;
    for(auto x:S) if(ff[x.se] == now-1 || ff[x.se] == now-2){
        isr[x.fi] = 1;
        bool res = work(x.fi,::fa[x.fi]);
        if(!res){isr[x.fi] = 0;continue;}
        res &= work(rt,fa);
        isr[x.fi] = 0;
        if(res) return 1;
    }
    return 0;
}

int main(){
    read(n);
    f[0] = f[1] = 1;FOR(i,2,27) f[i] = f[i-1]+f[i-2];
    FOR(i,1,27) ff[f[i]] = i;
    FOR(i,2,n){
        int u,v;read(u);read(v);
        G[u].pb(v);G[v].pb(u);
    }
    bool res = work(1);
    puts(res?"YES":"NO");
    return 0;
}