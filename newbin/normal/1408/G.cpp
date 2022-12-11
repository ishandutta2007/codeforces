#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 1505;
const int mod = 998244353;
int n;
int w[maxn][maxn];
int x[maxn*maxn], y[maxn*maxn];
int fa[maxn*2], sz[maxn*2], num[maxn*2], key[maxn*2];
int fnd(int x){if(x == fa[x]) return x; return fa[x] = fnd(fa[x]);}
int tot;
vector<int> g[maxn*2];
int dp[maxn*2][maxn];//
void dfs(int u){
    if(key[u]) dp[u][1] = 1;
    if(g[u].size() == 0) return;
    assert(g[u].size() == 2);
    int lc = g[u][0]; int rc = g[u][1];
    dfs(lc); dfs(rc);
    for(int i = 1; i <= sz[lc]; ++i){
        for(int j = 1; j <= sz[rc]; ++j){
            dp[u][i+j] = (dp[u][i+j] + (ll)dp[lc][i]*dp[rc][j]%mod)%mod;
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    fors(i,1,n+1){
        fors(j,1,n+1){
            scanf("%d", &w[i][j]);
            if(j > i) x[w[i][j]] = i, y[w[i][j]] = j;
        }
    }
    int m = (n-1)*n/2;
    tot = n;
    fors(i,1,n+1) fa[i] = i, sz[i] = 1, num[i] = 0, key[i] = 1;

    fors(i,1,m+1){
        int u = x[i], v = y[i];
        u = fnd(u); v = fnd(v);
        if(u == v){
            num[u]++;
            if(sz[u]*(sz[u]-1) == 2*num[u]) key[u] = 1;
        }else{
            ++tot;
            fa[u] = fa[v] = tot;
            g[tot].pb(u); g[tot].pb(v);
            fa[tot] = tot;
            sz[tot] = sz[u] + sz[v];
            num[tot] = num[u] + num[v]+1;
            if(sz[tot]*(sz[tot]-1) == num[tot]*2) key[tot] = 1;

        }
    }
    dfs(tot);
    fors(i,1,n+1){
        printf("%d", dp[tot][i]);
        if(i == n) printf("\n"); else printf(" ");
    }
}