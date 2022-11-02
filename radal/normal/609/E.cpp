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
vector <int> comp[N];
vector<pll> adj[N];
ll mark[N];
ll edge[N];
int getpar(int v){
    if (v == par[v]) return v;
    return par[v] = getpar(par[v]);
}
bool merge(int u,int v,int w){
    if (getpar(u) == getpar(v)) return 0;
    u = par[u];
    v = par[v];
    if (comp[u].size() > comp[v].size()) swap(u,v);
    int cnt = comp[u].size();
    while (cnt--){
        int ver = comp[u].back();
        comp[u].pop_back();
        comp[v].pb(ver);
        for (pll s : adj[ver]){
            if (getpar(s.X) == v){
                mark[s.Y] = w;
            }
        }
    }
    par[u] = v;
    return 1;
}
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,1,n+1){
        par[i] = i;
        comp[i].pb(i);
    }
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        e.pb({{w,i},{u,v}});
        adj[u].pb({v,i});
        adj[v].pb({u,i});
        edge[i] = w;
    }
    sort(e.begin(),e.end());
    ll ans = 0;
    rep(i,0,m){
        if (merge(e[i].Y.X,e[i].Y.Y,e[i].X.X)){
            ans += e[i].X.X;
            mark[e[i].X.Y] = e[i].X.X;
        }
    }
    rep(i,0,m) cout << ans-mark[i]+edge[i] << endl;
    return 0;
}