#include <bits/stdc++.h>

using namespace std;
const int c=200002, s=2005;
int ss, oo, n, k;
long long mod=1e9+7, fakt[c], inv[c], dp[s][21], utdb[s][s], ans;
pair<int, int> t[s];

long long oszt(long long a) {
    long long ans=1, p=mod-2;
    while (p) {
        if (p%2) {
            ans*=a, ans%=mod;
        }
        a*=a, a%=mod;
        p/=2;
    }
    return ans;
}
long long ut(int a, int b) {
    int sa=t[a].first, oa=t[a].second, sb=t[b].first, ob=t[b].second;
    if (sa>sb || oa>ob) {
        return 0;
    }
    int x=sb-sa, y=ob-oa;
    return fakt[x+y]*inv[x]%mod*inv[y]%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);

    fakt[0]=1, inv[0]=1;
    for (int i=1; i<c; i++) {
        fakt[i]=fakt[i-1]*i%mod;
        inv[i]=oszt(fakt[i]);
    }

    cin >> ss >> oo >> n >> k;
    t[0]={1, 1}, t[n+1]={ss, oo};
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        t[i]={a, b};
    }
    n++;
    sort(t+1, t+n+1);
    for (int i=0; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            utdb[i][j]=ut(i, j);
        }
    }
    for (int j=0; j<20; j++) {
        for (int i=n-1; i>=0; i--) {
            dp[i][j]=utdb[i][n];
            for (int k=i+1; k<n; k++) {
                dp[i][j]-=utdb[i][k]*dp[k][j];
                dp[i][j]%=mod;
            }
            for (int k=0; k<j; k++) {
                dp[i][j]-=dp[i][k];
                dp[i][j]%=mod;
            }
            if (dp[i][j]<0) {
                dp[i][j]+=mod;
            }
        }
    }
    long long p=utdb[0][n];
    for (int k=0; k<20; k++) {
        p-=dp[0][k];
        p%=mod;
    }
    if (p<0) {
        p+=mod;
    }
    dp[0][20]=p;
    for (int i=0; i<=20; i++) {
        ans+=k*dp[0][i];
        ans%=mod;
        //cout << i << " " << dp[0][i] << "\n";
        k-=k/2;
    }
    ans*=oszt(utdb[0][n]);
    cout << ans%mod << "\n";
    return 0;
}