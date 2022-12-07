/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 5e3 + 1, mod = 1e9 + 7;

int n, m, k;

llint a[N], dp[N][N], sum[N];

void MAIN(){
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%lld", a + i);
        sum[i] = sum[i - 1] + a[i];
    }

    for(int i = m; i <= n; ++i){
        a[i - m + 1] = sum[i] - sum[i - m];
    }

    n -= m - 1;
    llint ans = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            if(i <= m) dp[i][j] = a[i];
            else{
                dp[i][j] = dp[i - m][j - 1] + a[i];
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    printf("%lld", ans);
}