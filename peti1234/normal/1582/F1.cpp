#include <bits/stdc++.h>

using namespace std;
const int c=512;
int dp[100005][c], n, cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=1; i<c; i++) {
        dp[0][i]=c;
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=0; j<c; j++) {
            dp[i][j]=dp[i-1][j];
        }
        for (int j=0; j<c; j++) {
            if (dp[i-1][j]<x) {
                dp[i][j^x]=min(dp[i][j^x], x);
            }
        }
    }
    for (int i=0; i<c; i++) {
        if (dp[n][i]<c) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i=0; i<c; i++) {
        if (dp[n][i]<c) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}