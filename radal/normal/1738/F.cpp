#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e5+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
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

int d[N];
vector<int> adj[N];
vector<pll> ve;
int vis[N];
void dfs(int v,int t){
    vis[v] = t;
    for (int u : adj[v]) if (!vis[u]) dfs(u,t);
}
inline void solve(){
    ve.clear();
    int n;
    cin >> n;
    rep(i,1,n+1){
        cin >> d[i];
        ve.pb({d[i],i});
        adj[i].clear();
        vis[i] = 0;
    }
    int cnt = 0;
    sort(all(ve));
    repr(i,n-1,0){
        int v = ve[i].Y;
        if (!d[v]) break;
        if (vis[v]) continue;
        vis[v] = 1;
        rep(j,0,d[v]){
            cnt++;
            if (cnt > n) assert(0);
            cout << "? " << v << endl;
            int u;
            cin >> u;
            adj[v].pb(u);
            adj[u].pb(v);
            if (vis[u]) break;
            vis[u] = 1;
        }
    }
    rep(i,1,n+1) vis[i] = 0;
    int t = 1;
    rep(i,1,n+1){
        if (vis[i]) continue;
        dfs(i,t);
        t++;
    }
    cout << "! ";
    rep(i,1,n+1) cout << vis[i] << ' ';
    cout << endl;
}

int main(){
   // ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}