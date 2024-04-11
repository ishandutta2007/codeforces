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
const long long int N=1e5+30,mod = 1e9+7,inf=1e9;
vector <int> adj[N];
int visited[N];
void dfs(int v, int c){
    visited[v] = c;
    for (auto u : adj[v]){
        if (!visited[u]){
            dfs(u,c);
        }
    }
    
}
int main(){
    int n,m,q;
    cin >> n >> m;
    rep(i,0,m){
        int u,v,c;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll t=1;
    rep(i,1,n+1){
        if (!visited[i]) dfs(i,t), t++;
    }
    ll ans=1;
    t = 0;
    sort(visited+1,visited+n+1);
    rep(i,1,n){
        while (i < n && visited[i] == visited[i+1]) {
            i++;
            t++;
        }
        ans *= pow(2,t);
        t=0;
    }
    cout << ans;
}