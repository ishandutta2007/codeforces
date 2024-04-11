#include <bits/stdc++.h>

using namespace std;
const int c=(1<<18), k=18;
int m, n, n2, t[c], len[k][c], kov[k][c], dp[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    n2=(1<<n);
    for (int i=1; i<=m; i++) {
        char c;
        cin >> c;
        if (c!='?') {
            t[i]=(c-'a'+1);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=m; j>=1; j--) {
            if (t[j]==0 || t[j]==i) {
                len[i][j]=len[i][j+1]+1;
            }
        }
    }
    int lo=0, hi=c, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        for (int i=1; i<=n; i++) {
            kov[i][m+1]=c;
            for (int j=m; j>=1; j--) {
                kov[i][j]=(len[i][j]>=mid ? j : kov[i][j+1]);
            }
        }
        dp[0]=1;
        for (int i=1; i<n2; i++) {
            dp[i]=c;
            for (int j=0; j<n; j++) {
                if (i & (1<<j) && dp[i-(1<<j)]<c) {
                    dp[i]=min(dp[i], kov[j+1][dp[i-(1<<j)]]+mid);
                }
            }
        }
        if (dp[n2-1]<c) {
            lo=mid;
        } else {
            hi=mid;
        }
    }
    cout << lo << "\n";
    return 0;
}
/*
5 1
?????
*/