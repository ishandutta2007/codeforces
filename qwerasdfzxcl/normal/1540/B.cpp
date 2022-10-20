#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
vector<int> adj[202];
ll comb[202][202];
ll dp[202][202], ans = 0;
int dep[202], par[202];
int sz[202], n;

void dfs(int s, int pa = -1){
    if (pa!=-1) dep[s] = dep[pa]+1;
    par[s] = pa;
    sz[s] = 1;
    for (auto &v:adj[s]) if (v!=pa){
        dfs(v, s);
        sz[s] += sz[v];
    }
}

void query(int x, int y){
    int lca = -1, len = 0;
    int X = x, Y = y;
    while(dep[X]!=dep[Y]){
        if (dep[x]>dep[y]) X = par[X];
        else Y = par[Y];
        len++;
    }
    while(X!=Y){
        X = par[X], Y = par[Y];
        len += 2;
    }
    lca = X;
    int pt = 0;
    for (int i=dep[x]-1;i>dep[lca];i--){
        pt++;
        ans += dp[len][pt] * (sz[par[x]]-sz[x]);
        ans %= MOD;
        x = par[x];
    }

    if (y!=lca){
        ans += dp[len][len] * (sz[y]);
        ans %= MOD;
    }
    int pt2 = len;
    for (int i=dep[y]-1;i>dep[lca];i--){
        pt2--;
        ans += dp[len][pt2] * (sz[par[y]]-sz[y]);
        ans %= MOD;
        y = par[y];

    }

    pt++;
    if (y==lca){
        ans += dp[len][len] * (n-sz[x]);
        ans %= MOD;
    }
    else if (x!=lca && y!=lca){
        ans += dp[len][pt] * (n-sz[x]-sz[y]);
        ans %= MOD;
    }
}

ll pw(ll a, ll e){
    if (!e) return 1;
    ll ret = pw(a, e/2);
    if (e&1) return ret*ret%MOD*a%MOD;
    return ret*ret%MOD;
}

ll inv(ll x){
    return pw(x, MOD-2);
}

int main(){
    comb[0][0] = 1;
    for (int i=1;i<202;i++){
        comb[i][0] = comb[i][i] = 1;
        for (int j=1;j<i;j++) comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%MOD;
    }
    scanf("%d", &n);
    for (int i=0;i<n-1;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int i=1;i<=n;i++){
        dp[i][0] = 0, dp[i][i] = 1;
        for (int j=1;j<i;j++){
            ll prv = 0;
            for (int k=i-j;k<i;k++){
                dp[i][j] += comb[k][k-i+j] * inv(pw(2, k));
                dp[i][j] -= prv*inv(pw(2, k));
                dp[i][j] %= MOD;
                if (dp[i][j]<0) dp[i][j] += MOD;

                prv = comb[k][k-i+j];
            }
        }
    }
    /*for (int i=1;i<=n;i++){
        for (int j=0;j<=i;j++) printf("%lld ", dp[i][j]);
        printf("\n");
    }*/
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            //printf("%d %d: ", i, j);
            query(i, j);
            //printf("%lld\n", ans);
        }
    }
    ans *= inv(n);
    ans %= MOD;
    printf("%lld\n", ans);
    return 0;
}