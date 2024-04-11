#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=5e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
pll seg[4*N];
int n,a[N];
vector<int> adj[N],ve;
int tin[N],t,ch[N];
void dfs(int v,int p){
    ve.pb(v);
    tin[v] = t;
    t++;
    for (int u : adj[v]) if (u != p) dfs(u,v);
    ch[v] = t-1;
}
void upd(int l,int r,int p,int v,int val){
    if (r-l == 1){
        seg[v].X = val;
        return;
    }
    int mid = (l+r)/2;
    if (p < mid)
        upd(l,mid,p,2*v,val);
    else
        upd(mid,r,p,2*v+1,val);
    seg[v].X = max(seg[2*v].X,seg[2*v+1].X);
}
void upd2(int l,int r,int s,int e,int val,int v){
    if (l == s && r == e){
        seg[v].Y = val;
        return;
    }
    int m = (l+r)/2;
    if (s >= m){
        upd2(m,r,s,e,val,2*v+1);
        return;
    }
    if (e <= m){
        upd2(l,m,s,e,val,2*v);
        return;
    }
    upd2(l,m,s,m,val,2*v);
    upd2(m,r,m,e,val,2*v+1);
}
int get(int l,int r,int s,int e,int v){
    int m = (l+r)/2;
    if (l == s && r == e) return seg[v].X;
    if (s >= m)
        return get(m,r,s,e,2*v+1);
    if (e <= m)
        return get(l,m,s,e,2*v);
    return max(get(l,m,s,m,2*v),get(m,r,m,e,2*v+1));
}
int get2(int l,int r,int v,int p){
    if (r-l == 1) return seg[v].Y;
    int m = (l+r)/2;
    if (p < m)
        return max(seg[v].Y,get2(l,m,2*v,p));
    return max(seg[v].Y,get2(m,r,2*v+1,p));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,-1);
    t = 1;
    int q;
    cin >> q;
    rep(i,0,q){
        int c,v;
        cin >> c >> v;
        if (c == 3){
            int mx = get(0,n,tin[v],ch[v]+1,1);
            int mx2 = get2(0,n,1,tin[v]);
            if (mx >= mx2) cout << 0;
            else cout << 1;
            cout << endl;
        }
        if (c == 2)
            upd(0,n,tin[v],1,i+1);
        if (c == 1)
            upd2(0,n,tin[v],ch[v]+1,i+1,1);
    }
    return 0;
}