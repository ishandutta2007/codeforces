#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
#define lc ((x)<<1)
#define rc ((x)<<1|1)

LL sm[MAXN<<2],tag[MAXN<<2];

inline void cover(int x,LL d){
    tag[x] = sm[x] = d;
}

inline void pushdown(int x){
    if(tag[x] != -1){
        cover(lc,tag[x]);
        cover(rc,tag[x]);
        tag[x] = -1;
    }
}

inline void modify(int x,int l,int r,int L,int R,LL d){
    if(l == L && r == R) return cover(x,d);
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    sm[x] = sm[lc]|sm[rc];
}

inline LL query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;pushdown(x);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(lc,l,mid,L,mid)|query(rc,mid+1,r,mid+1,R);
}

int n,m,c[MAXN];
std::vector<int> G[MAXN];
int dfn[MAXN],sz[MAXN],nfd[MAXN];

inline void dfs(int v,int fa=0){
    static int ts = 0;dfn[v] = ++ts;nfd[ts] = v;sz[v] = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);sz[v] += sz[x];
    }
}

inline void build(int x,int l,int r){
    tag[x] = -1;
    if(l == r) return (void)(sm[x] = 1ll<<c[nfd[l]]);
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    sm[x] = sm[lc]|sm[rc];
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",c+i),--c[i];
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);G[u].pb(v);G[v].pb(u);
    }
    dfs(1);build(1,1,n);
    FOR(i,1,m){
        int t,v;scanf("%d%d",&t,&v);
        if(t == 1){
            int c;scanf("%d",&c);--c;
            modify(1,1,n,dfn[v],dfn[v]+sz[v]-1,1ll<<c);
        }
        if(t == 2){
            printf("%d\n",__builtin_popcountll(query(1,1,n,dfn[v],dfn[v]+sz[v]-1)));
        }
    }
    return 0;
}