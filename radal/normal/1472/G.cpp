#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
vector<int> adj[N];
int d[N],dp[N];
void bfs(){
    d[1] = 0;
    queue <int> q;
    q.push(1);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if(d[u] == -1){
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
    return;
}
void dfs(int v){
    dp[v] = d[v];
    for (int u : adj[v]){
        if (d[u] <= d[v]){
            dp[v] = min(dp[v] , d[u]);
        }
        else{
            if (dp[u] == -1) dfs(u);
            dp[v] = min(dp[v],dp[u]);
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        memset(d,-1,sizeof d);
        memset(dp,-1,sizeof dp);
        rep(i,1,n+1) adj[i].clear();
        rep(i,0,m){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
        }
        bfs();
        rep(i,1,n+1) if (dp[i] == -1) dfs(i);
        rep(i,1,n+1){
            cout << dp[i] << ' ';

        }
        cout << endl;
    }
    return 0;
}