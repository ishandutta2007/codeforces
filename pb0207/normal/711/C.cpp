#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-8
#define maxn 105
#define inf 0x3f3f3f3f3f3f3f3f
#define IN freopen("in.txt","r",stdin);
using namespace std;
int c[105];
long long cost[105][105];
long long dp[105][105][105];
pair<long long,int> mfirst[105][105],msecond[105][105];

int main()
{
    int n,m,s;
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%I64d",&cost[i][j]);
            if(c[i])  cost[i][c[i]]=0;
        }

        memset(dp,inf,sizeof(dp));
        memset(mfirst,inf,sizeof(mfirst));
        memset(msecond,inf,sizeof(msecond));
        for(int i=1;i<=m;i++)
            dp[0][0][i]=0;
        mfirst[0][0]=make_pair(0,-1);
        msecond[0][0]=make_pair(0,-1);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s&&j<=i;j++)
            {
                for(int k=1;k<=m;k++)
                {
                    if(c[i]&&c[i]!=k) continue;
                    long long my=mfirst[i-1][j-1].first;
                    if(mfirst[i-1][j-1].second==k) my=msecond[i-1][j-1].first;
                    
                    dp[i][j][k]=min(my,dp[i-1][j][k])+cost[i][k];
                    if(dp[i][j][k]<mfirst[i][j].first){
                        msecond[i][j].first=mfirst[i][j].first;
                        mfirst[i][j].first=dp[i][j][k];
                        msecond[i][j].second=mfirst[i][j].second;
                        mfirst[i][j].second=k;
                    }
                    else if(dp[i][j][k]<msecond[i][j].first){
                        msecond[i][j].first=dp[i][j][k];
                        msecond[i][j].second=k;
                    }
                }
            }
        }
        long long ans=inf;
        for(int i=1;i<=m;i++)
            ans=min(ans,dp[n][s][i]);
        if(ans==inf)
            puts("-1");
        else
        printf("%I64d\n",ans);
    }
    return 0;
}