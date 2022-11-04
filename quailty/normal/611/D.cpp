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
int lcp[MAXN][MAXN],dp[MAXN][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=n;i>0;i--)
        for(int j=n;j>0;j--)
        {
            if(s[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
            else lcp[i][j]=0;
        }
    dp[1][1]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<=n;j++)
            dp[i][j]=(dp[i][j]+dp[i][j-1])%Mod;
        for(int j=i;j<n && n-j>=j-i+1;j++)
        {
            if(s[j+1]=='0')continue;
            int t=lcp[i][j+1];
            if(t>=j-i+1)
            {
                dp[j+1][2*j-i+2]=(dp[j+1][2*j-i+2]+dp[i][j])%Mod;
            }
            else
            {
                if(s[i+t]<s[j+1+t])dp[j+1][2*j-i+1]=(dp[j+1][2*j-i+1]+dp[i][j])%Mod;
                else dp[j+1][2*j-i+2]=(dp[j+1][2*j-i+2]+dp[i][j])%Mod;
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res=(res+dp[i][n])%Mod;
    printf("%d\n",(res+Mod)%Mod);
    return 0;
}