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
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int h[N];
int par[N][20];
vector<int> adj[N];
int ans[N],k,child[N];
void dfs(int v,int p){
    par[v][0] = p;
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v);
        child[v] += child[u];
    }
    child[v]++;
}
int getpar(int u,int k){
    if (h[u] < k) return -1;
    repr(i,19,0){
        if (k < (1 << i)) continue;
        u =  par[u][i];
        k -= (1 << i);
    }
    return u;
}
pair<int,pll> lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] < (1 << i)) continue;
        v = par[v][i];
    }
    if (v == u) return {v,{-1,-1}};
    repr(i,19,0){
        if (par[u][i] == par[v][i]) continue;
        u = par[u][i];
        v =  par[v][i];
    }
    return {par[v][0],{u,v}};
}
int main(){
    int n;
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    rep(j,1,20){
        rep(i,1,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    cin >> k;
    rep(i,0,k){
        int u,v,w;
        cin >> u >> v;
        pair<int,pll> p = lca(u,v);
        if (u == v){
            cout << n << endl;
            continue;
        }
        w = p.X;
        if ((h[v]+h[u]-2*h[w])&1){
            cout << 0 << endl;
            continue;
        }
        if (h[v] == h[u]){
            debug(p.Y.X);
            cout << n-child[p.Y.X]-child[p.Y.Y] << endl;
            continue;
        }
        if (h[u] > h[v]) swap(u,v);
        cout << child[getpar(v,(h[v]+h[u])/2-h[w])]-child[getpar(v,(h[v]+h[u])/2-1-h[w])] << endl;
    }
}