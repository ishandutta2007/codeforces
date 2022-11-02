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
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=5e5+20,mod = 1e9+7,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
int n,m,q;
vector<pair<int,pll>> e;
vector <pair<int,pll>> a[N];
int par[N];
bool ans[N];
vector<int> idx[N];
bool vis[N];
vector<int> adj[N];
int getpar(int v){
    if (par[v] == v) return v;
    return par[v] = getpar(par[v]);
}
inline void merge(int u,int v){
    if (getpar(u) == getpar(v)) return;
    par[par[u]] = par[v];
    return;
}
bool dfs(int v,int p){
    vis[v] = 1;
    bool f = 0;
    for (int u : adj[v]){ 
        if (u == p){
            if (f) return 0;
            f = 1;
            continue;
        }
        if (vis[u]) return 0;
        if (!dfs(u,v)) return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d", &n, &m);
    rep(i,1,n+1) par[i] = i;
    rep(i,0,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e.pb({w,{u,v}});
    }
    scanf("%d",&q);
    rep(i,0,q){
        ans[i] = 1;
        int k;
        scanf("%d",&k);
        rep(j,0,k){
            int ind;
            scanf("%d",&ind);
            a[i].pb(e[ind-1]);
        }
        sort(a[i].begin(),a[i].end());
        reverse(a[i].begin(),a[i].end());
        rep(j,0,k) if (!j || a[i][j].X != a[i][j-1].X) idx[a[i][j].X].pb(i);
    }
    sort(e.begin(),e.end());
    rep(i,0,m){
        int w = e[i].X;
        for (int j : idx[w]){
            vector <int> vert;
            while(!a[j].empty() && a[j].back().X == w){
                int u = a[j].back().Y.X,v = a[j].back().Y.Y;
                u = getpar(u);
                v = getpar(v);
                if (u == v) ans[j] = 0;
                vert.pb(v);
                vert.pb(u);
                adj[u].pb(v);
                adj[v].pb(u);
                a[j].pop_back();
            }
            for (int u : vert) if (!vis[u] && !dfs(u,-1)) ans[j] = 0;
            for (int u : vert){
                vis[u] = 0;
                adj[u].clear();
            }
        }
        while (i < m && e[i].X == w){
            merge(e[i].Y.Y,e[i].Y.X);
            i++;
        }
        i--;
    }
    rep(i,0,q){
        if (ans[i]) printf("%s\n","YES") ;
        else printf("%s\n","NO");
    }
    return 0;
}