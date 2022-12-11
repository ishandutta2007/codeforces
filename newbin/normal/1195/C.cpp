#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 50;
int n;
ll a[maxn], b[maxn];
ll dp[maxn][3];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%I64d", &a[i]);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%I64d", &b[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][0] = max(dp[i][0], dp[i-1][2]);
        ans = max(ans, dp[i][0]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
        ans = max(ans, dp[i][1]);
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + a[i];
        ans = max(ans, dp[i][2]);
    }
    cout<<ans<<endl;
}