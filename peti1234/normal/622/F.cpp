#include<bits/stdc++.h>

using namespace std;
long long n, k, ans, pre[1000005], fix, valt=1, mod=1e9+7;
long long po(long long a, long long b) {
    long long res=1;
    while (b) {
        if (b%2) res=res*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return res;
}
long long oszt(long long a) {
    return po(a, mod-2);
}

int main()
{
    cin >> n >> k;
    for (int i=1; i<=k+1; i++) {
        pre[i]=(pre[i-1]+po(i, k))%mod;
    }
    if (n<=k+1) {
        cout << pre[n] << "\n";
        return 0;
    }
    fix=n;
    for (int i=1; i<=k+1; i++) {
        fix=fix*(n-i)%mod;
        valt=valt*(mod-i)%mod;
    }

    for (int i=0; i<=k+1; i++) {
        ans+=pre[i]*fix%mod*oszt(n-i)%mod*oszt(valt)%mod;
        valt=valt*(i+1)%mod*oszt(mod+i-k-1)%mod;
    }

    cout << ans%mod << "\n";
    return 0;
}