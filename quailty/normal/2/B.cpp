#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int INF=0X3f3f3f3f;
const int f[2]={2,5};
int a[2][MAXN][MAXN],dp[2][MAXN][MAXN];
char res[MAXN<<1];
int main()
{
    int n;
    scanf("%d",&n);
    bool zero=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int p;
            scanf("%d",&p);
            if(!p)
            {
                zero=1;
                for(int k=0;k<2;k++)
                    a[k][i][j]=-1;
                continue;
            }
            for(int k=0;k<2;k++)
                while(p%f[k]==0)
                {
                    p/=f[k];
                    a[k][i][j]++;
                }
        }
    memset(dp,INF,sizeof(dp));
    for(int k=0;k<2;k++)
        if(a[k][1][1]>=0)
            dp[k][1][1]=a[k][1][1];
    for(int i=1;i<=n;i++)
        for(int j=1+(i==1);j<=n;j++)
            for(int k=0;k<2;k++)
            {
                if(a[k][i][j]<0)continue;
                dp[k][i][j]=min(dp[k][i][j],dp[k][i-1][j]+a[k][i][j]);
                dp[k][i][j]=min(dp[k][i][j],dp[k][i][j-1]+a[k][i][j]);
            }
    int loc=0;
    if(dp[1][n][n]<dp[0][n][n])loc=1;
    int ans=dp[loc][n][n];
    if(ans<INF)
    {
        int x=n,y=n,now=0;
        while(1)
        {
            if(x>1 && dp[loc][x][y]==dp[loc][x-1][y]+a[loc][x][y])
            {
                x--;
                res[now++]='D';
            }
            else if(y>1 && dp[loc][x][y]==dp[loc][x][y-1]+a[loc][x][y])
            {
                y--;
                res[now++]='R';
            }
            else break;
        }
        reverse(res,res+now);
    }
    if(zero && ans>1)
    {
        printf("1\n");
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[0][i][j]<0)
                {
                    for(int x=1;x<i;x++)printf("D");
                    for(int y=1;y<j;y++)printf("R");
                    for(int x=i;x<n;x++)printf("D");
                    for(int y=j;y<n;y++)printf("R");
                    return 0;
                }
    }
    printf("%d\n%s\n",ans,res);
    return 0;
}