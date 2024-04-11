#include <bits/stdc++.h>
#define int long long
#define ll long long

using namespace std;
const int MOD = 998244353;
pair<int, int> query[505];
ll dp[505][505][2];
int n;

bool cmp(int x, int y){
    if (query[x].second==query[y].second) return (x<y);
    return query[x].second<query[y].second;
}

ll solve(int x){
    dp[0][0][0] = 1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=n;j++) dp[i][j][0] = dp[i-1][j][0], dp[i][j][1] = dp[i-1][j][1];
        if (i==x){
            for (int j=0;j<=n;j++) dp[i][j][1] = dp[i-1][j][0];
            continue;
        }
        if (query[i].first==-1){
            dp[i][0][0] += dp[i-1][0][0]+dp[i-1][0][1];
            for (int j=1;j<=n;j++) dp[i][j-1][0] += dp[i-1][j][0], dp[i][j-1][1] += dp[i-1][j][1];
        }
        else if (cmp(i, x)){
            for (int j=1;j<=n;j++) dp[i][j][0] += dp[i-1][j-1][0], dp[i][j][1] += dp[i-1][j-1][1];
        }
        else{
            for (int j=0;j<=n;j++) dp[i][j][0] *= 2, dp[i][j][1] *= 2;
        }

        for (int j=0;j<=n;j++) dp[i][j][0] %= MOD, dp[i][j][1] %= MOD;
    }
    ll ret = 0;
    for (int j=0;j<=n;j++) ret = (ret+dp[n][j][1])%MOD;
    return (ret*query[x].second)%MOD;
}

signed main(){
    scanf("%lld", &n);
    for (int i=1;i<=n;i++){
        char tmp;
        int x;
        scanf(" %c", &tmp);
        if (tmp=='-') query[i] = {-1, 0};
        else{
            scanf("%lld", &x);
            query[i] = {1, x};
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) if (query[i].first==1) ans = (ans+solve(i))%MOD;
    printf("%lld\n", ans);
    return 0;
}