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
const long long int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,maxm= (1 << 21);
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
        k >>= 1;
    }
    return z;
}
string s;
vector<int> adj[N];
int cnt[maxm],h[N],sz[N];
ll ans[N],sum[N],k;
bool hide[N];
int n;
void siz(int v,int p){
    sz[v] = 1;
    for (int u : adj[v]){
        if (!hide[u] && u != p){
            siz(u,v);
            sz[v] += sz[u];
        }
    }
}
int cent(int v,int p,int _n){
    for(int u : adj[v]) if (u != p && !hide[u] && sz[u]*2 > _n) return cent(u,v,_n);
    return v;
}
void calc(int v,int p,int b,int x){
    h[v] ^= (1 << (s[v-1] - 'a'));
    int y = (b^h[v]);
    cnt[y] += x;
    rep(i,0,20){
        cnt[((1 << i)^y)] += x;
    }
    for (int u : adj[v]){
        if (u == p || hide[u]) continue;
        h[u] = h[v];
        calc(u,v,b,x);
    }
}
void dfs(int v,int p,int x){
    sum[v] += cnt[h[v]];
    k += cnt[h[v]];
    for (int u : adj[v]){
        if (u != p && !hide[u]){
            dfs(u,v,x);
            sum[v] += sum[u];
        }
    }
    ans[v] += sum[v]*x;
}
void rst(int v,int p){
    cnt[h[v]] = 0;
    h[v] = 0;
    sum[v] = 0;
    for (int u : adj[v]){
        if (!hide[u] && u != p)
            rst(u,v);
    }
}
void decom(int v){
    siz(v,-1);
    v = cent(v,-1,sz[v]);
    h[v] = 0;
    calc(v,-1,(1 << (s[v-1] - 'a')),1);
    dfs(v,-1,1);
    h[v] = 0;
    calc(v,-1,(1 << (s[v-1]-'a')),-1);
    k = 0;
    hide[v] = 1;
    for (int u : adj[v]){
        if (hide[u]) continue;
        rst(u,-1);
        h[u] = h[v];
        calc(u,v,h[v],1);
        dfs(u,v,-1);
        h[u] = h[v];
        calc(u,v,h[v],-1);
    }
    ans[v] -= k/2;
    ans[v] -= sum[v];
    sum[v]++;
    ans[v] += (sum[v] >> 1);
    rst(v,-1);
    for (int u : adj[v]){
        if (!hide[u])
            decom(u);
    }
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
    cin >> s;
    decom(1);
    rep(i,1,n+1) cout << ans[i] << ' ';
    return 0;
}