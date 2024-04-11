#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
int par[N];
pair<pll,bool> e[N];
int vis[N],sz[N];
vector<int> adj[N];
int getpar(int v){
    if (v == par[v]) return v;
    return par[v] = getpar(par[v]);
}
inline void mg(int u,int v){
    u = getpar(u);
    v = getpar(v);
    par[u] = v;
}
bool dfs(int v,int t){
    vis[v] = t;
    for (int u : adj[v]){
        if (vis[u] == t) return 1;
        if (!vis[u] && dfs(u,3-t))
            return 1;
        
    }
    return 0;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,1,n+1) par[i] = i;
    rep(i,0,m){
        cin >> e[i].X.X >> e[i].X.Y >> e[i].Y;
        if (e[i].Y)
            mg(e[i].X.X,e[i].X.Y);
    }
    rep(i,0,m){
        if (e[i].Y) continue;
        int u = getpar(e[i].X.X),v = getpar(e[i].X.Y);
        if (u == v){
            cout << 0;
            return 0;
        }
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int t = 0;
    rep(i,1,n+1){
        if (vis[getpar(i)]) continue;
        if (dfs(getpar(i),1)){
            cout << 0;
            return 0;
        }
        t++;
    }
    cout << poww(2,t-1);
}