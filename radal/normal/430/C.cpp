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
vector <int> adj[N],ans;
bool init[N],goal[N],visited[N];
int h[N];
void dfs(int v,int he){
    h[v] = he;
    visited[v] = 1;
    for(int u : adj[v]){
        if (!visited[u]){
            dfs(u,he+1);
        }
    }
}
void dfs2(int v,int te,int to){
    visited[v] = 1;
    if (h[v]%2){
        if ((goal[v] != init[v] && to%2 == 0) || (goal[v] == init[v] && to%2)){
            ans.pb(v);
            to++;
        }
    }
    else{
        if ((goal[v] != init[v] && te%2 == 0) || (goal[v] == init[v] && te%2)){
            ans.pb(v);
            te++;
        }
    }
    for(int u : adj[v]){
        if (!visited[u]){
            dfs2(u,te,to);
        }
    }
}
int main(){
    int n;
    cin >> n;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,1,n+1){
        cin >> init[i];
    }
    rep(i,1,n+1){
        cin >> goal[i];
    }
    dfs(1,0);
    memset(visited,0,sizeof visited);
    dfs2(1,0,0);
    cout << ans.size() << endl;
    for (int v : ans) cout << v << endl;
}