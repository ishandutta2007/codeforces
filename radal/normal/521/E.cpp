#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,ll> pll;
constexpr ll N = 1e6+20,mod = 1e9+7,inf = 1e18+10,maxm = 1e6;
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
int h[N],tin[N],tout[N],T,par[N],n,m;
vector<int> adj[N],ve[3];
set<pll> st[N];
bool vis[N];
void calc(pll p1,pll p2,int v){
    if (h[p1.X] < h[p2.X]) swap(p1,p2);
    int a = p1.X,b = p1.Y,c = p2.X,d = p2.Y;
    int u = v;
    while (u != par[a]){
        ve[0].pb(u);
        u = par[u];
    }
    reverse(ve[0].begin(),ve[0].end());
    u = b;
    ve[1].pb(a);
    while (u != par[v]){
        ve[1].pb(u);
        u = par[u];
    }
    u = a;
    while(u != par[c]){
        ve[2].pb(u);
        u = par[u];
    }
    u = d;
    while (u != par[v]){
        ve[2].pb(u);
        u = par[u];
    }
}
bool dfs(int v){
    vis[v] = 1;
    for (int u : adj[v]){
        if (!vis[u]){
            if (dfs(u)) return 1;
            for (auto u : st[u]) st[v].insert(u);
        }
    }
    for (int u : adj[v]){
        if (u == par[v]) continue;
        if (h[u] < h[v]) st[v].insert({u,v});
        else st[v].erase({v,u});
    }
    if (st[v].size() < 2) return 0;
    pll p1 = *(st[v].begin()),p2;
    st[v].erase(st[v].begin());
    p2 = *(st[v].begin());
    calc(p1,p2,v);
    return 1;
}
void pre(int v,int p){
    vis[v] = 1;
    par[v] = p;
    tin[v] = T;
    T++;
    for(int u : adj[v]){
        if (!vis[u]){
            h[u] = h[v]+1;
            pre(u,v);
        }
    }
    tout[v] = T;
    T++;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,1,n+1)
        if (!vis[i]) 
            pre(i,-1);
    memset(vis,0,sizeof vis);
    rep(i,1,n+1){
        if (!vis[i]){
            if (dfs(i)){
                cout << "YES" << endl;
                rep(j,0,3){
                    cout << ve[j].size() << ' ';
                    for (int u : ve[j]) cout << u << ' ';
                    cout << endl;
                }
                return 0;
            }
        }
    }
    cout << "NO";
}