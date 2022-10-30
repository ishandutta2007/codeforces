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
const long long int N = 1e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int par[N][20],T,tin[N],h[N];
vector<int> adj[N];
pll seg[N*4][2];
void dfs(int v){
    tin[v] = T;
    T++;
    for (int u : adj[v]){
        h[u] = h[v]+1;
        dfs(u);
    }
}
inline int lca(int u,int v){
    if (h[u] < h[v]) swap(u,v);
    repr(i,19,0){
        if (h[u]-h[v] >= (1 << i))
            u = par[u][i];
    }
    if (u == v) return v;
    repr(i,19,0){
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v][0] = {tin[l],l};
        seg[v][1] = {tin[l],l};
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    build (l,m,u);
    build (m,r,u|1);
    seg[v][1] = max(seg[u][1],seg[u|1][1]);
    seg[v][0] = min(seg[u][0],seg[u|1][0]);
}
pll que(int l,int r,int s,int e,int v,bool f){
    if (s == e){
        if (f) return {-inf,0};
        return {inf,0};
    }
    if (s <= l && r <= e) return seg[v][f];
    if (s >= r || l >= e){
        if (f) return {-inf,-inf};
        return {inf,inf};
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (f) return max(que(l,m,s,e,u,f),que(m,r,s,e,u|1,f));
    return min(que(l,m,s,e,u,f),que(m,r,s,e,u|1,f));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(par,-1,sizeof par);
    int n,q;
    cin >> n >> q;
    rep(i,2,n+1){
        cin >> par[i][0];
        adj[par[i][0]].pb(i);
    }
    dfs(1);
    rep(j,1,20){
        rep(i,2,n+1){
            if (h[i] < (1 << j)) continue;
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    build(1,n+1,1);
    while (q--){
        int l,r;
        cin >> l >> r;
        r++;
        pll p1 = que(1,n+1,l,r,1,1),p2 = que(1,n+1,l,r,1,0);
        pll ans = {-1,0};
        pll v = max(que(1,n+1,l,p1.Y,1,1),que(1,n+1,p1.Y+1,r,1,1));
        int u = lca(v.Y,p2.Y);
        ans = {h[u],p1.Y};
        v = min(que(1,n+1,l,p2.Y,1,0),que(1,n+1,p2.Y+1,r,1,0));
        u = lca(v.Y,p1.Y);
        ans = max(ans,{h[u],p2.Y});
        cout << ans.Y << ' ' << ans.X << endl;
    }
}