#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
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
const long long int N=1e6+20,mod = 1e9+7,inf=3e8;
const long double eps = 0.0001;
vector<pair<pll,int> > adj[N];
int visited[N];
int par[N];
bool mark[N],vis[N];
vector<pair<pll,bool> > edge;
void dfs(int v,int t){
    visited[v] = t;
    for (auto u : adj[v]){
        if (!visited[u.X.X] && u.X.Y){
            par[u.X.X] = v;
            dfs(u.X.X,t);
        }
    }
    return;
}
void dfs2(int v){
    vis[v] = 1;
    for (auto u : adj[v]){
        if (!vis[u.X.X] && mark[u.Y]){
            par[u.X.X] = v;
            dfs2(u.X.X);
        }
    }
    return;
}
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
bool merge(int u,int v){
    if (getpar(u) == getpar(v)) return 0;
    u = par[u];
    v = par[v];
    par[u] = v;
    return 1;
}
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        char c;
        cin >> u >> v >> c;
        if (c == 'M'){
            adj[u].pb({{v,0},i});
            adj[v].pb({{u,0},i});
            edge.pb({{u,v},0});
        }
        else{
            adj[u].pb({{v,1},i});
            adj[v].pb({{u,1},i});
            edge.pb({{u,v},1});
        }
    }
    if (n%2 == 0){
        cout << -1;
        return 0;
    }
    int t = 0;
    rep(i,1,n+1){
        if (!visited[i]){
            par[i] = i;
            t++;
            dfs(i,t);
        }
    }
    if (t-1 > (n-1)/2){
        cout << -1;
        return 0;
    }
    int cnt = t-1;
    rep(i,0,m){
        if (edge[i].Y == 0) if (merge(edge[i].X.X,edge[i].X.Y)) mark[i] = 1;
    }
    memset(par,0,sizeof par);
    rep(i,1,n+1){
        if (!vis[i]){
            dfs2(i);
            par[i] = i;
        }
    }
    rep(i,0,m){
        if (cnt == (n-1)/2) break;
        if (edge[i].Y == 0 && !mark[i]){
            if (merge(edge[i].X.X,edge[i].X.Y)){
                cnt++;
                mark[i] = 1;
            }
        }
    }
    if (cnt < (n-1)/2){
        cout << -1;
        return 0;
    }
    rep(i,0,m){
        if (edge[i].Y == 1){
            mark[i] = merge(edge[i].X.X,edge[i].X.Y);
        }
    }
    cout << n-1 << endl;
    rep(i,0,m) if (mark[i]) cout << i+1 << ' ';
    return 0;
}