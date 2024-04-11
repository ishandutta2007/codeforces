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
const int N = 2e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
int par[N],n,a[N],T,tin[N],sz[N],ind[N],d[N];
int seg[4*N],lz[4*N];
vector<int> adj[N];
pair<int,pll> q[N];
void dfs(int v){
    tin[v] = T;
    sz[v] = 1;
    for(int u : adj[v]){
        if (u != par[v]){
            T++;
            dfs(u);
            sz[v] += sz[u];
        }
    }
}
void upd2(int l,int r,int p,int x,int v){
    if (r-l == 1){
        seg[v] += x;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v] != 1){
        lz[u] = 1ll*lz[v]*lz[u]%mod;
        lz[u|1] = 1ll*lz[v]*lz[u|1]%mod;
        seg[u] = 1ll*lz[v]*seg[u]%mod;
        seg[u|1] = 1ll*lz[v]*seg[u|1]%mod;
        lz[v] = 1;
    }
    if (m > p) upd2(l,m,p,x,u);
    else upd2(m,r,p,x,u+1);
    seg[v] = mkay(seg[2*v],seg[2*v+1]);
}
void upd(int l,int r,int s,int e,int x,int v){
    if (l >= s && e >= r){
        lz[v] = 1ll*lz[v]*x%mod;
        seg[v] = 1ll*x*seg[v]%mod;
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v] != 1){
        lz[u] = 1ll*lz[u]*lz[v]%mod;
        seg[u] = 1ll*lz[v]*seg[u]%mod;
        lz[u|1] = 1ll*lz[u|1]*lz[v]%mod;
        seg[u|1] = 1ll*seg[u|1]*lz[v]%mod;
        lz[v] = 1;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = mkay(seg[u],seg[u|1]);
}
int que(int l,int r,int s,int e,int v){
    if (s <= l && r <= e)
        return seg[v];
    if (l >= e || s >= r) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v] != 1){
        lz[u] = 1ll*lz[u]*lz[v]%mod;
        seg[u] = 1ll*lz[v]*seg[u]%mod;
        lz[u|1] = 1ll*lz[u|1]*lz[v]%mod;
        seg[u|1] = 1ll*seg[u|1]*lz[v]%mod;
        lz[v] = 1;
    }
    return mkay(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int qu;
    cin >> a[1] >> qu;
    n = 1;
    rep(i,0,qu){
        cin >> q[i].X >> q[i].Y.X;
        if (q[i].X == 1){
            cin >> q[i].Y.Y;
            n++;
            a[n] = q[i].Y.Y;
            q[i].Y.Y = n;  
            par[n] = q[i].Y.X;
            adj[n].pb(par[n]);
            adj[par[n]].pb(n);
        }
    }
    T = 1;
    rep(i,0,4*n+1) lz[i] = 1;
    dfs(1);
    vector<pll> ve;
    rep(i,1,n+1) ve.pb({tin[i],i});
    sort(ve.begin(),ve.end());
    rep(i,0,n) ind[ve[i].Y] = i;
    upd2(0,n,0,a[1],1);
    rep(i,0,qu){
        if (q[i].X == 2){
            int v = q[i].Y.X;
            int ans = que(0,n,ind[v],ind[v]+sz[v],1),tasir = 1ll*que(0,n,ind[v],ind[v]+1,1)*poww(a[v],mod-2)%mod;
            tasir = 1ll*tasir*poww(d[v]+1,mod-2)%mod;
            cout << 1ll*ans*poww(tasir,mod-2)%mod << endl;
            continue;
        }
        int v = q[i].Y.Y;
        int tasir = 1ll*que(0,n,ind[par[v]],ind[par[v]]+1,1)*poww(a[par[v]],mod-2)%mod;
   //     tasir = 1ll*tasir*(d[par[v]]+1)%mod;
        tasir = 1ll*tasir*a[v]%mod;
        upd2(0,n,ind[v],tasir,1);
        d[par[v]]++;
        int x = 1ll*poww(d[par[v]],mod-2)*(d[par[v]]+1)%mod;
        upd(0,n,ind[par[v]],ind[par[v]]+sz[par[v]],x,1);
    }
}