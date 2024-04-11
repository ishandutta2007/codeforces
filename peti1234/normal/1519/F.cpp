#include <bits/stdc++.h>

using namespace std;
const int c=7, k=15625, sok=2e9;
int n, m, a[c], b[c], t[c][c];
int dp[5][k], po[c], ans=sok, sum;
int db(int mask, int a) {
    return (mask/po[a])%5;
}
int main()
{
    cin >> n >> m;
    po[1]=1;
    for (int i=2; i<=m; i++) {
        po[i]=po[i-1]*5;
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum+=a[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<k; j++) {
            dp[i][j]=sok;
        }
    }
    dp[0][0]=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int ert=0; ert<a[i]; ert++) {
                for (int mask=0; mask<k; mask++) {
                    int tov=min(b[j]-db(mask, j), a[i]-ert);
                    for (int add=1; add<=tov; add++) {
                        int o=ert+add, s=mask+add*po[j];
                        dp[o][s]=min(dp[o][s], dp[ert][mask]+t[i][j]);
                    }
                }
            }
        }
        for (int ert=1; ert<=a[i]; ert++) {
            for (int mask=0; mask<k; mask++) {
                dp[0][mask]=min(dp[0][mask], dp[ert][mask]);
                dp[ert][mask]=sok;
            }
        }
    }
    for (int mask=0; mask<k; mask++) {
        int cnt=0;
        for (int i=1; i<=m; i++) {
            cnt+=db(mask, i);
        }
        if (cnt>=sum) {
            ans=min(ans, dp[0][mask]);
        }
    }
    if (ans==sok) {
        ans=-1;
    }
    cout << ans << "\n";
    return 0;
}