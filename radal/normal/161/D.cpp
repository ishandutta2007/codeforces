#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
typedef long long  int ll;
typedef pair<int,int> pll;
const ll N = 5e4+50;
int dp[N][520],p[N];
vector <int> adj[N];
void simp(int v,int par){
    p[v] = par;
    for (int u : adj[v]) if (u != par) simp(u,v);
}
void dfs(int v,int par,int k){
    if (k == 0){
        dp[v][k] = 1;
        return;
    }
    dp[v][k] = 0;
    for (int u : adj[v]){
        if (u != par){
            if (dp[u][k-1] == -1) dfs(u,v,k-1);
            dp[v][k] += dp[u][k-1];
        }
    }
}
ll out(int v,int par,int k){
    ll ans=dp[v][k];
    ll sum = 0;
    for (int u : adj[v]){
        if (u != par){
            rep(i,0,k-1){
                sum += dp[u][i]*(dp[v][k-i-1]-dp[u][k-i-2]);
            }
            ans += out(u,v,k);
        }
    }
    return ans+sum/2;
}
int main(){
    memset(dp,-1,sizeof dp);
    int n,k;
    cin >> n >> k;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    simp(1,-1);
    rep (i,1,n+1) rep (j,0,k+1) if (dp[i][j] == -1) dfs(i,p[i],j);
    debug(dp[2][2]);
    cout << out(1,-1,k);
}