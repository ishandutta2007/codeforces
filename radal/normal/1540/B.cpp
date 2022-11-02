#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
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
typedef pair<ll,ll> pll;
const long long int N=2e2+20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 524288;
ll d[N][N],par[N][30],h[N];
ll dp[N][N];
vector<int> adj[N];
void pre(int v,int p){
    for (int u : adj[v]){
        if (u == p) continue;
        par[u][0] = v;
        h[u] = h[v]+1;
        pre(u,v);
    }
}
void dfs(int i,int j){
    for(int u : adj[j]){
        if (d[i][u] == -1){
            d[i][u] = d[i][j]+1;
            dfs(i,u);
        }
    }
}
ll poww(ll a,ll k){
    if (k == 0) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,11,0) if (h[v]-h[u] >= (1 << i)) v = par[v][i];
    if (u == v) return v;
    repr(i,11,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[u][0];
}
int main(){
    memset(d,-1,sizeof d);
    int n;
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,1,n+1){
        d[i][i] = 0;
        dfs(i,i);
    }        
    rep(i,1,n+1){
        dp[0][i] = 1;
        dp[i][0] = 0;
    }
    pre(1,0);
    rep(i,1,n+1){
        rep(j,1,n+1){
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
            dp[i][j] %= mod;
            dp[i][j] *= poww(2,mod-2);
            dp[i][j] %= mod;
        }
    }
    rep(i,1,11){
        rep(j,1,n+1){
            if (h[j] < (1 << i)) continue;
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    ll p=0;
    rep(i,1,n+1){
        rep(k,1,n){
            rep(j,k+1,n+1){
                int w = lca(k,j);
                int v = lca(i,j);
                int u = lca(i,k);
                int q = lca(i,w);
                if (w != j && w != k){
                    if (u == k) continue;
                    if (v == j){
                        p++;
                        p %= mod;
                        continue;
                    }
                    if (q != w || (u == w && v == w)){
                        p += dp[d[w][j]][d[w][k]];
                        p %= mod;
                        continue;
                    }
                    if (u == w){
                        p += dp[d[v][j]][d[v][k]];
                        p %= mod;
                        continue;
                    }
                    if (v == w){
                        p += dp[d[u][j]][d[u][k]];
                        p %= mod;
                        continue;
                    }
                }
                if (w == j){
                    if (u == k) continue;
                    if (v == j && u == i){
                        p += dp[d[i][j]][d[i][k]];
                        p %= mod;
                        continue;
                    }
                    if (v != j){
                        p++;
                        p %= mod;
                        continue;
                    }
                    p += dp[d[u][j]][d[u][k]];
                    p %= mod;
                    continue;
                }
                if (u != k) continue;
                p += dp[d[v][j]][d[v][k]];
                p %= mod;
            }
        }
    }
    cout << p*poww(n,mod-2)%mod;
}