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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,maxm = 1e6;
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
int n;
int t[N],h[N];
int in[N],d[N],out[N];
ll dp[N][3],pre[N],suf[N]; //0 : p -> v, 2 : v -> p
bool vis[N];
vector<int> adj[N];
void dfs(int v,int p){
    vis[v] = 1;
    vector<pll> ve;
    int sz = 0;
    for (int u : adj[v]){
        if (u == p) continue;
        sz++;
        dfs(u,v);
        ve.pb({dp[u][0]-dp[u][2],u});
    }
    sort(ve.begin(),ve.end());
    rep(i,0,sz){
        pre[i] = dp[ve[i].Y][0];
        suf[sz-i-1] = dp[ve[sz-i-1].Y][2];
        if (i){
            pre[i] += pre[i-1];
            suf[sz-i-1] += suf[sz-i];
        }
    }
    suf[sz] = 0;
    rep(j,0,2) dp[v][j] = suf[0] + 1ll*t[v]*max(in[v]+sz+1-j,out[v]);
    dp[v][2] = suf[0] + 1ll*t[v]*max(in[v]+sz,out[v]+1);
    rep(i,1,sz+1){
        rep(j,0,2){
            int x = in[v]+sz-i+1-j,y = out[v]+i;
            dp[v][j] = min(dp[v][j],pre[i-1]+suf[i]+1ll*t[v]*max(x,y));
        }
        dp[v][2] = min(dp[v][2],pre[i-1]+suf[i]+1ll*t[v]*max(in[v]+sz-i,out[v]+i+1));
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n+1) cin >> t[i];
    rep(i,1,n+1) cin >> h[i];
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        if (h[u] != h[v]){
            if (h[u] > h[v]) swap(u,v);
            out[u]++;
            in[v]++;
        }
        else{
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    ll ans = 0;
    rep(i,1,n+1) if (!vis[i]){
        dfs(i,-1);
        ans += dp[i][1];
    }
    cout << ans;
}