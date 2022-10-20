#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    for (int z=0;z<q;z++){
        int n;
        scanf("%d", &n);
        int input[201];
        int dp[201][400];
        for (int i=0;i<201;i++){
            for (int j=0;j<400;j++) dp[i][j]=1000000000;
        }
        for (int i=0;i<n;i++) scanf("%d", &input[i]);
        sort(input, input+n);
        int x=n+n/2+1;
        for (int j=1;j<=x;j++) dp[0][j]=abs(input[0]-j);
        for (int i=1;i<n;i++){
            for (int j=1;j<=x;j++){
                for (int k=1;k<j;k++){
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+abs(input[i]-j));
                }
            }
        }
        /*for (int i=0;i<n;i++) printf("%d ", input[i]);
        printf("\n");
        for (int i=0;i<n;i++){
            for (int j=0;j<=x;j++) printf("%d ", dp[i][j]);
            printf("\n");
        }*/
        int ans=1000000000;
        for (int i=0;i<=x;i++) ans=min(ans, dp[n-1][i]);
        printf("%d\n", ans);
    }
    return 0;
}