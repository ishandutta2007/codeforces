#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int par[N][20];
int h[N],up[N],d[N],dp[N],co[N];
bool vis[N],mark[N];
vector<pll> adj[N];
void pre(int v,int c){
    vis[v] = 1;
    co[v] = c;
    for (pll u : adj[v]){
        if (!vis[u.X]){
            h[u.X] = h[v]+1;
            par[u.X][0] = v;
            pre(u.X,c);
        }
    }
}
inline int getpar(int v,int k){
    if (h[v] < k) return 0;
    repr(i,19,0){
        if (k >= (1 << i)){
            v = par[v][i];
            k -= (1 << i);
        }
    }
    return v;
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    v = getpar(v,h[v]-h[u]);
    if (u == v) return u;
    repr(i,19,0){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void dfs(int v){
    vis[v] = 1;
    dp[v] = h[v];
    for(pll u : adj[v]){
        if (u.X != par[v][0]) dp[v] = min(dp[v],h[u.X]);
        if (vis[u.X]){
            if (u.X != par[v][0]) mark[u.Y] = 0;
            continue;
        }
        dfs(u.X);
        if (dp[u.X] <= h[v]) mark[u.Y] = 0;
        dp[v] = min(dp[v],dp[u.X]);
    }
    int sz = adj[v].size();
    rep(i,0,sz-1){
        if (adj[v][i].X == adj[v][i+1].X){
            mark[adj[v][i].Y] = 0;
            mark[adj[v][i+1].Y] = 0;
        }
    }
}
bool dfs2(int v){
    vis[v] = 1;
    for (pll u : adj[v]){
        if (vis[u.X]) continue;
        if (!dfs2(u.X)) return 0;
        up[v] = min(up[v],up[u.X]);
        d[v] = min(d[v],d[u.X]);
        if (mark[u.Y] && d[u.X] <= h[v] && up[u.X] <= h[v]) return 0;
    }
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
        mark[i] = 1;
    }
    rep(i,1,n+1) sort(adj[i].begin(),adj[i].end());
    int c = 0;
    rep(i,1,n+1){
        if (!vis[i]){
            c++;
            pre(i,c);
        }
        up[i] = 1e9;
        d[i] = 1e9;
        vis[i] = 0;
    }
    rep(i,1,20){
        rep(j,1,n+1){
            if (h[j] < (1 << i)) continue;
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    rep(i,1,n+1) if (!vis[i]) dfs(i);
    bool f = 1;
    rep(i,0,q){
        int u,v,w;
        cin >> u >> v;
        if (co[u] != co[v]){
            f = 0;
            continue;
        }
        w = lca(u,v);
        up[u] = min(up[u],h[w]);
        d[v] = min(d[v],h[w]);
    }
    if (!f){
        cout << "NO";
        return 0;
    }
    memset(vis,0,sizeof vis);
    rep(i,1,n+1){
        if (!vis[i]){
            if (!dfs2(i)){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}