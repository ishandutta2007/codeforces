#include <bits/stdc++.h>
using namespace std;
const int MAXN=15;
const int INF=0x3f3f3f3f;
int a[MAXN],loc[MAXN],sum[(1<<MAXN)+5],dp[MAXN+2][(1<<MAXN)+5][MAXN+2];
pair<int,int> pre[MAXN+2][(1<<MAXN)+5][MAXN+2];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<(1<<n);i++)
    {
        sum[i]=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))sum[i]+=a[j];
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<(1<<n);j++)
            for(int k=0;k<=n;k++)
                dp[i][j][k]=INF;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            for(int k=0;k<=n;k++)if(dp[i][j][k]<INF)
            {
                if(dp[i+1][j][k]>dp[i][j][k])
                {
                    dp[i+1][j][k]=dp[i][j][k];
                    pre[i+1][j][k]={-1,0};
                }
                if((j&(1<<i)) || k==n)continue;
                for(int all=((1<<n)-1)-j,sub=all;sub;sub=(sub-1)&all)
                {
                    if(~sub&(1<<i))continue;
                    if(sum[sub]<=dp[i][j][k])continue;
                    if(dp[i+1][j|sub][k+1]<sum[sub])continue;
                    dp[i+1][j|sub][k+1]=sum[sub];
                    pre[i+1][j|sub][k+1]={i,sub};
                }
            }
    int tj=(1<<n)-1,tk=0;
    for(int k=1;k<=n;k++)
        if(dp[n][tj][k]<INF)tk=k;
    printf("%d\n",n-tk);
    vector<pair<int,int>> opt;
    for(int i=n;i>=1;i--)
    {
        pair<int,int> s=pre[i][tj][tk];
        if(s.first>=0)
        {
            opt.push_back(s);
            tj-=s.second,tk--;
        }
    }
    for(int i=0;i<n;i++)
        loc[i]=i+1;
    vector<pair<int,int>> res;
    for(auto &t:opt)
        for(int i=0;i<n;i++)
        {
            if(i==t.first || (~t.second&(1<<i)))continue;
            res.push_back({loc[i],loc[t.first]});
            for(int j=0;j<n;j++)
                loc[j]-=(loc[j]>=loc[i]);
        }
    for(auto &t:res)
        printf("%d %d\n",t.first,t.second);
}
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}