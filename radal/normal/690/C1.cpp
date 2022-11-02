#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=5e5+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
ll n,m;
bool vis[N];
vector<int> adj[N];
void dfs(int v){
    vis[v] = 1;
    for (int u : adj[v]){
        if (!vis[u]) dfs(u);
    }
    return;
}
int main(){
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (m != n-1){
        cout << "no";
        return 0;
    }
    dfs(1);
    rep(i,1,n+1){
        if (!vis[i]){
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
}