#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
typedef pair<int,int> pll;
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10;
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
int n,q;
pair<pll,bool> Q[N];
int tin[N],sz[N],par[N][20],h[N],T,d[N],he[N];
bool fl[N],seg[N*4],lz[N*4];
vector<pll> adj[N];
int getpar(int v){
    return par[v][0] == v ? v : par[v][0] = getpar(par[v][0]);
}
inline bool cmp(pll i,pll j){
    return (sz[i.X] > sz[j.X]);
}
void dfs2(int v,int p,bool f){
    tin[v] = T;
    T++;
    if (f) he[v] = he[he[p]];
    else he[v] = v;
    bool g = 1;
    for (pll u : adj[v]){
        if (u.X == p) continue;
        dfs2(u.X,v,g);
        g = 0;
    }
}
void dfs(int v,int p){
    par[v][0] = p;
    sz[v] = 1;
    for (pll u : adj[v]){
        if (u.X == p) continue;
        h[u.X] = h[v]^u.Y;
        d[u.X] = d[v]+1;
        dfs(u.X,v);
        sz[v] += sz[u.X];
    }
}
int que(int l,int r,int s,int e,int v = 1){
    if (s >= e || s >= r || l >= e) return 0;
    if (lz[v]) return 1;
    if (s <= l && r <= e) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    return que(l,m,s,e,u)|que(m,r,s,e,u|1);
}
void upd(int l,int r,int s,int e,int v = 1){
    if (lz[v] || s >= e || l >= e || s >= r) return;
    if (s <= l && r <= e){
        lz[v] = 1;
        seg[v] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    upd(l,m,s,e,u);
    upd(m,r,s,e,u|1);
    seg[v] = seg[u]|seg[u|1];
}
inline int lca(int u,int v){
    if (d[u] > d[v]) swap(u,v);
    while (d[v]-d[u]){
        v = par[v][__builtin_ctz(d[v]-d[u])];
    }
    if (u == v) return u;
    repr(i,19,0)
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    return par[v][0];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    rep(i,1,n+1) par[i][0] = i;
    rep(i,0,q){
        int u,v,w;
        cin >> u >> v >> w;
        Q[i].X.X = u;
        Q[i].X.Y = v;
        Q[i].Y = w;
        if (getpar(u) != getpar(v)){
            adj[u].pb({v,w});
            adj[v].pb({u,w});
            par[par[v][0]][0] = par[u][0];
            fl[i] = 1;
        }
    }
    memset(par,-1,sizeof par);
    rep(i,1,n+1) if (par[i][0] == -1) dfs(i,0);
    rep(i,1,n+1) sort(adj[i].begin(),adj[i].end(),cmp);
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    rep(i,1,n+1) if (d[i] == 0) dfs2(i,0,0);
    rep(i,0,q){
        if (fl[i]){
            cout << "YES" << endl;
            continue;
        }
        int u = Q[i].X.X,v = Q[i].X.Y,g = Q[i].Y;
        if (!(g^h[u]^h[v])){
            cout << "NO" << endl;
            continue;
        }
        vector<pll> hld;
        int w = lca(u,v);
        int b = u;
        while (b > 0){
            if (d[he[b]] > d[w]){
                hld.pb({tin[he[b]],tin[b]});
                b = par[he[b]][0];
                continue;
            }
            hld.pb({tin[w]+1,tin[b]});
            break;
        }
        b = v;
        while (b > 0){
            if (d[he[b]] > d[w]){
                hld.pb({tin[he[b]],tin[b]});
                b = par[he[b]][0];
                continue;
            }
            hld.pb({tin[w]+1,tin[b]});
            break;
        }
        bool ans = 1;
        for (pll p : hld){
            if (que(0,n,p.X,p.Y+1)){
                ans = 0;
                break;
            }
        }
        if (!ans){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (pll p : hld)
            upd(0,n,p.X,p.Y+1);
    }
    return 0;
}