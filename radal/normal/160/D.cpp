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
typedef pair<int,int> pll;
const long long int N=2e5+20,mod = 1e9+7,inf=2e18,maxk = 1e5+20;
const long double eps = 0.0001;
vector<pair<pll,pll>> e;
int par[N];
vector<pll> adj[N];
int mark[N];
bool vis[N],bridge[N];
ll h[N],d[N];
int getpar(int v){
    if (v == par[v]) return v;
    return par[v] = getpar(par[v]);
}
bool merge(int u,int v){
    if (getpar(u) == getpar(v)) return 0;
    u = par[u];
    v = par[v];
    par[u] = v;
    adj[u].clear();
    adj[v].clear();
    return 1;
}
void dfs(int v,int p){
    vis[v] = 1;
    int i = 0,sz = adj[v].size();
    sort(adj[v].begin(),adj[v].end());
    for (pll u : adj[v]){
        if (!vis[u.X]){
           h[u.X] = h[v]+1;
            dfs(u.X,v);
            d[v] = min(d[v],d[u.X]);
            if (d[u.X] > h[v]) bridge[u.Y] = 1;
        }
        else if (u.X != p)  d[v] = min(h[u.X],d[v]);
        if (i+1 < sz && adj[v][i].X == adj[v][i+1].X) bridge[u.Y] = 0;
        if (i && adj[v][i].X == adj[v][i-1].X) bridge[u.Y]  = 0;
        i++;
    }
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,1,n+1){
        par[i] = i;
    }
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        e.pb({{w,i},{u,v}});
    }
    sort(e.begin(),e.end());
    rep(i,0,m){
        int s,st = i;
        vector<int> ve;
        if (getpar(e[i].Y.X) == getpar(e[i].Y.Y)){
            mark[e[i].X.Y] = 1;
            continue;
        }
        int u = par[e[i].Y.X],v = par[e[i].Y.Y];
        adj[u].pb({v,e[i].X.Y});
        adj[v].pb({u,e[i].X.Y});
        vis[v] = 0;
        vis[u] = 0;
        d[u] = inf;
        d[v] = inf;
        ve.pb(u);
        ve.pb(v);
        while (i+1 < m && e[i+1].X.X == e[i].X.X){
            i++;
            if (getpar(e[i].Y.X) == getpar(e[i].Y.Y)){
                mark[e[i].X.Y] = 1;
                if (e[i].X.Y == 3) debug(par[e[i].Y.X]);
                continue;
            }
            int u = par[e[i].Y.X],v = par[e[i].Y.Y];
            adj[u].pb({v,e[i].X.Y});
            adj[v].pb({u,e[i].X.Y});
            vis[v] = 0;
            vis[u] = 0;
            d[u] = inf;
            d[v] = inf;
            ve.pb(u);
            ve.pb(v);
        }
        for (int s : ve){
            if (vis[s]) continue;
            h[s] = 0;
            dfs(s,-1);
        }
        rep(j,st,i+1) merge(e[j].Y.X,e[j].Y.Y);
    }
    rep(i,0,m){
        if (mark[i]){
            cout << "none" << endl;
            continue;
        }
        if (bridge[i]){
            cout << "any" << endl;
            continue;
        }
        cout << "at least one" << endl;
    }
    return 0;
}