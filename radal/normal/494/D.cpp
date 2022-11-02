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
typedef pair<int,int> pll;
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,maxm = 2e5+20;
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
int dpd[N][2],sz[N],tin[N],tout[N],T,n,dpu[N][2],D[N],h[N];
int par[N][20];
vector<pll> adj[N];
void dfs2(int v,int p){
    for (pll pa : adj[v]){
        int u = pa.X,w = pa.Y;
        if (u != p){
            dpu[u][0] = mkay(dpu[v][0],dpd[v][0]);
            dpu[u][0] = mkay(dpu[u][0],1ll*(n-sz[u])*w%mod);
            dpu[u][0] = mkay(dpu[u][0],-mkay(1ll*w*sz[u]%mod,dpd[u][0]));
            dpu[u][1] = mkay(mkay(dpd[v][1],dpu[v][1]),-dpd[u][1]);
            dpu[u][1] = mkay(mkay(dpu[u][1],-1ll*w*w%mod*sz[u]%mod),-1ll*2*w*dpd[u][0]%mod);
            dpu[u][1] = mkay(dpu[u][1],1ll*w*w%mod*(n-sz[u])%mod);
            dpu[u][1] = mkay(dpu[u][1],1ll*2*w*mkay(dpu[u][0],-1ll*w*(n-sz[u])%mod)%mod);
            dfs2(u,v);
        }
    }
}
void dfs(int v,int p){
    par[v][0] = p;
    tin[v] = T;
    T++;
    sz[v] = 1;
    for (pll u : adj[v]){
        if (u.X == p) continue;
        h[u.X] = h[v]+1;
        D[u.X] = mkay(D[v],u.Y);
        dfs(u.X,v);
        sz[v] += sz[u.X];
        dpd[v][0] = mkay(dpd[v][0],dpd[u.X][0]);
        dpd[v][0] = mkay(dpd[v][0],1ll*sz[u.X]*u.Y%mod);
        dpd[v][1] = mkay(dpd[v][1],dpd[u.X][1]);
        dpd[v][1] = mkay(dpd[v][1],1ll*u.Y*u.Y%mod*sz[u.X]%mod);
        dpd[v][1] = mkay(dpd[v][1],1ll*2*u.Y%mod*dpd[u.X][0]%mod);
    }
    tout[v] = T;
    T++;
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0) if (h[v]-h[u] >= (1 << i)) v = par[v][i];
    if (v == u) return v;
    repr(i,19,0)
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    return par[v][0];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs(1,0);
    dfs2(1,0);
    rep(j,1,20){
        rep(i,2,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    while (q--){
        int u,v;
        cin >> u >> v;
        if (tin[u] >= tin[v] && tout[u] <= tout[v]){
            int d = mkay(D[u],-D[v]);
            int ans = mkay(dpd[u][1],dpu[u][1]),g = mkay(mkay(dpu[v][1],1ll*d*d%mod*(n-sz[v])%mod),1ll*2*d*dpu[v][0]%mod);
            cout << mkay(mkay(ans,-g),-g) << endl;
        }
        else{
            int w = lca(u,v),d = D[u]+D[v]-2*D[w];
            if (d < 0) d += mod;
            if (d >= mod) d -= mod;
            int ans = mkay(dpd[u][1],dpu[u][1]),g = mkay(mkay(dpd[v][1],1ll*d*d%mod*sz[v]%mod),1ll*2*dpd[v][0]*d%mod);
            cout << mkay(-ans,mkay(g,g)) << endl;
            continue;
        }
    }
}