#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;

constexpr int N = 2e5+20,mod = 998244353,inf = 1e9+10,maxm = (1 << 18)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(ll a,ll k,ll m){
    if (k < 0) return 0;
    ll z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%m;
        a = 1ll*a*a%m;
        k /= 2;
    }
    return z;
}
vector<int> adj[N];
int h[N];
void dfs(int v,int p){
    for(int u : adj[v]){
        if (u != p){
            h[u] = h[v]^1;
            dfs(u,v);
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        rep(i,1,n+1){
            adj[i].clear();
            h[i] = 0;
        }
        rep(i,1,n){
            int u,v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        rep(i,1,n+1){
            if (h[i]) cout << -int(adj[i].size()) << ' ';
            else cout << adj[i].size() << ' ';
        }
        cout << endl;
    }
}