#include <bits/stdc++.h>

using namespace std;
long long n, k, fakt[200002], dp[200002], mod=998244353, sum, p;
long long hat(long long a, long long b) {
    long long ans=1;
    while(b) {
        if (b%2) ans*=a, ans%=mod;
        a*=a, a%=mod;
        b/=2;
    }
    return ans;
}
long long oszt(long long x) {
    return hat(x, mod-2);
}
long long alatt(long long a, long long b) {
    return fakt[a]*oszt(fakt[b])%mod*oszt(fakt[a-b])%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k, fakt[0]=1;
    for (long long i=1; i<=n; i++) fakt[i]=fakt[i-1]*i%mod;
    if (k>=n) cout << 0 << "\n";
    else if (k==0) cout << fakt[n] << "\n";
    else {
        for (long long i=1; i<=n-k; i++) {
            p=alatt(n-k, i)*hat(i, n)%mod;
            if ((n-k-i)%2) sum-=p;
            else sum+=p;
            sum+=mod, sum%=mod;
        }
        cout << 2*alatt(n, n-k)%mod*(sum)%mod;
    }
    return 0;
}
// minden ll;