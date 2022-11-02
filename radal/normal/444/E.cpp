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
const long long int N=3e3+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
pair<int,pll> edge[N];
vector<int> adj[N];
int ans[N];
vector<pll> comp[N];
int par[N],cnt[N],t[N];
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
void merge(int u,int v,int w){
    u = getpar(u);
    v = getpar(v);
    sort(comp[u].begin(),comp[u].end());
    sort(comp[v].begin(),comp[v].end());
    if (comp[u].size() < comp[v].size()) swap(u,v);
    ll p=0;
    int sz = comp[u].size();
    for (pll vert : comp[v]){
        t[vert.Y] = 0;
        while (p < sz && t[vert.Y] < cnt[vert.Y]){
            t[vert.Y]++;
            t[ans[comp[u][p].Y]]--;
            comp[u][p].X = w;
            ans[comp[u][p].Y] = vert.Y;
            p++;
        }
    }
    p = 0;
    sz = comp[v].size();
    for (pll vert : comp[u]){
        while (p < sz && t[vert.Y] < cnt[vert.Y]){
            t[vert.Y]++;
            t[ans[comp[v][p].Y]]--;
            comp[v][p].X = w;
            ans[comp[v][p].Y] = vert.Y;
            p++;
        }
        if (p == sz) break;
    }
    while (!(comp[v].empty())){
        pll vert = comp[v].back();
        comp[v].pop_back();
        comp[u].pb(vert);
    }
    par[v] = u;
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >>  n;
    rep(i,0,n-1){
        int v,u,w;
        cin >> v >> u >> w;
        if (v > u) swap(v,u);
        edge[i] = {w,{v,u}};
        adj[v].pb(u);
        adj[u].pb(v);
        comp[i+1].pb({0,i+1});
        par[i+1] = i+1;
    }
    comp[n].pb({0,n});
    par[n] = n;
    rep(i,1,n+1) cin >> cnt[i];
    sort(edge,edge+n-1);
    rep(i,0,n-1){
        merge(edge[i].Y.X,edge[i].Y.Y,edge[i].X);
        getpar(1);
    }
    ll out = inf;
    rep(i,1,n+1){
        if (!(comp[i].empty())){
            for (pll v : comp[i]) out = min(out,v.X);
        }
    }
    cout << out;
    return 0;
}