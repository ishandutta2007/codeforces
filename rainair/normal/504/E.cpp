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

const int MAXN = 6e5 + 5;
const int MAXM = 20;
const int BASE = 31;
const int ha = 1e9 + 9;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

std::vector<int> G[MAXN];
int n;
char a[MAXN];
int mx[MAXN],son[MAXN],dep[MAXN],fa[MAXN];
int f[MAXN][MAXM+1];
int mn[MAXM+1][MAXN];
int occ[MAXN],N;
int pc[MAXN];
int h1[MAXN],h2[MAXN],pw[MAXN],ipw[MAXN];//  

inline int lca(int x,int y){
    int l = occ[x],r = occ[y];
    if(l > r) std::swap(l,r);
    int c = pc[r-l+1];
    if(dep[mn[c][l]] < dep[mn[c][r-(1<<c)+1]]) return mn[c][l];
    return mn[c][r-(1<<c)+1];
}

inline void dfs1(int v){
    f[v][0] = fa[v];dep[v] = dep[fa[v]]+1;
    FOR(i,1,MAXM) f[v][i] = f[f[v][i-1]][i-1];
    mn[0][++N] = v;
    h1[v] = (1ll*h1[fa[v]]*BASE%ha+a[v]-'a'+1)%ha;
    h2[v] = (h2[fa[v]]+1ll*pw[dep[v]-1]*(a[v]-'a'+1)%ha)%ha;
    if(!occ[v]) occ[v] = N;
    for(auto x:G[v]){
        if(x == fa[v]) continue;
        fa[x] = v;
        dfs1(x);
        mx[v] = std::max(mx[v],mx[x]+1);
        if(mx[x] > mx[son[v]]) son[v] = x;
        mn[0][++N] = v;
    }
}

std::vector<int> chain[MAXN],up[MAXN];
int bel[MAXN],tot;

inline int kth(int v,int k){
    if(!k) return v;
    v = f[v][pc[k]];
    k ^= (1<<pc[k]);
//    DEBUG(v);DEBUG(k);
//    DEBUG(chain[bel[v]].size());
    int u = chain[bel[v]][0];
    if(dep[v]-k < dep[u]) return up[bel[v]][dep[u]-dep[v]+k-1];
    else return chain[bel[v]][dep[v]-k-dep[u]];
}

inline void dfs2(int v,int tp){
    bel[v] = tp;chain[tp].pb(v);
    if(son[v]) dfs2(son[v],tp);
    for(auto x:G[v]){
        if(x == fa[v] || x == son[v]) continue;
        dfs2(x,++tot);
    }
}

int main(){
//    freopen("A.in","r",stdin);
    pc[0] = -1;FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+1;
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 1ll*BASE*pw[i-1]%ha;
    ipw[0] = 1;ipw[1] = qpow(BASE);FOR(i,2,MAXN-1) ipw[i] = 1ll*ipw[i-1]*ipw[1]%ha;
    read(n);FOR(i,1,n) a[i] = nc();
    FOR(i,2,n){
        int u,v;read(u);read(v);
        G[u].pb(v);G[v].pb(u);
    }
    mx[0] = -1e9;dfs1(1);tot = 1;dfs2(1,tot);
//    FOR(i,1,N) DEBUG(mn[0][i]);
    FOR(i,1,MAXM){
        for(int j = 1;j+(1<<(i-1)) <= N;++j){
            if(dep[mn[i-1][j]] < dep[mn[i-1][j+(1<<(i-1))]]) mn[i][j] = mn[i-1][j];
            else mn[i][j] = mn[i-1][j+(1<<(i-1))];
        }
    }
    FOR(i,1,tot){
        int v = chain[i][0];
        FOR(j,1,chain[i].size()){
            v = fa[v];
            up[i].pb(v);
        }
    }
  //  DEBUG(kth(261124,348));
   // exit(0);
    int q;read(q);
    while(q--){
        int a,b,c,d;read(a);read(b);read(c);read(d);
        int l1 = lca(a,b),l2 = lca(c,d);
        int d1 = dep[a]+dep[b]-2*dep[l1],d2 = dep[c]+dep[d]-2*dep[l2];
        int l = 0,r = std::min(d1,d2)+1,ans = -1;
        auto get = [&](int u,int v,int len){
            if(!len) return 0;
            int l = lca(u,v),l1 = dep[u]-dep[l]+1,l2 = dep[v]-dep[l];
            if(len <= l1){
                int t = kth(u,len-1);
                int res = 1ll*(h2[u]+ha-h2[fa[t]])%ha*ipw[dep[t]-1]%ha;
                return res;
            }
            int res = 1ll*(h2[u]+ha-h2[fa[l]])%ha*ipw[dep[l]-1]%ha;
            len -= l1;
            int t = kth(v,l2-len);
            res = 1ll*res*pw[len]%ha;
            (res += (h1[t]+ha-1ll*h1[l]*pw[len]%ha)%ha) %= ha;
            return res;
        };
        auto chk = [&](int len){
            return get(a,b,len) == get(c,d,len);
        };
        while(l <= r){
            int mid = (l + r) >> 1;
            if(chk(mid)) ans = mid,l = mid+1;
            else r = mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}