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
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e18,dlt = 12250;
ll poww(ll n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return r*r*poww(n,k&1)%mod;
}
vector<int> adj[N];
int n;
ll dp[N][2],l[N],r[N];;
void dfs(int v,int p,bool c){
    int val = l[v];
    if (c) val = r[v];
    dp[v][c] = 0;
    for (int u : adj[v]){
        if (u == p) continue;
        if (dp[u][0] == -1) dfs(u,v,0);
        if (dp[u][1] == -1) dfs(u,v,1);
        dp[v][c] += max(dp[u][0]+abs(l[u]-val),dp[u][1]+abs(r[u]-val));
    }
}
int main(){
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        rep(i,1,n+1){
            cin >> l[i] >> r[i];
            dp[i][0] = -1;
            dp[i][1] = -1;
            adj[i].clear();
        }
        rep(i,1,n){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,-1,0);
        dfs(1,-1,1);
        cout << max(dp[1][1],dp[1][0]) << endl;
    }
    return 0;
}