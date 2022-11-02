#include<bits/stdc++.h>
using namespace std;
int n,r[20],b[20],dp[70000][300],col[70000][2],sumr,sumb,ans;
char c[20];
int main(){
    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        scanf("%c%d%d\n",&c[i],&r[i],&b[i]);
        sumr+=r[i];
        sumb+=b[i];
    }
    for (int i=0;i<(1<<n);i++)
    for (int j=0;j<n*n;j++) dp[i][j]=-1;
    dp[0][0]=0;
    for (int i=0;i<(1<<n);i++){
        for (int j=0;j<n;j++)
        if ((i|(1<<j))!=i){
            col[i|(1<<j)][0]=col[i][0];
            col[i|(1<<j)][1]=col[i][1];
            if (c[j]=='R') col[i|(1<<j)][0]++;
            else col[i|(1<<j)][1]++;
            int o=min(col[i][0],r[j]),p=min(col[i][1],b[j]);
            for (int k=0;k<n*n;k++)
            if (dp[i][k]!=-1){
                if (dp[i|(1<<j)][k+o]==-1) dp[i|(1<<j)][k+o]=dp[i][k]+p;
                else dp[i|(1<<j)][k+o]=max(dp[i|(1<<j)][k+o],dp[i][k]+p);
            }
        }
    }
    ans=-1;
    for (int i=0;i<n*n;i++)
    if (dp[(1<<n)-1][i]!=-1){
        if (ans==-1) ans=max(sumr-i,sumb-dp[(1<<n)-1][i]);
        else ans=min(ans,max(sumr-i,sumb-dp[(1<<n)-1][i]));
    }
    printf("%d\n",ans+n);
}