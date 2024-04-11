#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
vector<pll> adj[N];
bool vis[N],mark[N];
vector<int> in[N],out[N],ve1,ve2;
int n,m;
void pre(int v){
    vis[v] = 1;
    for (pll u : adj[v]){
        if (mark[u.Y]) continue;
        out[v].pb(u.X);
        in[u.X].pb(v);
        mark[u.Y] = 1;
        if (vis[u.X]) continue;
        pre(u.X);
    }
}
void dfs(int v){
    vis[v] = 1;
    ve1.pb(v);
    for (int u : out[v]) if (!vis[u]) dfs(u);
}
void sfd(int v){
    ve2.pb(v);
    vis[v] = 1;
    for (int u : in[v]) if (!vis[u]) sfd(u);
}
int main(){
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }
    pre(1);
    memset(vis,0,sizeof vis);
    dfs(1);
    memset(vis,0,sizeof vis);
    sfd(1);
    if (min(ve1.size(),ve2.size()) != n) cout << 0;
    else{
        rep(i,1,n+1){
            for (int u : out[i]){
                cout << i << ' ' << u << endl;
            }
        }
    }
}