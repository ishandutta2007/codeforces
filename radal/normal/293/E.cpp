#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
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
const long long int N = 5e5+20,mod = 1e9+7,inf = 1e18+10,sq = 300,maxm= 700+2;
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
int n,l,w;
vector<int> adj[N];
vector<pll> ve[N];
int par[N][20],sz[N];
ll h[N][2],total;
int fen[N];
bool hide[N];
inline void upd(int i,int x){
    for(; i <= n; i |= (i+1)){
        fen[i] += x;
    }
}
inline int que(int i){
    int ans = 0;
    for (; i >= 0; i = ((i+1)&i)-1){
        ans += fen[i];
    }
    return ans;
}
inline int lca(int u,int v){
    if (h[u][0] > h[v][0]) swap(u,v);
    repr(i,19,0) if (h[v][0]-h[u][0] >= (1 << i)) v = par[v][i];
    if (u == v) return u;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[v][0];
}
inline ll calc(int u){
    int sz = ve[u].size();
    int po = 0;
    ll ans = 0;
    repr(i,sz-1,0){
        while (po < sz && ve[u][po].X+ve[u][i].X <= w){
            upd(ve[u][po].Y,1);
            po++;
        }
        if (po) ans += que(l-ve[u][i].Y);
    }
    rep(i,0,po) upd(ve[u][i].Y,-1);
    return ans;
}
void DFS(int v,int p){
    sz[v] = 1;
    for (int u : adj[v]){
        if (!hide[u] && u != p){
            DFS(u,v);
            sz[v] += sz[u];
        }
    }
}
int cent(int v,int p,int _n){
    for (int u : adj[v])
        if (u != p && !hide[u] && _n < sz[u]*2) return cent(u,v,_n);
    return v;
}
inline int dist(int u,int v,bool f){
    int w = lca(u,v);
    return h[v][f]+h[u][f]-2*h[w][f];
}
void dfs(int v,int p,int w){
    ve[w].pb({dist(v,w,1),dist(v,w,0)});
    for ( int u : adj[v])
        if (!hide[u] && u != p) dfs(u,v,w);
}
void decom(int v){
    DFS(v,0);
    v = cent(v,0,sz[v]);
    dfs(v,0,v);
    sort(ve[v].begin(),ve[v].end());
    total += calc(v);
    hide[v] = 1;
    for (int u : adj[v]){
        if (!hide[u]){
            ve[v].clear();
            dfs(u,v,v);
            sort(ve[v].begin(),ve[v].end());
            total -= calc(v);
        }
    }
    for (int u : adj[v]) if (!hide[u]) decom(u);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> w;
    rep(i,2,n+1){
        int x,p;
        cin >> p >> x;
        par[i][0] = p;
        adj[p].pb(i);
        adj[i].pb(p);
        h[i][0] = h[p][0] + 1;
        h[i][1] = h[p][1] + x;
    }
    rep(j,1,20){
        rep(i,2,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    decom(1);
    cout << (total-n)/2;
    return 0;
}