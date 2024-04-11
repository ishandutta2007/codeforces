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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e18,sq = 400,sig = 26;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
vector<int> adj[N],ve;
int d[N],par[N][20],h[N];
inline void bfs(){
    queue<int> q;
    for (int u : ve){
        q.push(u);
        d[u] = 0;
    }
    ve.clear();
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (d[u] > d[v]+1){
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
}
void dfs(int v,int p){
    par[v][0] = p;
    for (int u : adj[v])
        if (u != p){
            h[u] = h[v]+1;
            dfs(u,v);
        }
}
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0)
        if (h[v]-h[u] >= (1 << i)) v = par[v][i];
    if (u == v) return v;
    repr(i,19,0)
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
inline int dst(int u ,int v){
    int w = lca(u,v);
    return h[u]+h[v]-2*h[w];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(d,63,sizeof d);
    int n,m;
    cin >> n >> m;
    rep(i,1,n){
        int u,v;
        cin >> v >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ve.pb(1);
    dfs(1,0);
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    rep(i,0,m){
        int u,t;
        cin >> t >> u;
        if (t == 2){
            int ans = d[u];
            for (int v : ve)
                ans = min(ans,dst(v,u));
            cout << ans << endl;
        }
        else{
            ve.pb(u);
            if (ve.size() >= sq) bfs();
        }
    }
}