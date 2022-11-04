#include<bits/stdc++.h>
using namespace std;
const int MAXN=55;
const int Mod=1000000007;
int c[MAXN],pw[MAXN*MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int main()
{
    for(int i=(pw[0]=1);i<MAXN*MAXN;i++)
        pw[i]=2*pw[i-1]%Mod;
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    dp[0][0][0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            for(int k=0;k<=j;k++)
                for(int l=0;j+l<i;l++)
                {
                    if(c[i]!=0)
                    {
                        dp[i][j+1][k+1][l]=(dp[i][j+1][k+1][l]+1LL*pw[max(l-1,0)]*pw[i-1-j-l]%Mod*dp[i-1][j][k][l])%Mod;
                        if(l)dp[i][j+1][k][l]=(dp[i][j+1][k][l]+1LL*pw[l-1]*pw[i-1-j-l]%Mod*dp[i-1][j][k][l])%Mod;
                    }
                    if(c[i]!=1)
                    {
                        dp[i][j][k][l+1]=(dp[i][j][k][l+1]+1LL*pw[max(k-1,0)]*pw[j-k]%Mod*dp[i-1][j][k][l])%Mod;
                        if(k)dp[i][j][k][l]=(dp[i][j][k][l]+1LL*pw[k-1]*pw[j-k]%Mod*dp[i-1][j][k][l])%Mod;
                    }
                }
    int res=0;
    for(int j=0;j<=n;j++)
        for(int k=0;k<=j;k++)
            for(int l=0;j+l<=n;l++)
                if((k+l)%2==p)
                    res=(res+1LL*pw[j*(j-1)/2]*pw[(n-j)*(n-j-1)/2]%Mod*dp[n][j][k][l])%Mod;
    printf("%d\n",res);
    return 0;
}