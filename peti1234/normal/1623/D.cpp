#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7;
long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) ans=ans*a%mod;
        a=a*a%mod;
        p/=2;
    }
    return ans;
}
int main()
{
    int w;
    cin >> w;
    while (w--) {
        int n, m, c, d, e, f;
        long long ans=0, ert=1, prob;
        cin >> n >> m >> c >> d >> e >> f >> prob;
        prob=prob*oszt(100)%mod;
        int fc=c, fd=d, dc=1, dd=1;
        long long cnt=0;
        do {
            if (c==e || d==f) {
                ans=(ans+cnt*ert%mod*prob)%mod;
                ert=(ert*(mod+1-prob))%mod;
            }
            cnt++;
            if (c==1) dc=1;
            if (c==n) dc=-1;
            if (d==1) dd=1;
            if (d==m) dd=-1;
            c+=dc, d+=dd;
        } while (c!=fc || d!=fd || (c>1 && dc!=1) || (d>1 && dd!=1));


        ans=ans*oszt(mod+1-ert)%mod;
        cout << (ert*oszt(mod+1-ert)%mod*cnt%mod+ans)%mod << "\n";
    }
    return 0;
}