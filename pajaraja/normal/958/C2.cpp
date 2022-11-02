#include <bits/stdc++.h>
using namespace std;
int dp[105][57], a[20007];
int main(){
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for(int i=0; i<n; ++i) scanf("%d", &a[i]);
    for(int i=0; i<p; ++i) for(int j=0; j<=k; ++j) dp[i][j]=-1;
    dp[0][0]=0;
    int sum=0;
    for(int t=0; t<n; ++t){
        sum+=a[t];
        sum%=p;
        for(int i=1; i<=k; ++i){
            if(i==k &&  t!=n-1) continue;
            for(int j=0; j<p; ++j){
                if(dp[j][i-1]!=-1 && dp[j][i-1]+(sum-j+p)%p>dp[sum][i]){
                    dp[sum][i]=dp[j][i-1]+(sum-j+p)%p;
                }
            }
        }
    }
    printf("%d", dp[sum][k]);
    return 0;
}