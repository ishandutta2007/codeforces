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
using Node = P<int,int>;

int n;
std::vector<int> G[MAXN];
int a[MAXN],to[MAXN],son[MAXN];
Node f[MAXN][2];
bool lim[MAXN],vis[MAXN];

Node operator + (const Node &a,const Node &b){
    return MP(a.fi+b.fi,a.se+b.se);
}

std::ostream& operator << (std::ostream& out,const Node &v){
    out << '{' << v.fi << ',' << v.se << '}';
    return out;
}

int sx,sy;

inline void dfs1(int v,int fa=0){
    vis[v] = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        if(!vis[x]) dfs1(x,v);
        else if(sx == -1) sx = v,sy = x;
    }
}

inline bool match(int a,int b,int c,int d){
    return (a == c && b == d) || (a == d && b == c);
}

inline void dfs2(int v,int fa=0){
    f[v][0] = MP(0,0);f[v][1] = MP(-1e9,-1e9);son[v] = 0;
    for(auto x:G[v]){
        if(x == fa || match(v,x,sx,sy)) continue;
        dfs2(x,v);
        f[v][1] = f[v][1]+std::max(f[x][0],f[x][1]);
        if(!lim[x] && !lim[v]){
            f[v][1] = std::max(f[v][1],f[v][0]+f[x][0]+MP(1,a[v]^a[x]));
            if(f[v][1] == f[v][0]+f[x][0]+MP(1,a[v]^a[x])) son[v] = x;
        }
        f[v][0] = f[v][0]+std::max(f[x][0],f[x][1]);
    }
}

std::vector<P<int,int> > ans;

inline void dfs3(int v,int d,int fa=0){// d: 
    bool flag = d;
    for(auto x:G[v]){
        if(x == fa || match(v,x,sx,sy)) continue;
        if(d == 0) dfs3(x,f[x][0]<f[x][1],v);
        else{
            if(x == son[v]) dfs3(x,0,v),ans.pb(x,v),flag = 0;
            else dfs3(x,f[x][0]<f[x][1],v);
        }
    }
    assert(!flag);
}

inline void work(int rt){
    sx = sy = -1;
    dfs1(rt);
    dfs2(rt);
    Node ans1 = std::max(f[rt][0],f[rt][1]);
    if(sx == -1){
        dfs3(rt,f[rt][0]<f[rt][1]);
        return;
    }
    lim[sx] = lim[sy] = 1;
    dfs2(rt);
    Node ans2 = std::max(f[rt][0],f[rt][1])+MP(1,a[sx]^a[sy]);
    if(ans1 > ans2){
        lim[sx] = lim[sy] = 0;
        dfs2(rt);
    }
    else ans.pb(sx,sy);
    dfs3(rt,f[rt][0]<f[rt][1]);
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d%d",to+i,a+i);--a[i];
        if(to[i] && to[to[i]] == i) continue;
        G[to[i]].pb(i),G[i].pb(to[i]);
    }
    FOR(i,1,n) if(!vis[i]) work(i);
    int sm = 0;
    for(auto x:ans) sm += a[x.fi]^a[x.se];
    printf("%d %d\n",SZ(ans),sm);
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}