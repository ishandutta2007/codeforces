#include <bits/stdc++.h>

using namespace std;
const int c=100002, k=20;
int n, lg[c], t[c], maxi[c][k], pos[c][k];
long long sum, dp[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=2; i<=n; i++) lg[i]=lg[i/2]+1;
    for (int i=1; i<n; i++) {
        cin >> t[i];
        maxi[i][0]=t[i], pos[i][0]=i;
    }
    maxi[n][0]=n, pos[n][0]=n;
    for (int j=1; j<k; j++) {
        int s=(1<<j);
        for (int i=1; i+s<=n+1; i++) {
            int h=i+s/2;
            maxi[i][j]=maxi[i][j-1], pos[i][j]=pos[i][j-1];
            if (maxi[h][j-1]>maxi[i][j]) {
                maxi[i][j]=maxi[h][j-1], pos[i][j]=pos[h][j-1];
            }
        }
    }
    for (int i=n-1; i>=1; i--) {
        int ert=lg[t[i]-i], h=pos[i+1][ert], f=t[i]-(1<<(ert))+1;
        if (maxi[f][ert]>maxi[i+1][ert]) h=pos[f][ert];
        dp[i]=dp[h]+n-h+1+h-i-1-t[i]+h;
        sum+=dp[i];
    }
    cout << sum << "\n";
    return 0;
}
/*
10
2 10 8 7 8 8 10 9 10
*/