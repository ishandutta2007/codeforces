#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[30][30];
int dp[30][30][30][30];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    int res=0;
    for(int u=0;u<=n;u++)
        for(int l=0;l<=m;l++)
            for(int d=0;d<=n;d++)
                for(int r=0;r<=m;r++)
                    dp[u][l][d][r]=(d<u || r<l);
    for(int u=1;u<=n;u++)
        for(int l=1;l<=m;l++)
            for(int d=u;d<=n;d++)
                for(int r=l;r<=m;r++)
                    if(dp[u][l][d][r]=(dp[u][l][d-1][r] && dp[u][l][d][r-1] && s[d][r]=='0'))
                        res=max(res,2*(d-u+1)+2*(r-l+1));
    return 0*printf("%d",res);
}