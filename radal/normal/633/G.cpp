#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 1e5+10,mod = 998244353,inf = 1e9+10,maxm = 1010;
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
        k /= 2;
    } 
    return z; 
}
bitset<maxm> seg[N*4];
bitset<maxm> bi;
int lz[N*4],n,m,a[N],tin[N],sz[N],T;
vector<int> ve,adj[N],ti;
bool mark[maxm];

void dfs(int v,int p){
    sz[v] = 1;
    tin[v] = T;
    ti.pb(v);
    T++;
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        sz[v] += sz[u];
    }
}

void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v][a[ti[l]]] = 1;
        return;
    }
    int mid = (l+r) >> 1,u = (v << 1);
    build(l,mid,u);
    build(mid,r,u|1);
    seg[v] = seg[u]|seg[u|1];
}

void pass(int v,int x){
    lz[v] += x;
    if (lz[v] >= m) lz[v] -= m;
    seg[v] = (seg[v] << x)|(seg[v] >> (m-x));
}

void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s >= r || l >= e) return;
    if (s <= l && r <= e){
        pass(v,x);
        return;
    }
    int mid = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        pass(u,lz[v]);
        pass(u|1,lz[v]);
        lz[v] = 0;
    }
    upd(l,mid,s,e,x,u);
    upd(mid,r,s,e,x,u|1);
    seg[v] = seg[u]|seg[u|1];
}

void que(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e){
        ve.pb(v);
        return;
    }
    if (s >= r || l >= e) return;
    int mid = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        pass(u,lz[v]);
        pass(u|1,lz[v]);
        lz[v] = 0;
    }
    que(l,mid,s,e,u);
    que(mid,r,s,e,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    rep(i,1,n+1){
        cin >> a[i];
        a[i] %= m;
    }
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    build(0,n);
    vector<int> pr;
    rep(i,2,m){
        if (mark[i]) continue;
        pr.pb(i);
        for (int j = 2; j*i < m; j++)
            mark[j*i] = 1;
    }
    int q;
    cin >> q;
    while (q--){
        int tt,v;
        cin >> tt >> v;
        if (tt == 1){
            int x;
            cin >> x;
            x %= m;
            upd(0,n,tin[v],tin[v]+sz[v],x);
            continue;
        }
        ve.clear();
        que(0,n,tin[v],tin[v]+sz[v]);
        bi = seg[ve[0]];
        int sz = ve.size();
        rep(i,1,sz) bi |= seg[ve[i]];
        int ans = 0;
        for (int p : pr){
            ans += bi[p];
        }
        cout << ans << endl;
    }
}