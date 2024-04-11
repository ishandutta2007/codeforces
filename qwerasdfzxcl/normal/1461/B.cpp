#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char matrix[600][600];
int dp[600][600][2];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i=0;i<=n+1;i++){
            for (int j=0;j<=m+1;j++){
                for (int k=0;k<2;k++){
                    dp[i][j][k]=0;
                }
            }
        }
        for (int i=1;i<=n;i++) scanf("%s", matrix[i]+1);
        ll ans=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (matrix[i][j]=='*'){
                    //printf("%d %d\n", i, j);
                    dp[i][j][0]+=1;
                    ans++;
                }
            }
        }
        for (int k=1;k<=m/2+2;k++){
            for (int i=1;i<=n;i++){
                for (int j=1;j<=m;j++){
                    if (matrix[i][j]=='*'){
                        if (dp[i+1][j-1][0] && dp[i+1][j][0] && dp[i+1][j+1][0]){
                            dp[i][j][1]+=1;
                            ans++;
                        }
                    }
                }
            }
            for (int i=0;i<=n+1;i++){
                for (int j=0;j<=m+1;j++){
                    dp[i][j][0]=dp[i][j][1];
                    dp[i][j][1]=0;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}