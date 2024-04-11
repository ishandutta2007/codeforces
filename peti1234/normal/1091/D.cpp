#include <bits/stdc++.h>

using namespace std;
long long sum=1, n, fakt[1000002], mod=998244353;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
int main()
{
    cin >> n;
    fakt[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
    }
    for (long long i=1; i<=n; i++) {
        sum+=fakt[n]*oszt(fakt[n-i+1])%mod*(n-i)%mod*i;
        sum%=mod;
    }
    cout << sum << "\n";
    return 0;
}