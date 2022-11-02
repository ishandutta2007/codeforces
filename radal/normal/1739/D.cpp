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

vector<int> adj[N],ve;
int par[N][20],h[N],T,tin[N],sz[N];
int n,k;
pll seg[N*4];

void dfs(int v){
    tin[v] = T++;
    sz[v] = 1;
    ve.pb(v);
    for (int u : adj[v]){
        dfs(u);
        sz[v] += sz[u];
    }
}

void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v] = {h[ve[l]],ve[l]};
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}

void upd(int l,int r,int s,int e,int v = 1){
    if (l >= e || s >= r) return;
    if (s <= l && r <= e){
        seg[v] = {-1,-1};
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    upd(l,m,s,e,u);
    upd(m,r,s,e,u|1);
    seg[v] = max(seg[u],seg[u|1]);
}

int getpar(int v,int x){
    while (x){
        int cn = __builtin_ctz(x);
        x -= (1 << cn);
        v = par[v][cn];
    }
    return v;
}

bool check(int x){
    build(0,n);
    int cnt = 0;
    while (cnt <= k && seg[1].X > x){
        int v = seg[1].Y,p = getpar(v,x-1);
        upd(0,n,tin[p],tin[p]+sz[p]);
        cnt++;
    }
    return ((cnt <= k));
}

int bs(){
    if (n == 1) return 0;
    int l = 0,r = n-1,m;
    while (r-l > 1){
        m = (l+r) >> 1;
        if (check(m)) r = m;
        else l = m;
    }
    return r;
}
void solve(){
    cin >> n >> k;
    rep(i,1,n+1) adj[i].clear();
    rep(i,2,n+1){
        cin >> par[i][0];
        h[i] = h[par[i][0]]+1;
        adj[par[i][0]].pb(i);
    }
    rep(j,1,20){
        rep(i,2,n+1) 
            par[i][j] = par[par[i][j-1]][j-1];
    }
    T = 0;
    ve.clear();
    dfs(1);
    cout << bs() << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}