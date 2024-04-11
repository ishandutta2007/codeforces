#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
char s[3][115];
bool dp[3][35];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(s,0,sizeof(s));
        memset(dp,0,sizeof(dp));
        int n,k;
        scanf("%d%d",&n,&k);
        int c=n/3+1;
        for(int i=0;i<3;i++)
            scanf("%s",s[i]);
        for(int i=0;i<3;i++)
            for(int j=n;j<=3*c;j++)
                s[i][j]='.';
        int col;
        for(int i=0;i<3;i++)
            if(s[i][0]=='s')col=i;
        dp[col][0]=1;
        for(int j=0;j<c;j++)
            for(int i=0;i<3;i++)
            {
                if(!dp[i][j])continue;
                if(s[i][3*j+1]!='.')continue;
                for(int k=-1;k<=1;k++)
                {
                    if(i+k<0 || i+k>2)continue;
                    bool isok=1;
                    if(k!=0)isok&=(s[i+k][3*j+1]=='.');
                    isok&=(s[i+k][3*j+2]=='.');
                    isok&=(s[i+k][3*j+3]=='.');
                    if(isok)dp[i+k][j+1]=1;
                }
            }
        if(dp[0][c]||dp[1][c]||dp[2][c])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}