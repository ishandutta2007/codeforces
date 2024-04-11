#include <bits/stdc++.h>

using namespace std;
const int c=5025;
int n, k, f[c], p[c], dp[c][1<<9], inv;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> f[i];
        p[f[i]]=i;
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+k+1; j<=n; j++) {
            if (p[i]>p[j]) {
                inv++;
            }
        }
    }
    for (int i=0; i<=n; i++) {
        for (int j=0; j<(1<<(k+1)); j++) {
            dp[i][j]=c*c;
        }
    }
    dp[0][0]=0;
    for (int i=0; i<n; i++) {
        for (int mask=0; mask<(1<<k+1); mask++) {
            int ert=dp[i][mask];
            if (mask%2) {
                dp[i+1][mask/2]=min(dp[i+1][mask/2], ert);
            } else {
                for (int j=0; j<=k; j++) {
                    if (mask & (1<<j)) continue;
                    int kov=mask+(1<<j), db=0;
                    for (int s=max(1, i+j+1-k); s<=i; s++) {
                        if (p[i+j+1]<p[s]) {
                            db++;
                        }
                    }
                    for (int s=0; s<=k; s++) {
                        if ((mask & (1<<s)) && p[i+1+j]<p[i+1+s]) {
                            db++;
                        }
                    }
                    dp[i][kov]=min(dp[i][kov], ert+db);
                }
            }
        }
    }
    cout << inv+dp[n][0] << "\n";
    return 0;
}