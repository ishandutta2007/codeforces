#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair<LL,LL>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 3e5 + 5;

std::vector<std::pair<int,P> > G[MAXN];
int a[MAXN],dep[MAXN],sz[MAXN],dfn[MAXN],nfd[MAXN],son[MAXN],fa[MAXN],id[MAXN],tp[MAXN];
int n,m;

inline void dfs1(int v,int faa=0){
    sz[v] = 1;fa[v] = faa;
    for(auto x:G[v]){
        if(x.fi == faa) continue;
        dep[x.fi] = dep[v]+1;dfs1(x.fi,v);
        sz[v] += sz[x.fi];
        if(!son[v] || sz[son[v]] < sz[x.fi]) son[v] = x.fi;
    }
}

struct Matrix{
    LL a[2][2];
    Matrix(){CLR(a,0);}
    LL *operator [](LL x){
        return a[x];
    }
    Matrix operator * (const Matrix &t) const {
        Matrix res;
        FOR(i,0,1){
            FOR(j,0,1){
                res[i][j] = 1e18;
                FOR(k,0,1){
                    res[i][j] = std::min(res[i][j],a[i][k]+t.a[k][j]);
                }
            }
        }
        return res;
    }

    inline void print(){
        puts("---DEBUG---");
        FOR(i,0,1) FOR(j,0,1) printf("%d%c",a[i][j],j == 1 ? '\n' : ' ');
        puts("--- END ---");
    }
}up[MAXN],down[MAXN],us[MAXN<<2],ds[MAXN<<2],tu,tv,E;

#define lc (x<<1)
#define rc (x<<1|1)
int ts = 0;
inline void dfs2(int v,int t=1,int fa=0){
    dfn[v] = ++ts;id[ts] = v;
    tp[v] = t;nfd[t] = ts;
    if(son[v]) dfs2(son[v],t,v);
    for(auto x:G[v]){
        if(x.fi == fa || x.fi == son[v]) continue;
        dfs2(x.fi,x.fi,v);
    }
    for(auto x:G[v]){
        if(x.fi == fa) continue;
        int t = dfn[x.fi];
        down[t][0][0] = x.se.fi;down[t][0][1] = x.se.se+a[x.fi];
        down[t][1][0] = x.se.fi+a[x.fi];down[t][1][1] = x.se.se;
        up[t][0][0] = x.se.fi;up[t][0][1] = x.se.se+a[v];
        up[t][1][0] = x.se.fi+a[v];up[t][1][1] = x.se.se;
    }
}

inline void pushup(int x){
    us[x] = us[lc]*us[rc];
    ds[x] = ds[rc]*ds[lc];
}

inline void build(int x,int l,int r){
    if(l == r){
        us[x] = up[l];ds[x] = down[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

inline Matrix queryu(int x,int l,int r,int L,int R){
    if(l == L && r == R) return us[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return queryu(lc,l,mid,L,R);
    if(L > mid) return queryu(rc,mid+1,r,L,R);
    return queryu(lc,l,mid,L,mid)*queryu(rc,mid+1,r,mid+1,R);
}

inline Matrix queryd(int x,int l,int r,int L,int R){
    if(l == L && r == R) return ds[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return queryd(lc,l,mid,L,R);
    if(L > mid) return queryd(rc,mid+1,r,L,R);
    return queryd(rc,mid+1,r,mid+1,R)*queryd(lc,l,mid,L,mid);
}

inline Matrix query(int u,int v){
    tu[0][0] = tu[1][1] = 0;
    tu[0][1] = tu[1][0] = 1e18;
    tv = tu;
    while(tp[u] != tp[v]){
        if(dfn[tp[u]] < dfn[tp[v]]){
            tv = tv*queryd(1,1,n,dfn[tp[v]],dfn[v]);
            v = fa[tp[v]];
        }
        else{
            tu = queryu(1,1,n,dfn[tp[u]],dfn[u])*tu;
            u = fa[tp[u]];
        }
   //     tv.print();
    }
    if(u == v) return tv*tu;
    if(dfn[u] < dfn[v]) return tv*queryd(1,1,n,dfn[u]+1,dfn[v])*tu;
    return tv*queryu(1,1,n,dfn[v]+1,dfn[u])*tu;
}
//std::priority_queue<int>::iterator it[MAXN];
//std::priority_queue<P,std::vector<P>,std::greater<P> > q;
//__gnu_pbds::priority_queue<P,std::greater<P> > it[MAXN];
std::set<P> q;
std::set<P>::iterator it[MAXN];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n){
        scanf("%lld",a+i);
        q.insert(MP(a[i],i));
        it[i] = q.find(MP(a[i],i));
    }
    FOR(i,1,n-1){
        int u,v,x,y;scanf("%lld%lld%lld%lld",&u,&v,&x,&y);
        G[u].pb(MP(v,MP(x,y)));G[v].pb(MP(u,MP(x,y)));
    }
    while(!q.empty()){
        LL t = q.begin()->se;q.erase(q.begin());
        for(auto x:G[t]){
            if(a[x.fi] > a[t]+x.se.fi+x.se.se){
                a[x.fi] = a[t]+x.se.fi+x.se.se;
                q.erase(it[x.fi]);
                q.insert(MP(a[x.fi],x.fi));
                it[x.fi] = q.find(MP(a[x.fi],x.fi));
            }
        }
    }
    dfs1(1);dfs2(1);build(1,1,n);
    int q;scanf("%lld",&q);
    while(q--){
        int u,v;scanf("%lld%lld",&u,&v);
        int x = (u-1)%2;u = (u-1)/2 + 1;
        int y = (v-1)%2;v = (v-1)/2 + 1;
        E[x][0] = 0;E[x^1][0] = a[u];Matrix t = query(u,v)*E;
        printf("%lld\n",(query(u,v)*E)[y][0]);
    }
    return 0;
}