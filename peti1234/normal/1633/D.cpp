#include <bits/stdc++.h>

using namespace std;
const int c=1005, p=1e7;
int dp[c][c], w, n, k, dp2[c][15*c], db[c];
int main()
{
    for (int i=1000; i>=1; i--) {
        set<int> s;
        for (int j=1; j<=i; j++) {
            s.insert(i/j);
        }
        for (int j=1; j<=1000; j++) {
            if (i>j) dp[i][j]=p;
            if (i<j) {
                dp[i][j]=p;
                for (auto x:s) {
                    if (i+x<=j) {
                        dp[i][j]=min(dp[i][j], dp[i+x][j]+1);
                    }
                }
            }
        }
    }

    cin >> w;
    while (w--) {
        cin >> n >> k;
        k=min(k, 12*n);
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            db[i]=dp[1][x];
        }
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            for (int j=0; j<=k; j++) {
                dp2[i][j]=dp2[i-1][j];
                if (j>=db[i]) {
                    dp2[i][j]=max(dp2[i][j], dp2[i-1][j-db[i]]+x);
                }
            }
        }
        cout << dp2[n][k] << "\n";

        for (int i=0; i<=n; i++) {
            for (int j=0; j<=k; j++) {
                dp2[i][j]=0;
            }
            db[i]=0;
        }
    }
    return 0;
}