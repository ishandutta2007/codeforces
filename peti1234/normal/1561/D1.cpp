#include <bits/stdc++.h>

using namespace std;
const int c=4000005;
long long n, mod, dp[c], mul[c], sum;
int main()
{
    cin >> n >> mod;
    dp[1]=1;
    for (int i=1; i<=n; i++) {
        mul[i]=(mul[i]+mul[i-1])%mod;
        dp[i]=(dp[i]+sum+mul[i])%mod;
        sum=(sum+dp[i])%mod;
        for (int j=2; i*j<=n; j++) {
            mul[i*j]=(mul[i*j]+dp[i])%mod;
            int s=(i+1)*j;
            if (s<=n) {
                mul[s]=(mul[s]+mod-dp[i]);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}