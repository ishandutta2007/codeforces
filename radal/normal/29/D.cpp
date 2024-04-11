#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=4e2+30,mod = 1e9+7,inf=1e9;
vector <int> adj[N],ans;
bool vis[N],visited[N];
int a[N],par[N];
int p;
void df(int v,int pa){
    par[v] = pa;
    for (int u : adj[v]){
        if (u != pa) df(u,v);
    }


}
bool child(int v,int c){
    if (v == c) return 1;
    vis[v] = 1;
    for (int u : adj[v]){
        if (u != par[v]){
            if (u == c || child(u,c)) return 1;
        }
    }
    return 0;
}
void dfs(int v,int n){
    visited[v] = 1;
    ans.pb(v);
    if (p < n && v == a[p]){
        p++;
        return;
    }
    bool f = 1;
    while (p < n && child(v,a[p]) && f){
        f = 0;
        for (int u : adj[v]){
            if (!visited[u] && child(u,a[p])){
                dfs(u,n);
                f = 1;
                ans.pb(v);
            }
        }
       // debug(v);
    }

}
int main(){
    ll n,t=0;
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,2,n+1) if (adj[i].size() == 1) t++;
    rep(i,0,t)
        cin >> a[i];
    df(1,-1);
    dfs(1,t);
 //   debug(ans.size());
    if(ans.size()!=2*n-1){
        cout << -1;
        return 0;
    }
    for(int u : ans) cout << u << ' ';
}