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
vector<pll> adj[N],ve;
int ans[N],k,cnt[N],cnt2[N];
void dfs(int v,int p){
    par[v][0] = p;
    for (pll u : adj[v]){
        if (u.X == p) continue;
        h[u.X] = h[v]+1;
        dfs(u.X,v);
    }
}
int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] < (1 << i)) continue;
        v = par[v][i];
    }
    if (v == u) return v;
    repr(i,19,0){
        if (par[u][i] == par[v][i]) continue;
        u = par[u][i];
        v =  par[v][i];
    }
    return par[v][0];
}
int dfs2(int v,int p){
    ll sum = 0;
    for (auto u : adj[v]){
        if (u.X == p) continue;
        ans[u.Y] = dfs2(u.X,v);
        sum += ans[u.Y];
    }
    sum -= cnt2[v];
    sum += (cnt[v]-cnt2[v]);
    return sum;
}
int main(){
    int n;
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
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
        int u,v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
        cnt2[lca(u,v)]++;
    }
    dfs2(1,-1);
    rep(i,0,n-1) cout << ans[i] << ' ';
}