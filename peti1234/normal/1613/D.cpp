#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long w, n, dp[c], spec[c], mod=998244353;
// dp[i] 0, 1, ... -1 volt
// spec[i] 0, 1, ... i-2 es i volt, i-1 nem
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        dp[0]=1;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            dp[x+1]=(2*dp[x+1]+dp[x])%mod;
            if (x) {
                spec[x]=(2*spec[x]+dp[x-1])%mod;
            }
            spec[x+2]=(2*spec[x+2])%mod;
        }
        long long sum=0;
        for (int i=0; i<=n+1; i++) {
            sum=(sum+spec[i]+dp[i])%mod;
        }
        cout << (sum+mod-1)%mod << "\n";


        for (int i=0; i<=n+3; i++) {
            dp[i]=0, spec[i]=0;
        }
    }
    return 0;
}
/*
1
2
0 0
*/