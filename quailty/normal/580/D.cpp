#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[25],c[25][25];
ll dp[1<<18][18];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    int x,y;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        --x,--y;
        scanf("%I64d",&c[x][y]);
    }
    for(int i=0;i<n;i++)
        dp[1<<i][i]=a[i];
    for(int mask=1;mask<(1<<n);mask++)
        for(int i=0;i<n;i++)
            if(!(mask&(1<<i)))
                for(int j=0;j<n;j++)
                    if(mask&(1<<j))
                        dp[mask|(1<<i)][i]=max(dp[mask|(1<<i)][i],dp[mask][j]+a[i]+c[j][i]);
    ll ans=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
            if(mask&(1<<i))cnt++;
        if(cnt==m)
            for(int i=0;i<n;i++)
                ans=max(ans,dp[mask][i]);
    }
    printf("%I64d\n",ans);
    return 0;
}