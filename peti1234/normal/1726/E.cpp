#include <bits/stdc++.h>

using namespace std;


/*
c meg mod erteket be kell allitani
calc n utan n-ig tud faktorialis, inverz es a alatt b-t szamolni
*/


const int c=500005;
long long mod=998244353;



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
long long alatt2(long long a, long long b) {
    if (a<b || b<0) return 0;
    long long ans=1;
    for (int i=1; i<=b; i++) {
        ans=ans*(a+1-i)%mod;
    }
    return ans*inv[b]%mod;
}
void calc(int a) {
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<=a; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
}

int w;
long long n, dp[300005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        calc(n);
        dp[0]=1, dp[1]=1;
        for (int i=2; i<=n; i++) {
            dp[i]=(dp[i-1]+(i-1)*dp[i-2])%mod;
        }
        long long ans=0, spec=1;
        for (int i=0; i<=n/4; i++) {
            ans=(ans+alatt(n-2*i, 2*i)*spec%mod*dp[n-4*i]%mod)%mod;
            spec=spec*2*(2*i+1)%mod;
        }
        cout << ans << "\n";
    }
    return 0;
}