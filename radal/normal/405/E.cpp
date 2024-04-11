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
vector<int> adj[N],ve[N];
int h[N];
bool vis[N];
vector<pair<pll,int>> ans;
void dfs(int v,int p){
    vis[v] = 1;
    for (int u : adj[v]){
        if (vis[u]){
            if (h[u] < h[v] && u != p) ve[u].pb(v);
            continue;
        }
        h[u] = h[v]+1;
        dfs(u,v);
    }
    while (ve[v].size() > 1){
        int u = ve[v].back();
        ve[v].pop_back();
        int w = ve[v].back();
        ve[v].pop_back();
        ans.pb({{u,v},w});
    }
    if (!ve[v].empty()){
        ans.pb({{ve[v][0],v},p});
        ve[v].clear();
    }
    else
        ve[p].pb(v);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin >> n >> m;
    if (m&1){
        cout << "No solution";
        return 0;
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    int sz = ans.size();
    rep(i,0,sz){
        cout << ans[i].X.X << ' ' << ans[i].X.Y << ' ' << ans[i].Y << endl;
    }

}