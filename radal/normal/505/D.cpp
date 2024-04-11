#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=2e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
int poww(int n,int k){
    if (!k) return 1;
    if (k == 1) return n;
    ll r = poww(n,k/2);
    return (((r*r)%mod)*poww(n,k&1))%mod;
}
int vis[N],comp[N],sz[N];
bool dg[N];
vector<int> adj[N],out[N];
void pre(int v,int c){
    comp[v] = c;
    sz[c]++;
    for (int u : adj[v]) if (!comp[u]) pre(u,c);
}
bool dfs(int v){
    vis[v] = 1;
    for (int u : out[v]){
        if (vis[u] == 1) return 0;
        if (vis[u] == 2) continue;
        if (!dfs(u)) return 0;
    }
    vis[v] = 2;
    return 1;
}
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        out[u].pb(v);
    }
    int c = 0;
    rep(i,1,n+1){
        if(!comp[i]){
            c++;
            dg[c] = 1;
            pre(i,c);
        }
    }
    rep(i,1,n+1){
        if (vis[i]) continue;
        if (!dfs(i)) dg[comp[i]] = 0;
    }
    int ans = 0;
    rep(i,1,c+1){
        if (dg[i]) ans += sz[i]-1;
        else ans += sz[i];
    }
    cout << ans;
    return 0;
}