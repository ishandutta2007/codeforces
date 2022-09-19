#include<bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, k, fakt[c], inv[c], s[c], mu[c], ans, mod=998244353;

long long po(long long a, long long b) {
    long long ans=1;
    while (b) {
        if (b%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
long long calc(long long a) {
    long long ans=0, m=min(a, k);
    for (int i=1; i<=m; i++) {
        ans=(ans+po(i, a)*inv[i]%mod*s[m-i]%mod)%mod;
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    if (k==1) {
        cout << 1 << "\n";
        return 0;
    }
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=n; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=po(fakt[i], mod-2);
    }
    s[0]=1;
    for (int i=1; i<=k; i++) {
        long long p=(i%2 ? mod-inv[i] : inv[i]);
        s[i]=(s[i-1]+p)%mod;
    }
    mu[1]=1;
    for (int i=1; i<=n; i++) {
        for (long long j=i; j<n; j+=i) {
            mu[min(n, i+j)]-=mu[i];
        }
    }
    for (int i=1; i<=n; i++) {
        ans=(ans+calc((n+i-1)/i)*mu[i]+mod)%mod;
    }
    cout << ans << "\n";
	return 0;
}