#include <bits/stdc++.h>

using namespace std;
const long long c=300002;
long long n, t[c], kom[c], inv, mod=998244353;
long long h(long long n) {
    long long ans=1, p=mod-2;
    while(p) {
        if (p%2) ans*=n, ans%=mod;
        p/=2, n*=n, n%=mod;
    }
    return ans;
}
int main()
{
    cin >> n, inv=h(n);
    for (long long i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (long long i=1; i<=n; i++) kom[i]=kom[i-1]+t[i];
    for (long long i=1; i<n; i++) {
        long long db=n-i, sum=0, x=db%i;
        if (!x) x+=i;
        sum+=kom[x]*((db+i-1)/i), sum%=mod;
        for (long long j=(db-1)/i; j>0; j--) sum+=(kom[x+i]-kom[x])*j, x+=i, sum%=mod;
        cout << sum*inv%mod << "\n";
    }
    cout << 0 << "\n";
    return 0;
}