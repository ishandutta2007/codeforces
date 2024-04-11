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
constexpr ll N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
int dp[N][2],dp2[2];
vector<int> adj[N];
void dfs(int v){
    dp[v][1] = 1;
    for (int u : adj[v]){
        dfs(u);
        int x = dp[v][1];
        dp[v][1] = mkay(1ll*dp[v][1]*(dp[u][0]+1)%mod,1ll*dp[v][0]*dp[u][1]%mod);
        dp[v][0] = mkay(1ll*dp[v][0]*(dp[u][0]+1)%mod,1ll*x*dp[u][1]%mod);
    }
    dp[v][1] = mkay(dp[v][1],dp[v][1]);
    dp[v][0] = mkay(dp[v][0],dp[v][0]);
    int z = 1;
    for (int u : adj[v]) z = 1ll*z*(dp[u][0]+1)%mod;
    dp[v][1] = mkay(dp[v][1],-z);
    dp2[0] = 1;
    dp2[1] = 0;
    for (int u : adj[v]){
        int x = dp2[0];
        dp2[0] = mkay(1ll*dp2[1]*dp[u][1]%mod,dp2[0]);
        dp2[1] = mkay(1ll*x*dp[u][1]%mod,dp2[1]);
    }
    dp[v][0] = mkay(dp[v][0],-dp2[1]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,2,n+1){
        int v;
        cin >> v;
        adj[v].pb(i);
    }
    dfs(1);
    cout << mkay(dp[1][0],dp[1][1]);
}