#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2,fma")
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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e18+10,maxm= (1 << 21);
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
int h[N],mx[N],r,n;
ll ans;
vector<int> adj[N];
void dfs(int v,int p){
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        mx[v] = max(mx[v],mx[u]);
    }
    if (v != r){
        if (mx[v] < h[v]){
            ans += h[v]-mx[v];
        }
        mx[v] = max(mx[v],h[v]);
        return;
    }
    int m1 = 0,m2 = 0;
    for (int u : adj[v]){
        if (mx[u] > m1){
            m2 = m1;
            m1 = mx[u];
        }
        else if (mx[u] > m2){
            m2 = mx[u];
        }
    }
    ans += max(0,h[v]-m1)+max(h[v]-m2,0);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int k = 0;
    rep(i,1,n+1){
        cin >> h[i];
        if (h[i] > k){
            k = h[i];
            r = i;
        }
    }
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(r,-1);
    cout << ans;
 }