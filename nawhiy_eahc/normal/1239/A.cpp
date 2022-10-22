#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll dp[100002];

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=100000;i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
    }
    ll ans = dp[n] * 2 + dp[m] * 2 - 2;
    ans %= mod;

    printf("%lld", ans);
}