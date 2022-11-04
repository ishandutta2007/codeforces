#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5005;
const int Mod=1000000007;
char s[MAXN];
int dp[MAXN][MAXN],C[MAXN][MAXN],la[26];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=(C[0][0]=1);i<=n-1;i++)
        for(int j=(C[i][0]=1);j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=dp[i-1][j];
        for(int j=1;j<=n;j++)
        {
            if(!la[s[i]-'a'])dp[i][j]+=dp[i-1][j-1];
            else dp[i][j]+=dp[i-1][j-1]-dp[la[s[i]-'a']][j-1];
            dp[i][j]=(dp[i][j]%Mod+Mod)%Mod;
        }
        la[s[i]-'a']=i;
    }
    int res=0;
    for(int j=1;j<=n;j++)
        res=(res+1LL*dp[n][j]*C[n-1][j-1])%Mod;
    return 0*printf("%d",res);
}