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
bool hide[N],f[N];
int sz[N],d[N],a[N],n,k,ans[N],fen[N],h[N];
vector<int> adj[N];
inline void bfs(){
    queue<int> q;
    rep(i,1,n+1){
        if (f[i]){
            q.push(i);
            d[i] = 0;
        }
    }
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]){
            if (d[u] > d[v]+1){
                d[u] = d[v]+1;
                q.push(u);
            }
        }
    }
    return;
}
void siz(int v,int p){
    sz[v] = 1;
    for (int u : adj[v]){
        if (u != p && !hide[u]){
            siz(u,v);
            sz[v] += sz[u];
        }
    }
}
int cent(int v,int p,int _n){
    for (int u : adj[v]) if (!hide[u] && u != p && sz[u]*2 > _n) return cent(u,v,_n);
    return v;
}
inline void upd(int x,bool f,int r){
    for (; r <= n; r |= (r+1)){
        if (f) fen[r] = max(fen[r],x);
        else fen[r] = 0;
    }
}
inline int que(int l){
    int ans = 0;
    for (; l >= 0; l = (l&(l+1))-1)
        ans = max(ans,fen[l]);
    return ans;
}
void dfs2(int v,int p){
    ans[v] = max(ans[v],que(n-h[v]-1));
    for (int u : adj[v]){
        if (!hide[u] && u != p)
            dfs2(u,v);
    }
}
void dfs(int v,int p,bool f){
    int val = d[v]-h[v];
    if (val >= 0) upd(d[v],f,n-val);
    for (int u : adj[v]){
        if (hide[u] || u == p) continue;
        h[u] = h[v]+1;
        dfs(u,v,f);
    }
}
void decom(int v){
    siz(v,-1);
    v = cent(v,-1,sz[v]);
    h[v] = 0;
    dfs(v,-1,1);
    dfs2(v,-1);
    dfs(v,-1,0);
    hide[v] = 1;
    for (int u : adj[v])
        if (!hide[u])
            decom(u);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(d,63,sizeof d);
    cin >> n;
    rep(i,1,n){
        int u ,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k;
    rep(i,0,k){
        int x;
        cin >> x;
        f[x] = 1;
    }
    bfs();
    decom(1);
    rep(i,1,n+1) cout << ans[i] << ' ';
    return 0;
}