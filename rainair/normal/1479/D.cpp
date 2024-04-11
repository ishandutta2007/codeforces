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

const int MAXN = 6e5 + 5;
const int MAXM = 18;
std::vector<int> G[MAXN];
int n,q,c[MAXN];
int f[MAXN][MAXM+1];
int ts,id[MAXN],st[MAXN],ed[MAXN],dep[MAXN];

inline void dfs(int v,int fa=0){
    id[st[v] = ++ts] = v;
    f[v][0] = fa;dep[v] = dep[fa]+1;
    FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);
    }
    id[ed[v] = ++ts] = v;
}

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

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x]-dep[y];
        FOR(i,0,MAXM) if((d>>i)&1) x = f[x][i];
    }
    if(x == y) return x;
    ROF(i,MAXM,0){
        if(f[x][i] == f[y][i]) continue;
        x = f[x][i],y = f[y][i];
    }
    return f[x][0];
}

int B;

struct DS{
    int sm[MAXN],bel[MAXN],n,val[MAXN];

    inline void init(int N){
        n = N;B = std::sqrt(1.0*n);
        FOR(i,1,n) bel[i] = (i-1)/B+1,val[i] = sm[i] = 0;
    }

    inline void update(int p){
        sm[bel[p]] -= val[p];
        val[p] ^= 1;
        sm[bel[p]] += val[p];
    }

    inline int query(int l,int r){
        if(bel[l] == bel[r]){
            FOR(i,l,r) if(val[i]) return i;
            return -1;
        }
        FOR(i,l,bel[l]*B) if(val[i]) return i;
        FOR(i,bel[l]+1,bel[r]-1) if(sm[i]){
            FOR(j,(i-1)*B+1,i*B) if(val[j]) return j;
        }
        FOR(i,(bel[r]-1)*B+1,r) if(val[i]) return i;
        return -1;
    }
}ds;
int ans[MAXN];

struct Node{
    int l,r,L,R,id,lca;

    inline bool operator < (const Node &t) const {
        if(l/B == t.l/B) return r < t.r;
        return l/B < t.l/B;
    }
}a[MAXN];

int main(){
    read(n);read(q);
    FOR(i,1,n) read(c[i]);
    FOR(i,2,n){
        int u,v;read(u);read(v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    ds.init(ts);
    int m = 0;
    FOR(i,1,q){
        int u,v,l,r;read(u);read(v);read(l);read(r);
        if(u == v){
            if(l <= c[u] && c[u] <= r){
                ans[i] = c[u];
            }
            else{
                ans[i] = -1;
            }
            continue;
        }
        if(st[u] > st[v]) std::swap(u,v);
        int p = lca(u,v);
        if(p == u){
            a[++m] = {st[u],st[v],l,r,i,p};
        }
        else{
            a[++m] = {ed[u],st[v],l,r,i,p};
        }
    }
    std::sort(a+1,a+m+1);
    int l = a[1].l,r = a[1].r;
    FOR(i,l,r) ds.update(c[id[i]]);
    if(a[1].lca != id[a[1].l] && a[1].lca != id[a[1].r]) ds.update(c[a[1].lca]);
    ans[a[1].id] = ds.query(a[1].L,a[1].R);
    if(a[1].lca != id[a[1].l] && a[1].lca != id[a[1].r]) ds.update(c[a[1].lca]);
    FOR(i,2,m){
        while(l > a[i].l) --l,ds.update(c[id[l]]);
        while(r < a[i].r) ++r,ds.update(c[id[r]]);
        while(l < a[i].l) ds.update(c[id[l]]),++l;
        while(r > a[i].r) ds.update(c[id[r]]),--r;
        if(a[i].lca != id[a[i].l] && a[i].lca != id[a[i].r]) ds.update(c[a[i].lca]);
        ans[a[i].id] = ds.query(a[i].L,a[i].R);
        if(a[i].lca != id[a[i].l] && a[i].lca != id[a[i].r]) ds.update(c[a[i].lca]);
    }
    FOR(i,1,q) printf("%d\n",ans[i]);puts("");
    return 0;
}