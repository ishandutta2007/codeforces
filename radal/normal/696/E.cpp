//just to be saved

#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pll;
constexpr ll N = 1e5+20,mod = 1e9+7,inf = 1e18+10,maxm = 2e5+20;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int n,m,q;
vector<int> adj[N],ve;
int tin[N],sz[N],he[N],c[N],par[N][20],h[N],tout[N],T,ind[N];
multiset<pll> st[N];
pll seg[N*4];
ll lz[N*4];
ll w[N];
bitset<N> mark;
void pre(int v,int p){
    sz[v] = 1;
    for(int u : adj[v]) if (u != p){
        pre(u,v);
        sz[v] += sz[u];
    }
}
inline bool cmp(int i,int j){
    return (sz[i] > sz[j]);
}
void dfs(int v,int p,bool f){
    par[v][0] = p;
    if (f) he[v] = he[p];
    else he[v] = v;
    bool fl = 1;
    ind[v] = ve.size();
    ve.pb(v);
    tin[v] = T;
    T++;
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v,fl);
        fl = 0;
    }
    tout[v] = T;
    T++;
}
void build(int l = 0,int r = n,int v = 1){
    if (r-l == 1){
        if (st[l].empty()) seg[v] = {inf,n+1};
        else seg[v] = {st[l].begin()->X,ve[l]};
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}
inline void pass(int v){
    if (!lz[v]) return;
    int u = (v << 1);
    lz[u] += lz[v];
    seg[u].X += lz[v];
    lz[u|1] += lz[v];
    seg[u|1].X += lz[v];
    lz[v] = 0;
}
void upd(int l,int r,int p,int v){
    if (r-l == 1){
        if (st[l].empty()) seg[v] = {inf,n+1};
        else seg[v] = {st[l].begin()->X+lz[v],ve[l]};
        return;
    }
    pass(v);
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}
void upd(int l,int r,int s,int e,int x,int v){
    if (l >= e || s >= r || s >= e) return;
    if (s <= l && r <= e){
        lz[v] += x;
        seg[v].X += x;
        return;
    }
    pass(v);
    int m = (l+r) >> 1,u = (v << 1);
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}
pll que(int l,int r,int s,int e,int v = 1){
    if (s >= e || s >= r || l >= e) return {inf,n+1};
    if (s <= l && r <= e){
        return {seg[v].X,seg[v].Y};
    }
    pass(v);
    int m = (l+r) >> 1,u = (v << 1);
    return min(que(m,r,s,e,u|1),que(l,m,s,e,u));
}

inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    while (h[v] > h[u]){
        v = par[v][__builtin_ctz(h[v]-h[u])];
    }
    if (v == u) return u;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pre(1,0);
    rep(i,1,n+1) sort(adj[i].begin(),adj[i].end(),cmp);
    dfs(1,0,0);
    rep(i,1,m+1){
        cin >> c[i];
        st[ind[c[i]]].insert({i,i});
        w[i] = i;
    }
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    build(); 
    while(q--){
        int t,v,u;
        cin >> t >> v >> u;
        if (t == 2){
            upd(0,n,ind[v],ind[v]+sz[v],u,1);
            continue;
        }
        int k;
        cin >> k;
        vector<int> ans;
        vector<pll> hld;
        int w = lca(u,v);
        int b = u;
        while (b > 0){
            if (h[he[b]] > h[w]){
                hld.pb({ind[he[b]],ind[b]});
                b = par[he[b]][0];
                continue;
            }
            hld.pb({ind[w],ind[b]});
            break;
        }
        b = v;
        while (b > 0){
            if (h[he[b]] > h[w]){
                hld.pb({ind[he[b]],ind[b]});
                b = par[he[b]][0];
                continue;
            }
            hld.pb({ind[w],ind[b]});
            break;
        }
        while (k--){
            pll mi = {inf,-1};
            for (pll p : hld){
                pll g = que(0,n,p.X,p.Y+1);
                if (g.Y > n || g.Y < 0) continue;
                mi = min(mi,g);
            }
            if (mi.X == inf) break;
            int j = st[ind[mi.Y]].begin()->Y;
            ans.pb(j);
            mark[j] = 1;
            st[ind[mi.Y]].erase(st[ind[mi.Y]].begin());
            upd(0,n,ind[mi.Y],1);
        }
        cout << ans.size() << ' ';
        for (int j : ans) cout << j << ' ';
        cout << endl;
    }
}