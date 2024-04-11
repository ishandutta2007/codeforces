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
int vis[N];
bool visi[N];
vector<int> adj[N];
bool dfs(int v,int c){
    vis[v] = c;
    for (int u : adj[v]){
        if (vis[u] == vis[v]) return 0;
        if (vis[u] == 3-vis[v]) continue;
        if (!dfs(u,3-c)) return 0;
    }
    return 1;
}
pll dfs2(int v){
    visi[v] = 1;
    int x=0,y=0;
    if (vis[v] == 1) x++;
    else y++;
    for (int u : adj[v]){
        if (!visi[u]){
            pll p = dfs2(u);
            x += p.X;
            y += p.Y;
        }
    }
    return {x,y};
}
int main(){
    cin >> n >> m;
    if (!m){
        cout << 3 << ' ' << n*(n-1)*(n-2)/6;
        return 0;
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool f = 1;
    rep(i,1,n+1) if (!vis[i]) f &= dfs(i,1);
    if (!f){
        cout << 0 << ' ' << 1;
        return 0;
    }
    ll ans = 0;
    rep(i,1,n+1){
        if (!visi[i]){
            pll p = dfs2(i);
            ans += p.X*(p.X-1)/2+p.Y*(p.Y-1)/2;
        }
    }
    if (ans){
        cout << 1 << ' ' << ans;
        return 0;
    }
    cout << 2 << ' ' << m*(n-2);
}