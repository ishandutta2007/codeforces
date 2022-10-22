#include <iostream>
#define Mod 998244353
using namespace std;
long long dp[200001];
long long dp2[200001];

int main()
{
    dp[1] = 1;
    dp[2] = 1;
    dp2[1] = 499122177;
    int n;
    scanf("%d", &n);
    int cnt=0;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= Mod;
    }
    for(int i=2;i<=n;i++){
        dp2[i] = dp2[i-1] * dp2[1];
        dp2[i] %= Mod;
    }

    long long result = dp[n]*dp2[n];
    result %= Mod;
    printf("%lld", result);
}