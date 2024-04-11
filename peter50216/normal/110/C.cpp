#include<stdio.h>
#include<string.h>
int dp[1000];
int main(){
    int n,i;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(i=1;i<1000;i++){
	if(i>=4&&dp[i-4]!=-1)dp[i]=dp[i-4]+1;
	if(i>=7&&dp[i-7]!=-1&&(dp[i]==-1||dp[i-7]<dp[i]))dp[i]=dp[i-7];
    }
    int r=0;
    int nn=n;
    while(n>=1000)n-=7;
    if(dp[n]==-1)puts("-1");
    else{
	r=(nn-dp[n]*4)/7;
	for(i=0;i<dp[n];i++)printf("4");
	for(i=0;i<r;i++)printf("7");
	puts("");
    }
}