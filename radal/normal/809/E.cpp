#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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

int par[N][20],n,h[N],tin[N],tout[N],phi[N],a[N],T,dp[N];
int ans[N],tot;
vector<int> adj[N],vert[N];
vector<int> G[N];

void pre(int v,int p){
    par[v][0] = p;
    tin[v] = T;
    T++;
    for (int u : adj[v]){
        if (u != p){
            h[u] = h[v]+1;
            pre(u,v);
        }
    }
    tout[v] = T;
    T++;
}

inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0)
        if ((h[v]-h[u])&(1 << i))
            v = par[v][i];
    if (u == v) return v;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}

inline bool cmp(int u,int v){
    return tin[u] < tin[v];
}

void dfs(int v,int g){
    if (a[v]%g == 0) dp[v] = phi[a[v]];
    else dp[v] = 0;
    for (int p : G[v]){
        dfs(p,g);
        dp[v] = mkay(dp[v],dp[p]);
        ans[g] = mkay(ans[g],1ll*dp[p]*mkay(tot,-dp[p])%mod*(h[p]-h[v])%mod);
    }
}
inline void calc(int g){
    vector<int> ve;
    tot = 0;
    for(int i = g; i <= n; i += g){
        for (int u : vert[i]){
            ve.pb(u);
            G[u].clear();
            tot = mkay(tot,phi[i]);
            dp[u] = 0;
        }
    }
    sort(all(ve),cmp);
    int sz = ve.size();
    if (sz < 2) return;
    rep(i,0,sz){
        int v = ve[i],u;
        if (i) u = ve[i-1];
        else u = ve[sz-1];
        u = lca(u,v);
        G[u].clear();
        dp[u] = 0;
        ve.pb(u);
    }
    sort(all(ve));
    ve.resize(unique(all(ve))-ve.begin());
    sort(all(ve),cmp);
    set<pll> st;
    sz = ve.size();
    st.insert({tout[ve[0]],ve[0]});
    rep(i,1,sz){
        auto p = *st.lower_bound({tout[ve[i]]+1,0});
        G[p.Y].pb(ve[i]);
        st.insert({tout[ve[i]],ve[i]});
    }
    dfs(ve[0],g);
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        phi[i] = i;
        vert[a[i]].pb(i);
    }
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,2,n+1){
        if (phi[i] == i)
            for (int j = 1; j*i <= n; j++)
                phi[j*i] -= phi[j*i]/i;
    }
    pre(1,0);
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    rep(g,1,n+1){
        calc(g);
    }
    int out = 0;
    repr(i,n,1){
        for (int j = 2*i; j <= n; j += i)
            ans[i] = mkay(ans[i],-ans[j]);
        out = mkay(out,1ll*i*poww(phi[i],mod-2)%mod*ans[i]%mod);
    }
    cout << 2ll*out%mod*poww(1ll*n*(n-1)%mod,mod-2)%mod;
}