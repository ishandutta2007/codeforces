#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 2e5+10,mod = 998244353,inf = 1e18,sq = 500;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int sz[N],T,lz[N],par[N];
int tin[N],n,fen[N],bch[N];
vector<int> adj[N];
vector<int> ve[N];
void pre(int v,int p){
    sz[v] = 1;
    par[v] = p;
    tin[v] = T;
    T++;
    int mx = -1,w = -1;
    for (int u : adj[v]){
        if (p != u){
            pre(u,v);
            sz[v] += sz[u];
            if (sz[u] > mx){
                w = u;
                mx = sz[u];
            }
        }
    }
    bch[v] = w;
}
void dfs(int v){
    for (int u : adj[v]){
        if (u == par[v]) continue;
        ve[u].reserve(ve[v].size());
        for(int w : ve[v])
            ve[u].pb(w);
        if (u != bch[v]) ve[u].pb(u);
        dfs(u);
    }
}
inline void upd(int l,int r,int x){
    for(; l < n; l |= (l+1))
        fen[l] = mkay(fen[l],x);
    for(; r < n; r  |=(r+1))
        fen[r] = mkay(-x,fen[r]);
}
inline int que(int v){
    int ans = 0;
    for(; v >= 0; v = (v&(v+1))-1)
        ans = mkay(ans,fen[v]);
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(bch,-1,sizeof bch);
    int q;
    cin >> n >> q;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    pre(1,-1);
    dfs(1);
    int x = poww(n,mod-2);
    rep(j,1,q+1){
        int t,v;
        cin >> t >> v;
        if (t == 1){
            int d;
            cin >> d;
            lz[v] = mkay(lz[v],d);
            upd(0,n,1ll*d*sz[v]%mod);
            upd(tin[v],tin[v]+sz[v],-(1ll*d*sz[v]%mod));
            upd(tin[v],tin[v]+1,1ll*d*n%mod);
            if (bch[v] >= 1)
                upd(tin[bch[v]],tin[bch[v]]+sz[bch[v]],1ll*d*(n-sz[bch[v]])%mod);
            continue;
        }
        int ans = que(tin[v]);
        for(int u : ve[v])
            ans = mkay(ans,1ll*lz[par[u]]*(n-sz[u])%mod);
        cout << 1ll*x*ans%mod << endl;

    }
}