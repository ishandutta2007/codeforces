#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const ll N = 1e5+50;
vector<int> adj[N],ans,a[N];
bool x[N],vis[N],visited[N];
int child[N];
void pre(int v){
    vis[v] = 1;
    for (auto u : adj[v]){
        if (!vis[u]){
            pre(u);
            child[v]+=child[u];
   //         if (x[u]) child[v]++;
        }
    }
    if (x[v]) child[v]++;
}
void tree(int v){
    visited[v] = 1;
    for (int u : adj[v]){
        if (!visited[u]){
            a[v].pb(u);
            tree(u);
            a[u].pb(v);
        }
    }
}

void dfs(int v,int par){
    int t=1;
    bool f = 0;
    ans.pb(v);
    x[v] = 1-x[v];
    visited[v] = 1;
    for (int u : a[v]){
        if (!visited[u] && child[u]){
            dfs(u,v);
            ans.pb(v);
            x[v] = 1-x[v];
        }
    }
    if (x[v] == 1 && par != -1){
        ans.pb(par);
        ans.pb(v);
        x[v] = 0;
        x[par] = 1-x[par];
    }
}
int main(){
    int n,m,start=0;
    cin >> n >> m;
    rep (i,0,m){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep (i,1,n+1) {
        cin >> x[i];
        if (x[i]) start = i;
    }
    pre(start);
    rep(i,1,n){
        if (x[i] && !vis[i]){
            cout << -1;
            return 0;
        }
    }
    if (!child[start]){
        cout << 0;
        return 0;
    }
    tree(start);
    memset(visited,0,sizeof visited);
    dfs(start,-1);
    if (x[start]) ans.pop_back();
    cout << ans.size() << endl;
    for (int u : ans) cout << u << ' ';
    return 0;
}