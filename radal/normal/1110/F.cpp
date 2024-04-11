#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4,fma")
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
const long long int N = 5e5+20,mod = 1e9+7,inf = 1e18+10,sq = 32000;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
ll seg[N*4],h[N],lz[N*4],ans[N];
int sz[N];
vector<pair<pll,int>> Q[N];
int n;
vector<pll> adj[N];
void dfs(int v){
    sz[v] = 1;
    for (pll u : adj[v]){
        h[u.X] = h[v]+u.Y;
        dfs(u.X);
        sz[v] += sz[u.X];
    }
}
void build(int l,int r,int v = 1){
    if (r-l == 1){
        if (adj[l].empty())
            seg[v] = h[l];
        else
            seg[v] = inf;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}

void upd(int l,int r,int s,int e,int x,int v = 1){
    if (l >= s && e >= r){
        lz[v] += x;
        seg[v] += x;
        return;
    }
    if (l >= e || s >= r || s >= e) return;
    int m = (l+r) >> 1, u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}

ll que(int l,int r,int s,int e,int v = 1){
    if (l >= s && e >= r) return seg[v];
    if (l >= e || s >= r) return inf;
    int m = (l+r) >> 1, u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    return min(que(l,m,s,e,u),que(m,r,s,e,u|1));
}

void dfs2(int v,int W = 0){
    for (auto u : Q[v]){
        ans[u.Y] = que(0,n+1,u.X.X,u.X.Y+1);
    }
    for (pll p : adj[v]){
        int u = p.X,w = p.Y;
        upd(0,n+1,0,u,w);
        upd(0,n+1,u,u+sz[u],-w);
        upd(0,n+1,u+sz[u],n+1,w);
        dfs2(u,w);
    }
    upd(0,n+1,0,v,-W);
    upd(0,n+1,v,v+sz[v],W);
    upd(0,n+1,v+sz[v],n+1,-W);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> q;
    rep(i,2,n+1){
        int p,w;
        cin >> p >> w;
        adj[p].pb({i,w});
    }
    dfs(1);
    rep(i,0,q){
        int v,l,r;
        cin >> v >> l >> r;
        Q[v].pb({{l,r},i});
    }
    build(0,n+1);
    dfs2(1);
    rep(i,0,q) cout << ans[i] << endl;
}