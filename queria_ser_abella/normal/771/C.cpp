#include <bits/stdc++.h>
#define maxn 200200
#define pb push_back
#define debug
typedef long long ll;
using namespace std;

int n,k;
ll dp[5][maxn];
ll dp2[5][maxn];
int tot[maxn];
vector<int> L[maxn];

void dfs(int v,int p){
    tot[v] = 1;
    for(int i=0;i<L[v].size();i++){
        int to = L[v][i];
        if(to == p)
            continue;
        dfs(to,v);
        tot[v] += tot[to];
        for(int j=0;j<k;j++)
            dp[j][v] += dp[(j+1)%k][to];
        dp[k-1][v] += tot[to];
    }
}

void dfs2(int v,int p){
    if(v != p){
        for(int j=0;j<k;j++){
            dp2[j][v] = dp[j][v] + dp2[(j+1)%k][p] - dp[(j+2)%k][v];
        }
        dp2[k-1][v] += n-tot[v];
        if(k != 1)
            dp2[k-2][v] -= tot[v];
        else
            dp2[0][v] -= tot[v];
    }
    else
        for(int j=0;j<k;j++)
            dp2[j][v] = dp[j][v];
    for(int i=0;i<L[v].size();i++){
        int to = L[v][i];
        if(to == p)
            continue;
        dfs2(to,v);
    }
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=0,a,b;i<n-1;i++){
        scanf("%d%d",&a,&b), a--, b--;
        L[a].pb(b);
        L[b].pb(a);
    }
    dfs(0,0);
    dfs2(0,0);
    ll ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            debug("vx %d k %d -> %d %d\n",i,j,dp[j][i],dp2[j][i]);
    for(int i=0;i<n;i++)
        ans += dp2[k-1][i];
    printf("%lld\n",ans/2);
}