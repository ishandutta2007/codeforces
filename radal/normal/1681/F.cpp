#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4")
//#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10;
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
int dpd[N],dpu[N],n,sum[N],sz[N],calc[N];
vector<pll> adj[N];
void dfs1(int v,int p,int b){
    int perv = sum[b];
    sz[v] = 1;
    for (pll u : adj[v]){
        if (u.X != p){
            dfs1(u.X,v,u.Y);
            sz[v] += sz[u.X];
        }
    }
    if (b){
        calc[v] = sum[b]-perv;
        dpd[v] = sz[v]-sum[b]+perv;
        sum[b] += dpd[v];
    }
}
void dfs2(int v,int p,int b){
    if (b){
        dpu[v] = sum[b];
        sum[b] = dpd[v];
    }
    for(pll u : adj[v]){
        if (u.X != p){
            dfs2(u.X,v,u.Y);
        }
    }
    if (b){
        sum[b] = dpu[v];
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,1,n){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dfs1(1,0,0);
    rep(i,1,n+1) sum[i] = n-sum[i];
    dfs2(1,0,0);
    ll ans = 0;
    rep(i,2,n+1){
        ans += 1ll*dpd[i]*dpu[i];
    }
    cout << ans;
}