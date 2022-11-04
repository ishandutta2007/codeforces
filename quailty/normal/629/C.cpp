#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2005;
const int MAXM=100005;
const int Mod=1000000007;
char s[MAXM];
int dp[MAXN][MAXN];
void build(int n)
{
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%Mod;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    int tl=0,tr=0;
    for(int i=0;i<m;i++)
    {
        if(s[i]=='(')tl++;
        else
        {
            if(tl>0)tl--;
            else tr++;
        }
    }
    build(n-m);
    int res=0;
    for(int i=0;i<=n-m;i++)
        for(int j=tr;j<=i;j++)
            if(j-tr+tl>=0 && j-tr+tl<=n-m-i)
                res=(res+1LL*dp[i][j]*dp[n-m-i][j-tr+tl])%Mod;
    printf("%d",res);
    return 0;
}