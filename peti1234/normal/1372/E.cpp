#include <bits/stdc++.h>

using namespace std;
const int c=102;
int kezd[c][c], veg[c][c], dp[c][c], n, m, sum;
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int db; cin >> db;
        for (int j=1; j<=db; j++) {
            int a, b; cin >> a >> b;
            for (int k=a; k<=b; k++) kezd[i][k]=a, veg[i][k]=b;
        }
    }
    for (int j=0; j<m; j++) for (int i=1; i+j<=m; i++) {
        int maxi=0;
        for (int k=i; k<=i+j; k++) {
            int cnt=0;
            for (int l=1; l<=n; l++) cnt+=(i<=kezd[l][k] && veg[l][k]<=i+j);
            maxi=max(maxi, cnt*cnt+dp[i][k-1]+dp[k+1][i+j]);
        }
        dp[i][i+j]=maxi;
    }
    cout << dp[1][m] << "\n";
    return 0;
}