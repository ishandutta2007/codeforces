#include <bits/stdc++.h>

using namespace std;
map<long long, long long> dp;
long long mod=1000000007;
long long n, m;
long long f;
long long ans(long long x)
{
    f++;
    if (dp.find(x)!=dp.end()) {
        return dp[x];
    }
    if (x<0) {
        dp[x]=0;
        return 0;
    }
    if (x<m) {
        dp[x]=1;
        return 1;
    }
    long long sum=0;
    long long y=(x+1)/2;
    for (long long i=0; i<m; i++) {
        long long p=ans(y-i);
        long long q=ans(x-y+i-m);
        sum+=p*q;
        sum%=mod;
    }
    long long p=ans(y);
    long long q=ans(x-y-1);
    sum+=p*q;
    sum%=mod;
    dp[x]=sum;
    return sum;
}
 main()
{
    cin >> n >> m;
    cout << ans(n) << endl;
    //cout << dp.size() << " " << f << endl;
    return 0;
}