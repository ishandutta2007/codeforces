#include <bits/stdc++.h>

using namespace std;
long long n, x;
long long mini=0;
long long maxi=0;
long long ma=0;

long long com[300002];
long long t[300002];
long long tn[300002];
long long tk[300002];
long long dp[300001];
long long invdp[300002];
long long rn[300002];
long long rk[300002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (long long i=1; i<=n; i++) {
        long long a;
        cin >> a;
        t[i]=a;
        com[i]=com[i-1]+a;
        mini=min(mini, com[i]);
        maxi=max(maxi, com[i]);
        tn[i]=com[i]-mini;
        tk[i]=com[i]-maxi;
        if (x<=0) {
            dp[i]=max(tn[i], dp[i-1]+t[i]*x);
            //cout << dp[i] << endl;
        }
    }
    mini=0;
    maxi=0;
    for (long long i=n; i>=1; i--) {
        long long a=t[i];
        com[i]=com[i+1]+a;
        mini=min(mini, com[i]);
        maxi=max(maxi, com[i]);
        rn[i]=com[i]-mini;
        rk[i]=com[i]-maxi;
        if (x<=0) {
            invdp[i]=max(rn[i], invdp[i+1]+t[i]*x);
        }
    }
    maxi=0;
    for (long long i=1; i<=n; i++) {
        maxi=max(maxi, tn[i]);
    }
    maxi=max(maxi, maxi*x);
    if (x<=0) {
        for (long long i=0; i<=n; i++) {
            maxi=max(maxi, dp[i]+invdp[i+1]);
        }
    }
    cout << maxi << endl;
    return 0;
}