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
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int h[N],tin[N],dp[N];
int par[N][20],t,ans;
vector<int> adj[N],g[N];
bool mark[N],vis[N],visi[N];
void pre(int v,int p){
    t++;
    tin[v] = t;
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        par[u][0] = v;
        pre(u,v);
    }
    t++;
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
void dfs(int v,int p){
    visi[v] = 1;
    int cnt = 0;
    for (int u : g[v]){
        if (u == p) continue;
        dfs(u,v);
        dp[v] += dp[u];
        if (dp[u]) cnt++;
    }
    if(!mark[v]){
        if (dp[v] > 1){
            dp[v] = 0;
            ans++;
        }
        return;
    }
    if (dp[v]) ans+=cnt;
    dp[v] = 1;
    return;
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
    pre(1,-1);
    rep(j,1,20){
        rep(i,1,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int k;
        vector<pll> ve;
        cin >> k;
        rep(i,0,k){
            int u;
            cin >> u;
            ve.pb({tin[u],u});
            mark[u] = 1;
            vis[u] = 1;
        }
        sort(ve.begin(),ve.end());
        bool f = 1;
        mark[ve[0].Y] = 1;
        rep(i,1,k){
            if (mark[par[ve[i].Y][0]]){
                cout << -1 << endl;
                f = 0;
                break;
            }
            int w = lca(ve[i].Y,ve[i-1].Y);
            if (!vis[w]){
                ve.pb({tin[w],w});
                vis[w] = 1;
            }
        }
        if (!f){
            for(pll u : ve){
                mark[u.Y] = 0;
                vis[u.Y] = 0;
            }
            continue;
        }
        sort(ve.begin(),ve.end());
        int sz = ve.size();
        rep(i,1,sz){
            int w = lca(ve[i].Y,ve[i-1].Y);
            g[ve[i].Y].pb(w);
            g[w].pb(ve[i].Y);
        }
        dfs(ve[0].Y,-1);
        cout << ans << endl;
        ans = 0;
        for(pll u : ve){
            mark[u.Y] = 0;
            g[u.Y].clear();
            dp[u.Y] = 0;
            vis[u.Y] = 0;
            visi[u.Y] = 0;
        }
    }
}