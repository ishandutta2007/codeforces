#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
vector<int> adj[N];
int n,x,y,z;
int d[N],d2[N],par[N][20];
ll ans;
vector<pair<pll,int>> ve;
void dfs(int v,int p){
    for (int u : adj[v]){
        if (u == p) continue;
        d[u] = d[v]+1;
        dfs(u,v);
    }
}
void dfs2(int v,int p){
    for (int u : adj[v]){
        if (u == p) continue;
        d2[u] = d2[v]+1;
        par[u][0] = v;
        dfs2(u,v);
    }
}
int lca(int u,int v){
    if (d2[u] > d2[v]) swap(u,v);
    repr(i,19,0){
        if (d2[v]-d2[u] < (1 << i)) continue;
        v = par[v][i];
    }
    if (v == u) return v;
    rep(i,19,0){
        if (d2[v] < (1 << i)) continue;
        if (par[v][i] == par[u][i]) continue;
        v = par[v][i];
        u = par[u][i];
    }
    return par[v][0];
}
void dfs3(int v,int p){
    for (int u : adj[v]){
        if (u == p) continue;
        dfs3(u,v);
        if (lca(x,u) == u) continue;
        if (d2[u] > d[u]){
            ve.pb({{u,y},u});
            ans += d2[u];
        }
        else{
            ve.pb({{u,x},u});
            ans += d[u];
        }
    }
}
void dfs4(int v,int p){
    for (int u : adj[v]){
        if (u == p || lca(u,x) != u) continue;
        dfs4(u,v);
        ve.pb({{y,u},u});
        ans += d2[u];
    }
} 
int getpar(int v,int k){
    repr(i,19,0){
        if (d2[v] < (1 << i) || k < (1 << i)) continue;
        v = par[v][i];
        k -= (1 << i);
    }
    return v;
}
int main(){
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    d[1] = 0;
    dfs(1,-1);
    int mx = 0;
    rep(i,2,n+1){
        if (mx < d[i]){
            mx = d[i];
            x = i;
        }
    }
    d[x] = 0;
    dfs(x,-1);
    mx = 0;
    rep(i,1,n+1){
        if (mx < d[i]){
            mx = d[i];
            y = i;
        }
    }
    dfs2(y,-1);
    rep(i,1,20){
        rep(j,1,n+1){
            if (d2[j] < (1 << i)) continue;
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    dfs3(y,-1);
    dfs4(y,-1);
    cout << ans << endl;
    for (auto u : ve){
        cout << u.X.X << ' ' << u.X.Y << ' ' << u.Y << endl;
    }
    return 0;
}