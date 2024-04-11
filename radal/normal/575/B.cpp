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
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251,maxm = 1e6+10;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int n,k;
vector<pll> adj[N];
pair<pll,bool> e[N];
int a[maxm],h[N],b[N],c[N],d[N];
int dp[N],cnt[N],sum[N];
int par[N][20];
void pre(int v,int p){
    for (pll u : adj[v]){
        if (u.X == p) continue;
        par[u.X][0] = v;
        h[u.X] = h[v]+1;
        pre(u.X,v);
    }
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] < (1 << i)) continue;
        v = par[v][i];
    }
    if (u == v) return u;
    repr(i,19,0){
        if (par[u][i] != par[v][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
void dfs(int v,int p){
    for (pll u : adj[v]){
        if (u.X == p) continue;
        dfs(u.X,v);
        b[v] += b[u.X];
        c[v] += c[u.X];
        int i = u.Y;
        sum[v] += sum[u.X];
        if (!e[i].Y) continue;
        if (e[i].X.Y == u.X) dp[i] = sum[u.X];
        else dp[i] = c[u.X]-(b[u.X]-sum[u.X]);
    }
    sum[v] -= cnt[v];
    sum[v] += d[v];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n-1){
        cin >> e[i].X.X >> e[i].X.Y >> e[i].Y;
        adj[e[i].X.Y].pb({e[i].X.X,i});
        adj[e[i].X.X].pb({e[i].X.Y,i});
        
    }
    cin >> k;
    a[0] = 1;
    pre(1,-1);
    rep(i,1,20){
        rep(j,1,n+1){
            if (h[j] < (1 << i)) continue;
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    a[0] = 1;
    rep(i,1,k+1){
        cin >> a[i];
        int w = lca(a[i],a[i-1]);
        b[a[i-1]]++;
        c[a[i]]++;
        if (w != a[i-1]){
            cnt[w]++;
            d[a[i-1]]++;
        }
    }
    dfs(1,-1);
    ll ans = 0;
    rep(i,0,n-1){
        ans += poww(2,dp[i])-1;
        if (ans >= mod) ans -= mod;
    }
    cout << ans;
    return 0;
}