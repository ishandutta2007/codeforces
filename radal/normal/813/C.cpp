#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+5,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int mx[N],par[N],h[N];
vector<int> adj[N];
void dfs(int v,int p){
    par[v] = p;
    mx[v] = h[v];
    for (int u : adj[v]){
        if (u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v);
        mx[v] = max(mx[v],mx[u]);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin >> n >> x;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    int ans = mx[x];
    int t = 0,cur = x;
    while (1){
        cur = par[cur];
        t++;
        if (h[cur] <= t) break;
        ans = mx[cur];
    }
    cout << ans*2;
    return 0;
}