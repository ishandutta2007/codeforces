#include<bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(int i = a; i < b; ++i)
#define mid ((r+l)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1,mid+1,r
#define pb push_back
#define lowbit(x) (x&(-x))
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 2005;
int n, mod;
vector<int> e[maxn], g[maxn];
ll dp[maxn][maxn], f[maxn][maxn];
void dfs(int u){
    for(int v:g[u]) dfs(v);
    for(int i = 1; i < n; ++i){
        ll res = 1;
        for(int v:g[u]) res = res*f[v][i]%mod; 
        dp[u][i] = (dp[u][i]+res)%mod;
    }
    int len = g[u].size();
    if(len == 0){
        for(int i = 1; i < n; ++i) f[u][i] = (dp[u][i]+f[u][i-1])%mod; return;
    }
    vector<ll> val(len);
    for(int x = 2; x < n; ++x){
        vector<ll> p(len), s(len);
        p[0] = f[g[u][0]][x-1];
        for(int i = 1; i < len; ++i) p[i] = f[g[u][i]][x-1]*p[i-1]%mod;
        s[len-1] = f[g[u][len-1]][x-1];
        for(int i = len-2; i >= 0; --i) s[i] = f[g[u][i]][x-1]*s[i+1]%mod;
        for(int i = 0; i < len; ++i){
            ll res = 1;
            if(i) res = res*p[i-1]%mod;
            if(i+1<len) res = res*s[i+1]%mod;
            val[i] = (val[i]+res)%mod;
        }
        for(int i = 0; i < len; ++i){
            int v = g[u][i];
            dp[u][x] = (dp[u][x] + val[i]*dp[v][x])%mod;
        }
    }
    for(int i = 1; i < n; ++i) f[u][i] = (dp[u][i]+f[u][i-1])%mod;
}
int C[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>mod;
    C[0][0] = 1;
    fors(i,1,n+1){
        C[i][0] = 1;
        fors(j,1,i+1) C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
    }
    fors(i,1,n){
        int u, v; cin>>u>>v;
        e[u].pb(v); e[v].pb(u);
    }
    function<void(int,int)> go = [&](int u, int f){
        for(int v:e[u]) if(v^f) g[u].pb(v), go(v, u);
    }; go(1, 0);
    dfs(1);
    vector<ll> a(n+1);
    for(int k = 1; k < n; ++k){
        ll ans = 1; for(int v:g[1]) (ans *= f[v][k])%=mod;
        a[k] = ans;
    }
    vector<ll> ans(n+1);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            int f = 1; if((i-j)&1) f = -1;
            ans[i] += (ll)f*a[j]%mod*C[i][j]%mod;
            ans[i] %= mod;
        }
        ans[i] = (ans[i]+mod)%mod;
    }
    fors(i,1,n) cout<<ans[i]<<" ";
    return 0;
}