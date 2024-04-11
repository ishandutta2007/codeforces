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
const long long int N=1e5+20,mod = 1e9+7,inf=1e16;
const long double eps = 0.0001;
vector<pll> adj[N],adj2[N];
vector<int> sc;
ll d[N],dist[N];
int par[N];
bool fix[N],mark[N];
vector<pair<ll,pll> > edge;
void dij(){
    set<pll> st;
    for (int u : sc){
        d[u] = 0;
        par[u] = u;
        st.insert({0,u});
    }
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        fix[p.Y] = 1;
        for (pll u : adj[p.Y]){
            if (d[u.X] > d[p.Y]+u.Y){
                st.erase({d[u.X],u.X});
                if (par[u.X]){
                    ll w = d[p.Y]+d[u.X]+u.Y;
                    adj2[par[u.X]].pb({par[p.Y],w});
                    adj2[par[p.Y]].pb({par[u.X],w});
                    edge.pb({w,{par[p.Y],par[u.X]}});
                }
                d[u.X] = d[p.Y]+u.Y;
                par[u.X] = par[p.Y];
                st.insert({d[u.X],u.X});
            }
            else if (fix[u.X] && par[u.X] != par[p.Y]){
                ll w = d[p.Y]+d[u.X]+u.Y;
                adj2[par[u.X]].pb({par[p.Y],w});
                adj2[par[p.Y]].pb({par[u.X],w});
                edge.pb({w,{par[p.Y],par[u.X]}});
            }
        }
    }
}

ll ans;
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
bool merge(pair<ll,pll> e){
    ll u = e.Y.X,v = e.Y.Y,w = e.X;
    if (getpar(u) == getpar(v)) return 0;
   // debug(u);
    //debug(v);
    //debug(w);
    u = par[u];
    v = par[v];
    ans += w;
    par[v] = u;
    return 1;
}
void dij2(){
    dist[1] = 0;
    set<pll> st;
    st.insert({0,1});
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(st.begin());
        int v = p.Y;
        for (pll u : adj[v]){
            if (dist[u.X] > dist[v]+u.Y){
                st.erase({dist[u.X],u.X});
                dist[u.X] = dist[v] +u.Y;
                st.insert({dist[u.X],u.X});
            }
        }
    }
    return;
}
int main(){
    int n,m;
    memset(d,63,sizeof d);
    memset(dist,63,sizeof dist);
    cin >> n >> m;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    int k;
    cin >> k;
    rep(i,0,k){
        int x;
        cin >> x;
        sc.pb(x);
        mark[x] = 1;
    }
    //sc.pb(1);
    dij();
    sort(edge.begin(),edge.end());
    vector<ll> ve;
    for (auto e : edge){
        merge(e);
    }
    if (!mark[1]){
        dij2();
        ll mi = inf;
        for (int u : sc)   mi = min(mi,dist[u]);
        ans+=mi;
    }
    cout << ans;
    return 0;
}