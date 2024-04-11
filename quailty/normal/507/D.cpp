#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int dp[1005][105][3];
int solve(int n,int k,int m)
{
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1,t=1;i<=n;i++,t=t*10%k)
        for(int j=0;j<k;j++)
            for(int p=0;p<3;p++)
                for(int q=0;q<10;q++)
                {
                    int tj=(j+t*q)%k,tp=max(p,(int)(q>0));
                    if(tp==1 && tj==0)tp=2;
                    dp[i][tj][tp]=(dp[i][tj][tp]+dp[i-1][j][p])%m;
                }
    int res=0;
    for(int j=0;j<k;j++)
        res=(res+dp[n][j][2])%m;
    return res;
}
int main()
{
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    printf("%d",(solve(n,k,m)-solve(n-1,k,m)+m)%m);
    return 0;
}