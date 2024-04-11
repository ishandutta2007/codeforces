#include <bits/stdc++.h>
 
using namespace std;
long long mod=1000000007, n, m, k, sum, f[501];
long long h(long long a, long long b)
{
    long long ans=1;
    while(b>0) {
        if (b%2) {
            ans*=a;
            ans%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return ans;
}
long long oszt(long long a)
{
    return h(a, mod-2);
}
long long alatt(long long a, long long b)
{
    long long x=f[a]*oszt(f[b])%mod;
    x*=oszt(f[a-b]);
    return x%mod;
}
long long val(long long a, long long b)
{
    long long x=(a+b)*n-a*b;
    long long y=n*n-x;
    long long z=alatt(n, a)*alatt(n, b);
    z%=mod;
    long long ans=h(k-1, x)*h(k, y);
    ans%=mod;
    ans*=z;
    ans%=mod;
    if ((a+b)%2) {
        ans*=-1;
        ans+=mod;
    }
    return ans;
}
int main()
{
    cin >> n >> k;
    f[0]=1;
    for (long long i=1; i<=n; i++) {
        f[i]=f[i-1]*i;
        f[i]%=mod;
    }
    for (long long i=0; i<=n; i++) {
        for (long long j=0; j<=n; j++) {
            sum+=val(i, j);
        }
    }
    sum%=mod;
    cout << sum << endl;
    return 0;
}