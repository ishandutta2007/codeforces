#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int Mod=1000000007;
int c[MAXN][MAXN],dp[MAXN][MAXN][2];
void build()
{
    for(int i=0;i<MAXN;i++)
        for(int j=(c[i][0]=1);j<=i;j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
    dp[0][0][0]=dp[1][0][1]=1;
    for(int i=2;i<MAXN;i++)
        for(int j=0;j<=i-1-j;j++)
            for(int k=0;k<MAXN;k++)
                for(int l=0;l<=k;l++)
                {
                    int tmp=1LL*max(j,1)*max(i-1-j,1)*(j==i-1-j ? c[i-2][j-1] : c[i-1][j])%Mod;
                    dp[i][k][1]=(dp[i][k][1]+1LL*dp[j][l][0]*dp[i-1-j][k-l][0]%Mod*tmp)%Mod;
                    if(k<MAXN-1)
                    {
                        dp[i][k+1][0]=(dp[i][k+1][0]+1LL*dp[j][l][0]*dp[i-1-j][k-l][1]%Mod*tmp)%Mod;
                        dp[i][k+1][0]=(dp[i][k+1][0]+1LL*dp[j][l][1]*dp[i-1-j][k-l][0]%Mod*tmp)%Mod;
                        dp[i][k+1][0]=(dp[i][k+1][0]+1LL*dp[j][l][1]*dp[i-1-j][k-l][1]%Mod*tmp)%Mod;
                    }
                }
}
int main()
{
    build();
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",(dp[n][k][0]+dp[n][k][1])%Mod);
    return 0;
}