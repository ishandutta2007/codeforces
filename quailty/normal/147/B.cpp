#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int dp[15][305][305],now[305][305],tmp[305][305];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int _=0;_<9;_++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[_][i][j]=-INF*(i!=j);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%d%d",&dp[0][x][y],&dp[0][y][x]);
    }
    for(int _=1;_<9;_++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(dp[_-1][i][j]>-INF && dp[_-1][j][k]>-INF)
                        dp[_][i][k]=max(dp[_][i][k],dp[_-1][i][j]+dp[_-1][j][k]);
    int res=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            now[i][j]=-INF*(i!=j);
    for(int _=8;_>=0;_--)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                tmp[i][j]=-INF*(i!=j);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    if(now[i][j]>-INF && dp[_][j][k]>-INF)
                        tmp[i][k]=max(tmp[i][k],now[i][j]+dp[_][j][k]);
        bool isok=0;
        for(int i=1;i<=n;i++)
            isok|=(tmp[i][i]>0);
        if(!isok)
        {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    now[i][j]=tmp[i][j];
            res+=(1<<_);
        }
    }
    printf("%d\n",(res<n ? res+1 : 0));
    return 0;
}