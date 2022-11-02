#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 2e18,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
vector<int> adj[N];
ll a[N];
ll mx,sum[N];
pair<int,ll> dp[N];
void dfs(int v,int p){
    sum[v] = a[v];
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        if (sum[u] > 0) sum[v] += sum[u];
    }
    mx = max(mx,sum[v]);
}
void dfs2(int v,int p){
    dp[v].Y = a[v];
    for (int u : adj[v]){
        if (u == p) continue;
        dfs2(u,v);
        dp[v].X += dp[u].X;
        if (dp[u].Y > 0) dp[v].Y += dp[u].Y;
    }
    if (dp[v].Y == mx){
        dp[v].X++;
        dp[v].Y = 0;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    mx = -inf;
    dfs(1,-1);
    dfs2(1,-1);
    cout << 1ll*mx*dp[1].X << ' ' << dp[1].X;
}