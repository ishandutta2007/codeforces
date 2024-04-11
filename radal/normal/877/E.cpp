#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
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
const long long int N = 2e5+20,mod = 1e9+7,inf=1e9,maxm = 1e6+1;
vector<int> adj[N];
int child[N],par[N],T,tin[N],t[N],seg[N*4],lz[4*N],ve[N];
void dfs(int v){
    child[v] = 1;
    tin[v] = T;
    ve[T] = v;
    T++;
    for (int u : adj[v]){
        dfs(u);
        child[v] += child[u];
    }
}
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v] = t[ve[l]];
        return;
    }
    int m = (l+r)/2,u = 2*v;
    build(l,m,u);
    build(m,r,u+1);
    seg[v] = seg[u]+seg[u+1];
}
int que(int l,int r,int s,int e,int v){
    if (l >= s && e >= r)
        return seg[v];
    if (s >= r || l >= e) 
        return 0;
    int m = (l+r)/2,u = 2*v;
    if (lz[v]){
        seg[u] = m-l-seg[u];
        seg[u+1] = r-m-seg[u+1];
        lz[u] = 1-lz[u];
        lz[u+1] = 1-lz[u+1];
        lz[v] = 0;
    }
    return que(l,m,s,e,u)+que(m,r,s,e,u+1);
}
void upd(int l,int r,int s,int e,int v){
    if (l >= s && e >= r){
        seg[v] = r-l-seg[v];
        lz[v] = 1-lz[v];
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r)/2,u = 2*v;
    if (lz[v]){
        seg[u] = m-l-seg[u];
        seg[u+1] = r-m-seg[u+1];
        lz[u] = 1-lz[u];
        lz[u+1] = 1-lz[u+1];
        lz[v] = 0;
    }
    upd(l,m,s,e,u);
    upd(m,r,s,e,u+1);
    seg[v] = seg[u]+seg[u+1];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,2,n+1){
        cin >> par[i];
        adj[par[i]].pb(i);
    }
    dfs(1);
    rep(i,1,n+1)
        cin >> t[i];
    build(0,n,1);
    int q;
    cin >> q;
    while(q--){
        string s;
        int x;
        cin >> s >> x;
        if (s == "get"){
            cout << que(0,n,tin[x],tin[x]+child[x],1) << endl;
            continue;
        }
        upd(0,n,tin[x],tin[x]+child[x],1);
    }
    return 0;
}