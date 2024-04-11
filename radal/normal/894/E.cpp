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
const long long int N=1e6+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
bool vis[N],mark[N];
vector<int> ve,scc[N];
vector<pll> out[N],in[N];
int col[N],din[N],ind[N];
ll sum[N],dp[N];
vector<pll> g[N],adj[N];
void dfs(int v){
    vis[v] = 1;
    for (pll u : out[v]) if (!vis[u.X]) dfs(u.X);
    ve.pb(v);
}
void sfd(int v,int c){
    vis[v] = 1;
    col[v] = c;
    scc[c].pb(v);
    for (pll u : in[v]) if(!vis[u.X]) sfd(u.X,c);
}
void dfs2(int v){
    vis[v] = 1;
    ve.pb(v);
    ind[v] = ve.size()-1;
    for(pll u : g[v]){
        din[u.X]--;
        if (!din[u.X]) dfs2(u.X);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        out[u].pb({v,w});
        in[v].pb({u,w});
    }
    rep(i,1,n+1) if (!vis[i]) dfs(i);
    int c = 0;
    memset(vis,0,sizeof vis);
    repr(i,n-1,0){
        if (!vis[ve[i]]){
            c++;
            sfd(ve[i],c);
        }
    }
    rep(i,1,c+1){
        for (int u : scc[i]){
            for (pll v : out[u]){
                if (col[v.X] == i){
                    ll b = sqrt(2*v.Y);
                    if (b*(b+1)/2 < v.Y) b++;
                    sum[i]+= v.Y*(b+1)-b*(b+1)*(b+2)/6;
                    sum[i] += b*(b+1)/2-v.Y;
                }
                else{
                    g[i].pb({col[v.X],v.Y});
                    adj[col[v.X]].pb({i,v.Y});
                    din[col[v.X]]++;
                }
            }
        }
    }
    memset(vis,0,sizeof vis);
    ve.clear();
    rep(i,1,c+1) if (!din[i] && !vis[i]) dfs2(i);
    int x;
    cin >> x;
    mark[ind[col[x]]] = 1;
    ll ans = 0;
    rep(i,0,c){
        if (!mark[i]) continue;
        dp[i] = sum[ve[i]];
        ll mx = 0;
        for (pll u : adj[ve[i]]) if (mark[ind[u.X]]) mx = max(mx,u.Y+dp[ind[u.X]]);
        dp[i] += mx;
        ans = max(ans,dp[i]);
        for (pll u : g[ve[i]]) mark[ind[u.X]] = 1;
    }
    cout << ans;
    return 0;
}