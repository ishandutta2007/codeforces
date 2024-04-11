#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,len = 7;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
vector<int> adj[N][2];
vector<pll> comp[N];
vector<pair<pll,pll> > ans;
int par[N];
int getpar(int v){
    if (v == par[v]) return v;
    return par[v] = getpar(par[v]);
}
inline void mg(int v,int u){
    v = getpar(v);
    u = getpar(u);
    if (u == v) return;
    if (comp[u].size() > comp[v].size()) swap(u,v);
    while (!comp[u].empty()){
        pll p = comp[u].back();
        comp[u].pop_back();
        if (getpar(p.Y) == v || getpar(p.Y) == u) continue;
        comp[v].pb(p);
    }
    par[u] = v;
}
void dfs(int v,int p){
    for (int u : adj[v][0]){
        if (u == p) continue;
        dfs(u,v);
        int ind = lower_bound(all(adj[v][1]),u) - adj[v][1].begin();
        if (ind < (int)adj[v][1].size() && adj[v][1][ind] == u){
            mg(v,u);
            continue;
        }
        int pr = getpar(u);
        pll p = comp[pr].back();
        while (getpar(p.Y) == pr){
            comp[pr].pop_back();
            p = comp[pr].back();
        }
        mg(p.X,p.Y);
        ans.pb({{u,v},p});
        mg(p.X,p.Y);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(j,0,2){
        rep(i,1,n){
            int u,v;
            cin >> u >> v;
            adj[u][j].pb(v);
            adj[v][j].pb(u);
            if (j){
                comp[u].pb({u,v});
                comp[v].pb({v,u});
            }
        }
    }
    rep(i,1,n+1){
        par[i] = i;
        sort(all(adj[i][1]));
    }
    dfs(1,-1);
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.X.X << ' ' << p.X.Y << ' ' << p.Y.X << ' ' << p.Y.Y << endl;
}