#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
char str[4][1005];
int cost[5],dp[2][625];
inline void decode(int n,int a[])
{
    for(int i=0;i<4;i++)
        a[i]=n%5,n/=5;
}
inline int encode(int a[])
{
    int res=0;
    for(int i=3;i>=0;i--)
        res=res*5+a[i];
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=4;i++)
        scanf("%d",&cost[i]);
    for(int i=0;i<4;i++)
        scanf("%s",str[i]);
    int now=0,la=1;
    for(int j=0;j<625;j++)
        dp[now][j]=(j>0)*INF;
    for(int x=0;x<n;x++)
        for(int y=0;y<4;y++)
        {
            swap(now,la);
            for(int j=0;j<625;j++)
                dp[now][j]=INF;
            char ty=str[y][x];
            int cur[4];
            for(int j=0;j<625;j++)
            {
                decode(j,cur);
                for(int k=0;k<=4;k++)
                {
                    int tmp[4];
                    for(int t=0;t<4;t++)
                        tmp[t]=cur[t];
                    for(int t=y;t<min(4,y+k);t++)
                        tmp[t]=max(tmp[t],k);
                    if(tmp[y]<(ty=='*'))continue;
                    tmp[y]=max(tmp[y]-1,0);
                    int tj=encode(tmp);
                    dp[now][tj]=min(dp[now][tj],dp[la][j]+cost[k]);
                }
            }
        }
    int res=INF;
    for(int j=0;j<625;j++)
        res=min(res,dp[now][j]);
    return 0*printf("%d\n",res);
}