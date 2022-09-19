#include <bits/stdc++.h>

using namespace std;
const int c=100005;
long long fakt[c], inv[c], db[c];
long long w, n, k, mod=1000000007;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<b || a<0) {
        return 0;
    }
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    fakt[0]=1, inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }
    cin >> w;
    while (w--) {
        cin >> n >> k;
        long long sum=1, prob=1;
        db[0]=1;
        for (int i=1; i<=n; i++) {
            db[i]=alatt(n-(k-1)*(i-1), i)*fakt[i]%mod;
        }
        for (int i=1; i<=n; i++) {
            long long s=db[i-1]*(n-i+1)%mod;
            sum+=db[i]*prob%mod*oszt(s)%mod;
            sum%=mod;
            prob*=db[i], prob%=mod;
            prob*=oszt(s), prob%=mod;
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
1
99999 999
*/