#include<bits/stdc++.h>
using namespace std;
const int MAXN=255;
const int INF=0x3f3f3f3f;
inline void upd(int& x,int y) { (x>y) && (x=y); }
int a[MAXN],dp[2][MAXN][MAXN*2-5];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(dp,INF,sizeof(dp));
    int now=0,la=1;
    dp[now][m][MAXN]=0;
    for(int i=0;i<n;i++)
    {
        swap(now,la);
        memset(dp[now],INF,sizeof(dp[now]));
        for(int j=0;i*j<=m && j<=m;j++)
            for(int k=-m;k<=m;k++)if(dp[la][j][k+MAXN]<INF)
                for(int tj=0;tj<=j;tj++)
                {
                    int tk=k+a[i+1]-tj;
                    if(tk<-m || tk>m)continue;
                    upd(dp[now][tj][tk+MAXN],dp[la][j][k+MAXN]+abs(tk));
                }
    }
    int res=INF;
    for(int j=0;j<=m;j++)
        upd(res,dp[now][j][MAXN]);
    return 0*printf("%d\n",res);
}