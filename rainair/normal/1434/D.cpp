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

const int MAXN = 5e5 + 5;
int n;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

struct DS{
    int mx0[MAXN<<2],mx1[MAXN<<2],tag[MAXN<<2];
    int dfn[MAXN],nfd[MAXN],dep[MAXN],col[MAXN],sz[MAXN],ts = 0;
    #define lc ((x)<<1)
    #define rc ((x)<<1|1)

    inline void pushup(int x){
        mx0[x] = std::max(mx0[lc],mx0[rc]);
        mx1[x] = std::max(mx1[lc],mx1[rc]);
    }

    inline void build(int x,int l,int r){
        if(l == r){
            mx0[x] = mx1[x] = 0;
            if(col[nfd[l]]) mx1[x] = dep[nfd[l]];
            else mx0[x] = dep[nfd[l]];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc,l,mid);build(rc,mid+1,r);
        pushup(x);
    }

    inline void cover(int x){
        tag[x] ^= 1;std::swap(mx0[x],mx1[x]);
    }

    inline void pushdown(int x){
        if(tag[x]){
            cover(lc);cover(rc);tag[x] = 0;
        }
    }

    inline void modify(int x,int l,int r,int L,int R){
        if(l == L && r == R) return cover(x);
        int mid = (l + r) >> 1;pushdown(x);
        if(R <= mid) modify(lc,l,mid,L,R);
        else if(L > mid) modify(rc,mid+1,r,L,R);
        else modify(lc,l,mid,L,mid),modify(rc,mid+1,r,mid+1,R);
        pushup(x);
    }

    inline void dfs(int v,int fa=0){
        dfn[v] = ++ts;nfd[ts] = v;
        dep[v] = dep[fa]+1;sz[v] = 1;
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i].to == fa) continue;
            col[e[i].to] = col[v]^e[i].w;
            dfs(e[i].to,v);sz[v] += sz[e[i].to];
        }
    }
    
    inline void update(int u,int v){
        if(dep[u] > dep[v]) std::swap(u,v);
        modify(1,1,n,dfn[v],dfn[v]+sz[v]-1);
    }
}ds1,ds2;

inline int get(int rt){
    int mx = 0,ps = -1;
    std::function<void(int,int,int)> dfs = [&](int v,int fa,int dep){
        if(dep > mx){
            mx = dep;
            ps = v;
        }
        for(int i = head[v];i;i = e[i].nxt){
            if(e[i].to == fa) continue;
            dfs(e[i].to,v,dep+1);
        }
    };
    dfs(rt,0,1);
    return ps;
}

int uu[MAXN],vv[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);uu[i] = u;vv[i] = v;
        auto add = [&](int u,int v,int w){
            e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
            e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
        };
        add(u,v,w);
    }
    int q;scanf("%d",&q);
    int r1 = get(1),r2 = get(r1);
    ds1.dfs(r1);ds1.build(1,1,n);
    ds2.dfs(r2);ds2.build(1,1,n);
    while(q--){
        int x;scanf("%d",&x);
        ds1.update(uu[x],vv[x]);ds2.update(uu[x],vv[x]);
        printf("%d\n",std::max(ds1.mx0[1],ds2.mx0[1])-1);
    }
    return 0;
}