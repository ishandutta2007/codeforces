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
vector<pair<pll,ll>>adj[N],edge,in[N],adj2[N];
vector<pll> par[N];
ll d[N],d2[N],h[N];
ll cnt[N];
bool vis[N],mark[N],visi[N];
int s,t,n,m;
bool dp[N];
void dij(int v){
    d[v] = 0;
    set<pll> st;
    st.insert({0,v});
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        for (auto u : adj[p.Y]){
            if (d[u.X.X] > d[p.Y]+u.X.Y){
                st.erase({d[u.X.X],u.X.X});
                d[u.X.X] = d[p.Y]+u.X.Y;
                par[u.X.X].clear();
                par[u.X.X].pb({p.Y,u.Y});
                st.insert({d[u.X.X],u.X.X});
            }
            else if (d[u.X.X] == d[p.Y]+u.X.Y) par[u.X.X].pb({p.Y,u.Y});
        }
    }
    return;
}
void dij2(int v){
    d2[v] = 0;
    set<pll> st;
    st.insert({0,v});
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        for (auto u : in[p.Y]){
            if (d2[u.X.X] > d2[p.Y]+u.X.Y){
                st.erase({d2[u.X.X],u.X.X});
                d2[u.X.X] = d2[p.Y]+u.X.Y;
                st.insert({d2[u.X.X],u.X.X});
            }
        }
    }
    return;
}
void dfs(int v){
    vis[v] = 1;
    for (auto u : adj[v]){
        if (d[u.X.X] == d[v]+u.X.Y){
            adj2[u.X.X].pb({{v,u.Y},0});
            adj2[v].pb({{u.X.X,u.Y},1});
        }
        if (!vis[u.X.X]) dfs(u.X.X);
    }
}
void dfs2(int v){
    vis[v] = 1;
    if (v == t){
        dp[v] = 1;
        return;
    }
    for (auto u : adj2[v]){
        if (!u.Y) continue;
        if(!vis[u.X.X]) dfs2(u.X.X);
        dp[v] |= dp[u.X.X];
    }
    return;
}
ll bridge(int v,int p){
    vis[v] = 1;
    ll ans = inf;
    int i = 0,sz = adj2[v].size();
    for (auto k : adj2[v]){
        pll u = k.X;
        if (i < sz-1 && adj2[v][i].X.X == adj2[v][i+1].X.X && edge[u.Y].X.X == edge[adj2[v][i+1].X.Y].X.X){
            mark[adj2[v][i].X.Y] = 0;
            mark[adj2[v][i+1].X.Y] = 0;
        }
        i++;
        if (u.X == v){
            mark[u.Y] = 0;
            continue;
        }
        if (u.X == p) continue;
        if (dp[u.X] == 0) continue;
        if (vis[u.X]){
            ans = min(ans,h[u.X]);
            visi[u.Y] = 1;
        }
        else{
            h[u.X] = h[v]+1;
            ll H = bridge(u.X,v);
            if (H <= h[v]){
                if (!u.Y) debug(u.X);
                mark[u.Y] = 0;
            }
            ans = min(ans,H);
            visi[u.Y] = 1;
        }
        if (h[u.X] < h[v]){
            if (!u.Y) debug(u.X);
            mark[u.Y] = 0;
        }
    }
    return ans;
}
int main(){
    memset(d,63,sizeof d);
    memset(d2,63,sizeof d2);
    memset(mark,1,sizeof mark);
    cin >> n >> m >> s >> t;
    rep(i,1,n+1){
        adj[i].clear();
        in[i].clear();
        edge.clear();
        adj2[i].clear();
        par[i].clear();
        vis[i] = 0;
    }
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({{v,w},i});
        in[v].pb({{u,w},i});
        edge.pb({{u,v},w});
        visi[i] = 0;
    }
    dij(s);
    dij2(t);
    memset(vis,0,sizeof vis);
    dfs(s);
    rep(i,1,n+1) sort(adj2[i].begin(),adj2[i].end());
    memset(vis,0,sizeof vis);
    dfs2(s);
    memset(vis,0,sizeof vis);
    bridge(s,-1);
    debug(mark[0]);
    rep(i,0,m){
        ll u = edge[i].X.X,v = edge[i].X.Y,w = edge[i].Y;
        if (dp[v]&mark[i] && d[u]+d2[v]+w == d[t]){
            cout << "YES" << endl;
            continue;
        }
        if (d[u]+d2[v]+1 >= d[t]) cout << "NO" << endl;
        else{
            cout << "CAN" << ' ' << w-d[t]+d[u]+d2[v]+1 << endl;
        }
    }
    return 0;
}