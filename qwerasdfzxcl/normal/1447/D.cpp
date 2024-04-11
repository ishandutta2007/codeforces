#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char a[5002], b[5002];
int dp[5002][5002];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", a);
    scanf("%s", b);
    int ans=-1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dp[i][j]=max(max(dp[i][j], dp[i-1][j]-1), dp[i][j-1]-1);
            if (a[i-1]==b[j-1]) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+2);
            ans=max(ans, dp[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}