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
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e9+10,sq = 4e4;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k,int m){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%m;
        a = 1ll*a*a%m;
        k >>= 1;
    }
    return z;
}
int n,m,phi;
vector<pll> adj[N];
bool hide[N];
int h[N],sz[N],sum[N],pw[N],sum2[N],inv[N];
map<int,int> cnt;
ll ans;
int cent(int v,int p,int _n){
    for (auto u : adj[v])
        if (u.X != p && !hide[u.X] && sz[u.X]*2 > _n) return cent(u.X,v,_n);
    return v;
}
void siz(int v,int p){
    sz[v] = 1;
    for (auto u : adj[v]){
        if (u.X == p || hide[u.X]) continue;
        siz(u.X,v);
        sz[v] += sz[u.X];
    }
}
void dfs(int v,int p){
    for (auto u : adj[v]){
        if (u.X == p || hide[u.X]) continue;
        h[u.X] = h[v]+1;
        sum[u.X] = sum[v]+1ll*pw[h[v]]*u.Y%m;
        sum2[u.X] = 1ll*sum2[v]*10%m+u.Y;
        if (sum2[u.X] >= m) sum2[u.X] %= m;
        if (sum[u.X] >= m) sum[u.X] %= m;
        dfs(u.X,v);
    }
    int g = m-sum2[v];
    if (g == m) g = 0;
    g = 1ll*g*inv[h[v]]%m;
    cnt[g]++;
}
void calc(int v,int p,int x){
    ans += x*cnt[sum[v]];
    for (auto u : adj[v]){
        if (u.X != p && !hide[u.X]){
            calc(u.X,v,x);
        }
    }
}
void decom(int v){
    siz(v,-1);
    v = cent(v,-1,sz[v]);
    h[v] = 0;
    sum[v] = 0;
    sum2[v] = 0;
    cnt.clear();
    dfs(v,-1);
    hide[v] = 1;
    calc(v,-1,1);
    for (pll u : adj[v]){
        if (hide[u.X]) continue;
        cnt.clear();
        dfs(u.X,v);
        calc(u.X,v,-1);
    }
    for (pll u : adj[v]) if (!hide[u.X]) decom(u.X);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m2;
    cin >> n >> m;
    m2 = m;
    phi = m;
    rep(i,2,sq){
        if (i > m2) break;
        if (m2%i == 0){
            while(m2%i == 0) m2 /= i;
            phi -= phi/i;
        }
    }
    if (m2 > 1) phi -= phi/m2;
    pw[0] = 1;
    inv[0] = 1;
    rep(i,1,n){
        pw[i] = 1ll*pw[i-1]*10%m;
        inv[i] = poww(pw[i],phi-1,m);
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    decom(0);
    cout << ans-n;
    return 0;
}