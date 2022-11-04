#include<bits/stdc++.h>
using namespace std;
const int MAXN=65;
const int Mod=1000000007;
int dp[MAXN][6];
int main()
{
    int k;
    scanf("%d",&k);
    for(int j=0;j<6;j++)
        dp[1][j]=1;
    for(int i=1;i<=k;i++)
        for(int j=0;j<6;j++)
            for(int p=0;p<6;p++)
                for(int q=0;q<6;q++)
                    if(j!=p && j!=q && j!=(p+3)%6 && j!=(q+3)%6)
                        dp[i][j]=(dp[i][j]+1LL*dp[i-1][p]*dp[i-1][q])%Mod;
    int res=0;
    for(int j=0;j<6;j++)
        res=(res+dp[k][j])%Mod;
    return 0*printf("%d\n",res);
}