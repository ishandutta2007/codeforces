#include <bits/stdc++.h>

using namespace std;
const int c=52, k=100005;
int n, m, l[c], r[c], prdb[k], h[k];
long long ans, dp[c][k], pref[c][k], mod=998244353;
long long ert(int a, int b) {
    return (b<0 ? 0 : pref[a][b]);
}
long long solve(long long val) {
    dp[0][0]=1, pref[0][0]=1;
    for (int i=val; i<=m; i+=val) {
        pref[0][i]=1;
    }
    for (int i=1; i<=n; i++) {
        long long kis=l[i], nagy=r[i]-r[i]%val;
        if (kis%val) {
            kis+=val-kis%val;
        }
        //cout << "hatar " << i << " " << kis << " " << nagy << " " << val << "\n";
        if (kis>nagy) {
            return 0;
        }
        for (int j=0; j<=m; j+=val) {
            dp[i][j]=(ert(i-1, j-kis)-ert(i-1, j-nagy-val)+mod)%mod;
            if (val==3) {
                //cout << "ertek " << i << " " << j << " " << dp[i][j] << "\n";
            }
            pref[i][j]=(dp[i][j]+ert(i, j-val))%mod;
        }
    }
    long long res=0;
    for (int i=val; i<=m; i+=val) {
        res+=dp[n][i];
        res%=mod;
    }
    return res;
}
int main()
{
    for (long long i=2; i<k; i++) {
        if (!prdb[i]) {
            for (int j=i; j<k; j+=i) {
                prdb[j]++;
            }
            for (long long j=i*i; j<k; j+=i*i) {
                h[j]=1;
            }
        }
    }
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> l[i] >> r[i];
    }
    for (int i=1; i<=m; i++) {
        if (!h[i]) {
            long long add=solve(i);
            //cout << "fontos " << i << " " << add << "\n";
            if (prdb[i]%2) {
                ans=(ans+mod-add)%mod;
            } else {
                ans=(ans+add)%mod;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
2 5
1 3
1 3
*/