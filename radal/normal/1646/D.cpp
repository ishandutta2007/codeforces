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
typedef pair<int,ll> pll;
constexpr ll N = 3e5+20,mod = 1e9+7,inf = 1e18+10,maxm = 1e6;
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
vector<int> adj[N];
pll dp[N][3];
int ans[N];
void dfs(int v,int p){
    dp[v][1] = {-1,adj[v].size()};
    dp[v][0].Y = 1;
    for (int u : adj[v]){
        if (u != p){
            dfs(u,v);
            dp[v][1].X += dp[u][0].X;
            dp[v][1].Y += dp[u][0].Y;
            dp[v][0].X += dp[u][2].X;
            dp[v][0].Y += dp[u][2].Y;
        }
    }
    dp[v][2] = min(dp[v][1],dp[v][0]);
}
void calc(int v,int p,int f){
   if (!f || dp[v][0] < dp[v][1]){
       ans[v] = 1;
       for (int u : adj[v]){
           if (u != p){
               calc(u,v,1);
           }
       }
   }
   else{
       ans[v] = adj[v].size();
       for (int u : adj[v]){
           if (u != p){
               calc(u,v,0);
           }
       }
   }
}
inline void solve(){
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (n == 2){
        cout << 2 << ' ' << 2 << endl;
        cout << 1 << ' ' << 1 << endl;
        return;
    }
    dfs(1,-1);
    cout << -dp[1][2].X << ' ' << dp[1][2].Y << endl;
    calc(1,-1,1);
    rep(i,1,n+1) cout << ans[i] << ' ';
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    while (T--){
        solve();
    }
}