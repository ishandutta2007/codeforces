#include <bits/stdc++.h>

using namespace std;
long long h, v, n, x, y, mod=1000000007;
long long fakt[200002], inv[200002], dp[2003];
vector<pair<long long, long long> > p;
long long oszt(long long a) {
    long long p=mod-2, ans=1;
    while(p) {
        if (p%2) ans*=a, ans%=mod;
        a*=a, a%=mod, p/=2;
    }
    return ans;
}
long long alatt(long long a, long long b) {
    if (a<0 || a<b || b<0) return 0;
    return fakt[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> h >> v >> n, fakt[0]=1, inv[0]=1;
    for (long long i=1; i<=h+v; i++) fakt[i]=fakt[i-1]*i%mod, inv[i]=oszt(fakt[i]);
    for (long long i=1; i<=n; i++) {
        cin >> x >> y;
        p.push_back({x, y});
    }
    p.push_back({h, v});
    sort(p.begin(), p.end());
    for (long long i=0; i<=n; i++) {
        long long a=p[i].first, b=p[i].second;
        dp[i]=alatt(a+b-2, a-1);
        for (long long j=0; j<i; j++) {
            long long c=p[j].first, d=p[j].second;
            dp[i]-=alatt(a-c+b-d, a-c)*dp[j]%mod;
        }
        dp[i]+=mod*mod;
        dp[i]%=mod;
    }
    cout << dp[n];
    return 0;
}
// minden ll;