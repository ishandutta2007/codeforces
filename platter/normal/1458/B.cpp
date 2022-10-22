#include <bits/stdc++.h>
using namespace std;

int dp[101][10001][101];
int a[101];
int b[101];
int ret[101];

int main(void) {
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++) {
        scanf("%d %d",&a[i],&b[i]);
        sum+=b[i];
    }
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=sum;j++) {
            for(int k=0;k<=n;k++) {
                dp[i][j][k]=-1e9;
            }
        }
    }
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int k=0;k<=n;k++) {
            for(int j=0;j<=sum;j++) {
                dp[i][j][k]=dp[i-1][j][k];
                if (k&&j>=b[i]) {
                    dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-b[i]][k-1]+a[i]*2);
                }
                ret[k]=max(ret[k],min(j+sum,dp[i][j][k]));
            }
        }
    }
    for(int i=1;i<=n;i++) {
        printf("%d.%d ",ret[i]/2,(ret[i]%2)*5);
    }
}