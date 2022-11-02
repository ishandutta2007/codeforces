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
const long long int N=4e5+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
ll n,m,k,q;
bool blue[N];
vector<pll> adj[N],adj2[N];
ll d[N],c[N];
vector<pair<ll,pll> > edge;
vector<pll> Q[N];
vector<ll> comp[N];
ll ans[N];
void dijkstra(){
    set<pll> st;
    rep(i,1,k+1){
        st.insert({0,i});
        d[i] = 0;
        c[i] = i;
    }
    while (!st.empty()){
        pll v = *(st.begin());
        st.erase(st.begin());
        for (pll u : adj[v.Y]){
            if (d[u.X] > d[v.Y]+u.Y){
                st.erase({d[u.X],u.X});
                d[u.X] = d[v.Y]+u.Y;
                c[u.X] = c[v.Y];
                st.insert({d[u.X],u.X});
            }
            else if(st.find({d[u.X],u.X}) == st.end() && c[u.X] != c[v.Y]){
                ll w = d[v.Y]+d[u.X]+u.Y;
                adj2[c[v.Y]].pb({w,c[u.X]});
                adj2[c[u.X]].pb({w,c[v.Y]});
                edge.pb({w,{min(c[u.X],c[v.Y]),max(c[u.X],c[v.Y])}});
            }
        }
    }
    return;
}
int getpar(int v){
    if (c[v] == v) return v;
    return c[v] = getpar(c[v]);
}
void merge(int u,int v,ll w){
    u = getpar(u);
    v = getpar(v);
    if (u == v) return;
    if(comp[v].size() < comp[u].size()) swap(u,v);
    while (!comp[u].empty()){
        int ve = comp[u].back();
        comp[u].pop_back();
        if (!Q[ve].empty()){
            for (pll p : Q[ve]) {
                if (getpar(p.X) == v ){
                    ans[p.Y] = w;
                }
            }
        }
        comp[v].pb(ve);
    }
    c[u] = v;
    return;
}
int main(){
    memset(d,63,sizeof d);
    cin >> n >> m >> k >> q;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    rep(i,1,k+1) blue[k+1]  = 1;
    dijkstra();
    rep(i,1,n+1) comp[c[i]].pb(i);
    rep(i,0,q){
        int u,v;
        cin >> u >> v;
        Q[u].pb({v,i});
        Q[v].pb({u,i});
    }
    sort(edge.begin(),edge.end());
    int sz = edge.size();
    rep(i,0,sz) merge(edge[i].Y.X,edge[i].Y.Y,edge[i].X);
    rep(i,0,q){
        cout << ans[i] << endl;
    }
    return 0;
}