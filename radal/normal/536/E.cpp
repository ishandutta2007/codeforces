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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
int n,tin[N],T,he[N],h[N],par[N][20],sz[N],q,f[N],out[N];
vector<int> adj[N];
vector<pll> ve[2];
vector <pair<int,pll> > ed;
pair<pll,pll> Q[N];
int seg[N*4][3]; // sum pre suf
void upd(int l,int r,int p,int v = 1){
    if (r-l == 1){
        seg[v][1] = seg[v][2] = 1;
        seg[v][0] = f[1];
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u|1);
    seg[v][0]  = seg[u][0]+seg[u|1][0]-f[seg[u][2]]-f[seg[u|1][1]]+f[seg[u][2]+seg[u|1][1]];
    if (seg[u][1] == m-l) seg[v][1] = seg[u|1][1]+m-l;
    else seg[v][1] = seg[u][1];
    if (seg[u|1][2] == r-m) seg[v][2] = r-m+seg[u][2];
    else seg[v][2] = seg[u|1][2];
}
void que(int l,int r,int s,int e,bool fl,int v = 1){
    if (l >= e || s >= r) return;
    if (s <= l && r <= e){
        ve[fl].pb({v,(seg[v][1] == r-l)});
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (fl){
        que(l,m,s,e,fl,u);
        que(m,r,s,e,fl,u|1);
    }
    else{
        que(m,r,s,e,fl,u|1);
        que(l,m,s,e,fl,u);
    }
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    while(h[v]-h[u])
        v = par[v][__builtin_ctz(h[v]-h[u])];
    if (u == v) return v;
    repr(i,19,0) if (par[v][i] != par[u][i]){
        v = par[v][i];
        u = par[u][i];
    }
    return par[v][0];
}
inline bool cmp(int i,int j){
    return (sz[i] > sz[j]);
}
void pre(int v,int p){
    par[v][0] = p;
    sz[v] = 1;
    for (int u : adj[v]){
        if (u != p){
            h[u] = h[v]+1;
            pre(u,v);
            sz[v] += sz[u];
        }
    }
}
void dfs(int v,int p,bool f){
    tin[v] = T;
    T++;
    if (!f) he[v] = v;
    else he[v] = he[p];
    bool g = 1;
    for (int u : adj[v]){
        if (u != p){
            dfs(u,v,g);
            g = 0;
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    rep(i,1,n) cin >> f[i];
    rep(i,1,n){
        int u,v,w;
        cin >> u >> v >> w;
        ed.pb({w,{u,v}});
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sort(ed.begin(),ed.end());
    reverse(ed.begin(),ed.end());
    pre(1,0);
    rep(i,0,n-1) if (h[ed[i].Y.X] > h[ed[i].Y.Y]) swap(ed[i].Y.Y,ed[i].Y.X);
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    rep(i,1,n+1) sort(adj[i].begin(),adj[i].end(),cmp);
    dfs(1,0,0);
    rep(i,0,q){
        int u,v,l;
        cin >> u >> v >> l;
        Q[i] = {{l,i},{u,v}};
    }
    sort(Q,q+Q);
    reverse(Q,q+Q);
    int po = 0;
    rep(i,0,q){
        int u = Q[i].Y.Y,v = Q[i].Y.X,l = Q[i].X.X,w = lca(u,v);
        while (po < n && ed[po].X >= l){
            upd(0,n,tin[ed[po].Y.Y]);
            po++;
        }
        if (tin[u] > tin[v]) swap(u,v);
        int b = u;
        while (b > 0){
            if (h[he[b]] > h[w]){
                que(0,n,tin[he[b]],tin[b]+1,0);
                b = par[he[b]][0];
                continue;
            }
            que(0,n,tin[w]+1,tin[b]+1,0);
            break;
        }
        b = v;
        vector<pll> hld;
        while (b > 0){
            if (h[he[b]] > h[w]){
                hld.pb({tin[he[b]],tin[b]+1});
                b = par[he[b]][0];
                continue;
            }
            hld.pb({tin[w]+1,tin[b]+1});
            break;
        }
        reverse(hld.begin(),hld.end());
        for (pll p : hld) que(0,n,p.X,p.Y,1);
        int j = Q[i].X.Y,cur = 0;
        for (pll g : ve[0]){
            out[j] += seg[g.X][0]-f[cur]-f[seg[g.X][2]]+f[cur+seg[g.X][2]];
            if (g.Y) cur += seg[g.X][2];
            else cur = seg[g.X][1];
        }
        for (pll g : ve[1]){
            out[j] += seg[g.X][0]-f[cur]-f[seg[g.X][1]]+f[cur+seg[g.X][1]];
            if (g.Y) cur += seg[g.X][1];
            else cur = seg[g.X][2];
        }
        ve[0].clear();
        ve[1].clear();
    }
    rep(i,0,q) cout << out[i] << endl;
}