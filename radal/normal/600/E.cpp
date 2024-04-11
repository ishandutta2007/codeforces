#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
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
typedef pair<long double,long double> pld;
const long long int N = 1e5+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int n,m;
int c[N];
ll ans[N];
vector<int> adj[N];
map<int,int> st[N];
int mx[N];
ll sum[N];
void dfs(int v,int p){
    st[v][c[v]] = 1;
    mx[v] = 1;
    sum[v] = c[v];
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        if (st[v].size() < st[u].size()){
            swap(st[v],st[u]);
            swap(mx[u],mx[v]);
            swap(sum[u],sum[v]);
        }
        while (!st[u].empty()){
            auto y = *(st[u].begin());
            st[v][y.X] += y.Y;
            if (st[v][y.X] > mx[v]){
                mx[v] = st[v][y.X];
                sum[v] = y.X;
            }
            else if (st[v][y.X] == mx[v])
                sum[v] += y.X;
            st[u].erase(st[u].begin());
        }
    }
    ans[v] = sum[v];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,1,n+1) cin >> c[i];
    rep(i,0,n-1){
        int u,v;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1,-1);
    rep(i,1,n+1) cout << ans[i] << ' ';

}