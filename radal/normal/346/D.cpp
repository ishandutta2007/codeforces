#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e6+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int dp[N];
bool vis[N];
int s,t;
vector<int> adj[N],in[N];
int cnt[N];
void dfs(int v){
    vis[v] = 1;
    for (int u : adj[v]) if (!vis[u]) dfs(u);
}
void bfs(){
    deque<int> q;
    q.pb(t);
    while (!q.empty()){
        int u = q.front();
        q.pop_front();
        if (vis[u]) continue;
        for (int v : in[u]){
            cnt[v]++;
            if (dp[v] > dp[u] && cnt[v] == adj[v].size()){
                q.push_front(v);
                dp[v] = dp[u];
            }
            else if (dp[v] > dp[u]+1){
                dp[v] = dp[u]+1;
                q.pb(v);
            }
        }
        vis[u] = 1;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    memset(dp,63,sizeof dp);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        in[v].pb(u);
    }
    cin >> s >> t;
    dfs(s);
    if (!vis[t]){
        cout << -1;
        return 0;
    }
    dp[t] = 0;
    memset(vis,0,sizeof vis);
    bfs();
    cout << dp[s];
    return 0;
}