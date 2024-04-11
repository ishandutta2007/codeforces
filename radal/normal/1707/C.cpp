#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 3e5+10,mod = 998244353,inf = 1e9+10;
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
int tin[N],T,par[N],tout[N],h[N];
vector<int> adj[N];
int seg[N*4],pr[N][20];
bool bad[N];
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
void dfs(int v,int p){
    pr[v][0] = p;
    tin[v] = T;
    T++;
    for (int u : adj[v])
        if (u != p){
            h[u] = h[v]+1;
            dfs(u,v);
        }
    tout[v] = T;
    T++;
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] >= (1 << i))
            v = pr[v][i];
    }
    if (v == u) return v;
    repr(i,19,0){
        if (pr[v][i] != pr[u][i]){
            v = pr[v][i];
            u = pr[u][i];
        }
    }
    return pr[v][0];
}
void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s <= l && r <= e){
        seg[v] += x;
        return;
    }
    if (s >= r || l >= e) return;
    int m = (l+r) >> 1,u = (v << 1);
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
}
int que(int l,int r,int p,int v = 1){
    if (r-l == 1) return seg[v];
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) return que(l,m,p,u)+seg[v];
    return que(m,r,p,u|1)+seg[v];
}
inline void solve(){
    vector<pair<int,pll> > e;
    int n,m;
    cin >> n >> m;
    rep(i,1,n+1) par[i] = i;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        e.pb({i,{u,v}});
    }
    sort(all(e));
    rep(i,0,m){
        int u = e[i].Y.X,v = e[i].Y.Y;
        if (getpar(u) != getpar(v)){
            adj[u].pb(v);
            adj[v].pb(u);
            u = par[u];
            v = par[v];
            par[u] = v;
        }
        else bad[i] = 1;
    }
    dfs(1,0);
    rep(i,1,20){
        rep(j,2,n+1)
            pr[j][i] = pr[pr[j][i-1]][i-1];
    }
    rep(i,0,m){
        if (!bad[i]) continue;
        int u = e[i].Y.X,v = e[i].Y.Y;
        if (h[u] > h[v]) swap(u,v);
        if (tin[u] <= tin[v] && tout[v] <= tout[u]){
            upd(0,T,tin[v],tout[v],-1);
            int w = h[v]-h[u]-1;
            repr(i,19,0){
                if (w >= (1 << i)){
                    w -= (1 << i);
                    v = pr[v][i];
                }
            }
            upd(0,T,tin[v],tout[v],1);
            continue;
        }
        else{
            int w = lca(u,v);
            upd(0,T,tin[1],tout[1],1);
            upd(0,T,tin[u],tout[u],-1);
            upd(0,T,tin[v],tout[v],-1);
        }
    }
    rep(i,1,n+1){
        if (que(0,T,tin[i]) > 0) cout << 0;
        else cout << 1;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
  //  cin >> T;
    while (T--){
        solve();
    }
    return 0;
}