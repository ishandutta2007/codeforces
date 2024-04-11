#include<stdio.h>
int t[5000],d[5000];
long long dp[5000][5000];
int n,k;

int main(){
    int i,j,q,w;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d%d",&t[i],&d[i]);
    t[n+1]=86401;d[n+1]=1;
    int ans=0;
    for(i=0;i<=k;i++)dp[0][i]=1;
    for(i=1;i<=n+1;i++){
        for(j=0;j<=k;j++){
            if(t[i]>=dp[i-1][j]){
                if(ans<t[i]-dp[i-1][j])ans=t[i]-dp[i-1][j];
                dp[i][j]=t[i]+d[i];
            }else{
                dp[i][j]=dp[i-1][j]+d[i];
            }
            if(j>0){
                if(dp[i][j]>dp[i-1][j-1])dp[i][j]=dp[i-1][j-1];
            }
        }
    }
    printf("%d\n",ans);
}