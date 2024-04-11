#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e9+10,sq = 300;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
bool hide[N];
int sz[N];
vector<int> adj[N];
char ans[N];
void dfs(int v,int p){
    sz[v] = 1;
    for (auto &u : adj[v]){
        if (!hide[u] && p != u) dfs(u,v),sz[v] += sz[u];
    }
}
int cent(int v,int p,int _n){
    for(int u : adj[v]){
        if (!hide[u] && u != p && sz[u]*2 > _n) return cent(u,v,_n);
    }
    return v;
}
void decomp(int v,int num = 0){
    dfs(v,-1);
    v = cent(v,-1,sz[v]);
    ans[v] = char('A'+num);
    hide[v] = 1;
    for(int u : adj[v])
        if (!hide[u]) decomp(u,num+1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    decomp(1,0);
    rep(i,1,n+1) cout << ans[i] << ' ';
}