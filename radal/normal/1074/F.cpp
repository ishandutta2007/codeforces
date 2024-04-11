#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
vector<int> adj[N];
int par[N][20],T,tin[N],sz[N],h[N];
pll seg[4*N];
int lz[4*N];
void pre(int v,int p){
    tin[v] = T;
    par[v][0] = p;
    T++;
    sz[v] = 1;
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        pre(u,v);
        sz[v] += sz[u];
    }
}
inline int getpar(int v,int k){
    rep(i,0,20)
        if (k&(1 << i))
            v = par[v][i];
    return v;
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    v = getpar(v,h[v]-h[u]);
    if (v == u) return v;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
void build(int l,int r,int v){
    seg[v] = {0,r-l};
    if (r-l == 1) return;
    int m = (l+r)/2,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}
void upd(int l,int r,int s,int e,int x,int v){
    if (l >= e || s >= r) return;
    if (l >= s && e >= r){
        lz[v] += x;
        seg[v].X += x;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    if (lz[v]){
        seg[u].X += lz[v];
        seg[u|1].X += lz[v];
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    if (seg[u].X == seg[u|1].X)
        seg[v] = {seg[u].X,seg[u].Y+seg[u|1].Y};
    else
        seg[v] = min(seg[u],seg[u|1]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(par,-1,sizeof par);
    int n,q;
    cin >> n >> q;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pre(1,-1);
    rep(j,1,20){
        rep(i,2,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    build(0,n,1);
    set<pll> e;
    while (q--){
        int u,v;
        cin >> u >> v;
        if (u > v) swap(u,v);
        if (e.find({u,v}) != e.end()){
            e.erase({u,v});
            int w = lca(u,v);
            if (w == u){
                int x = getpar(v,h[v]-h[u]-1);
                upd(0,n,tin[x],tin[x]+sz[x],-1,1);
                upd(0,n,tin[v],tin[v]+sz[v],1,1);
                if (seg[1].X)
                    cout << 0 << endl;
                else
                    cout << seg[1].Y << endl;
                continue;
            }
            if (w == v){
                int x = getpar(u,h[u]-h[v]-1);
                upd(0,n,tin[x],tin[x]+sz[x],-1,1);
                upd(0,n,tin[u],tin[u]+sz[u],1,1);
                if (seg[1].X)
                    cout << 0 << endl;
                else 
                    cout << seg[1].Y << endl;
                continue;
            }
            upd(0,n,0,n,-1,1);
            upd(0,n,tin[u],tin[u]+sz[u],1,1);
            upd(0,n,tin[v],tin[v]+sz[v],1,1);
            if (seg[1].X)
                cout << 0 << endl;
            else
                cout << seg[1].Y << endl;
            continue;
        }
        e.insert({u,v});
        int w = lca(u,v);
        if (w == u){
            int x = getpar(v,h[v]-h[u]-1);
            upd(0,n,tin[x],tin[x]+sz[x],1,1);
            upd(0,n,tin[v],tin[v]+sz[v],-1,1);
            if (seg[1].X)
                cout << 0 << endl;
            else
                cout << seg[1].Y << endl;
            continue;
        }
        if (w == v){
            int x = getpar(u,h[u]-h[v]-1);
            upd(0,n,tin[x],tin[x]+sz[x],1,1);
            upd(0,n,tin[u],tin[u]+sz[u],-1,1);
            if (seg[1].X)
                cout << 0 << endl;
            else
                cout << seg[1].Y << endl;
            continue;
        }
        upd(0,n,0,n,1,1);
        upd(0,n,tin[u],tin[u]+sz[u],-1,1);
        upd(0,n,tin[v],tin[v]+sz[v],-1,1);
        if (seg[1].X)
            cout << 0 << endl;
        else
            cout << seg[1].Y << endl;
        continue;
    }
}