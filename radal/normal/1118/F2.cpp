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
constexpr ll N = 3e5+20,mod = 998244353,inf = 1e9+10,maxm = 2e5+20;
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
int par[N][20],n,k,a[N],b[N],h[N];
vector<int> adj[N],col[N],G[N*2];
int dp[N*2][2];
void dfs2(int v,int p){
    dp[v][0] = 1;
    for (int u : G[v]){
        if (u != p){
            dfs2(u,v);
            dp[v][0] = 1ll*dp[v][0]*mkay(dp[u][0],dp[u][1])%mod;
        }
    }
    if (v <= k){
        dp[v][1] = dp[v][0];
        dp[v][0] = 0;
        return;
    }
    for(int u : G[v]){
        dp[v][1] = mkay(dp[v][1],1ll*dp[u][1]*dp[v][0]%mod*poww(mkay(dp[u][1],dp[u][0]),mod-2)%mod);
    }
}
void dfs(int v,int p){
    par[v][0] = p;
    col[a[v]].pb(v);
    for (int u : adj[v])
        if (u != p){
            h[u] = h[v]+1;
            dfs(u,v);
        }
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    while (h[v] > h[u]) v = par[v][__builtin_ctz(h[v]-h[u])];
    if (v == u) return v;
    repr(i,19,0) if (par[v][i] != par[u][i]) v = par[v][i],u = par[u][i];
    return par[v][0];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rep(i,1,n+1)
        cin >> a[i];
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    rep(j,1,20){
        rep(i,2,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    rep(i,1,k+1){
        int sz = col[i].size();
        rep(j,0,sz-1){
            int v = col[i][j],u = col[i][j+1],w = lca(u,v),vv = v;
            if (b[w] && b[w] != i){
                cout << 0;
                return 0;
            }
            b[w] = i;
            while (vv != w){
                if (b[vv] && b[vv] != i){
                    cout << 0;
                    return 0;
                }
                b[vv] = i;
                vv = par[vv][0];
            }
            vv = u;
            while (vv != w){
                if (b[vv] && b[vv] != i){
                    cout << 0;
                    return 0;
                }
                b[vv] = i;
                vv = par[vv][0];
            }
        }
        int v = col[i][0],u = col[i][sz-1],w = lca(u,v),vv = v;
        if (b[w] && b[w] != i){
            cout << 0;
            return 0;
        }
        b[w] = i;
        while (vv != w){
            if (b[vv] && b[vv] != i){
                cout << 0;
                return 0;
            }
            b[vv] = i;
            vv = par[vv][0];
        }
        vv = u;
        while (vv != w){
            if (b[vv] && b[vv] != i){
                cout << 0;
                return 0;
            }
            b[vv] = i;
            vv = par[vv][0];
        }
    }
    rep(i,1,n+1){
        for (int u : adj[i]){
            if(b[i]){
                if (b[i] != b[u]){
                    if(b[u]){
                        G[b[i]].pb(b[u]);
                    }
                    else{
                        G[b[i]].pb(u+k);
                    }
                }
            }
            else{
                if (b[u]){
                    G[i+k].pb(b[u]);
                }
                else{
                    G[i+k].pb(u+k);
                }
            }
        }
    }
    dfs2(1,0);
    cout << mkay(dp[1][1],dp[1][0]);
}