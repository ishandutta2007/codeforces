#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 1e5 + 5;
int f[maxn][20];
int main(){
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m; 
    #define P pair<int,int>
    vector<int> fa(n+1);fors(i,1,n+1) fa[i] = i;
    function<int(int)> fnd = [&](int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);};
    vector<vector<int> > g(n+1);
    vector<P> e;
    fors(i,0,m){
        int u, v; cin>>u>>v;
        if(fnd(u) == fnd(v)) e.pb(P(u,v));
        else fa[fnd(u)] = fnd(v), g[u].pb(v), g[v].pb(u);
    }
    vector<int> dep(n+1);
    function<void(int,int)> dfs = [&](int u, int pa){
        f[u][0] = pa; fors(i,1,20) f[u][i] = f[f[u][i-1]][i-1]; dep[u] = dep[pa]+1;
        for(int v:g[u]) if(v^pa) dfs(v, u);
    }; dfs(1, 0);
    auto lca = [&](int x, int y){
        if(dep[x]<dep[y]) swap(x, y);
        int d = dep[x]-dep[y];
        fors(i,0,20) if(d>>i&1) x = f[x][i];
        if(x == y) return x;
        for(int i = 19; i >= 0; --i) if(f[x][i]^f[y][i]) tie(x,y) = P(f[x][i],f[y][i]);
        return f[x][0];
    };
    vector<int> sz(n+1), ex(n+1);
    int tot = 0;
    for(auto [x,y]:e){
        int p = lca(x, y);
        if(dep[x] < dep[y]) swap(x, y);
        if(x == y) assert(0);
        else{
            if(p == y){
                tot++;
                int t = x;
                for(int i = 19; i >= 0; --i) if(dep[f[t][i]]  > dep[y]) t = f[t][i];
                sz[t]--;
                sz[x]++;
            }else{
                sz[x]++; sz[y]++;
            }
        }
    }
    function<void(int)> go = [&](int u){
        sz[u] += sz[f[u][0]]; for(int v:g[u]) if(v^f[u][0]) go(v);
    }; go(1);
    
    fors(i,1,n+1){
        // cout<<"i:"<<i<<" sz:"<<sz[i]<<" ex:"<<ex[i]<<endl;
        if(sz[i]+ex[i]+tot == e.size()) cout<<1;
        else cout<<0;
    }cout<<endl;
    return 0;
}
/*
5 5
1 2
3 5
1 3
1 2
4 2
*/