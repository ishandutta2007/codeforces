#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e3+20,mod = 1e9+7,inf = 1e9+10,lg = 18;
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

set<pll> st[N];
set<pll> adj[N/10][N];
int cnt[N/10][N];
int w[N];
int n,m,k;

void dfs(int v,int p){
    auto it = st[v].begin();
    auto it2 = st[v].rbegin();
    if ((it2->X)-(it->X) <= 2) return;

    int cnt = it2->X,cnt2 = it->X;
    int col = it2->Y,col2 = it->Y;
    st[v].erase(it);
    st[v].erase(st[v].find(*it2));
    cnt--;
    cnt2++;
    st[v].insert({cnt,col});
    st[v].insert({cnt2,col2});
    pll pa = (*adj[v][col].begin());
    adj[v][col].erase(pa);

    if (pa.X != p){
        int u = pa.X,i = pa.Y;
        st[u].erase({adj[u][col].size(),col});
        st[u].erase({adj[u][col2].size(),col2});
        adj[u][col].erase({v,i});
        adj[u][col2].insert({v,i});
        st[u].insert({adj[u][col].size(),col});
        st[u].insert({adj[u][col2].size(),col2});
        adj[v][col2].insert(pa);
        w[pa.Y] = col2;
        dfs(pa.X,v);
        return;
    }

    int j = pa.Y;
    pa = *(adj[v][col].begin());
    int u = pa.X,i = pa.Y;
    st[u].erase({adj[u][col].size(),col});
    st[u].erase({adj[u][col2].size(),col2});
    adj[v][col].erase(pa);
    adj[v][col].insert({p,j});
    adj[u][col].erase({v,i});
    adj[u][col2].insert({v,i});
    st[u].insert({adj[u][col].size(),col});
    st[u].insert({adj[u][col2].size(),col2});
    adj[v][col2].insert(pa);
    w[pa.Y] = col2;
    dfs(u,v);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    rep(i,1,n+1) rep(j,1,k+1) st[i].insert({0,j});
    rep(i,1,n+1){
        int w;
        cin >> w;
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        auto it = st[u].begin();
        int col = it->Y;
        w[i] = col;
        st[u].erase(it);
        st[v].erase({adj[v][col].size(),col});
        adj[u][col].insert({v,i});
        adj[v][col].insert({u,i});
        st[v].insert({adj[v][col].size(),col});
        st[u].insert({adj[u][col].size(),col});
        dfs(v,u);

    }

    rep(i,0,m) cout << w[i] << endl;
    return 0;
}