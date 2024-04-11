#include <bits/stdc++.h>

using namespace std;



const int c=500005;
long long mod=1e9+7;



long long fakt[c], inv[c];
long long po(long long a, long long p) {
    long long ans=1;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans=ans*a%mod;
        }
        a=a*a%mod;
        p/=2;
    }
    return ans;
}

long long alatt(long long a, long long b) {
    if (a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}

void calc(int a) {
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=a; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
}

long long n, k, ans;
int main()
{
    cin >> n >> k;
    calc(n);
    k=min(n, k);
    for (int i=0; i<=k; i++) {
        ans=(ans+alatt(n, i))%mod;
    }
    cout << ans << "\n";
    return 0;
}