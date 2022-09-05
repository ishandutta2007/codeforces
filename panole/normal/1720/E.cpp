#include<bits/stdc++.h>
using namespace std;

int n,a[510][510],xmi[250010],ymi[250010],xma[250010],yma[250010],sum[510][510],t;

int main()
{
    scanf("%d%d",&n,&t);
    for (int i=1; i<=n*n; i++) xmi[i]=ymi[i]=n+1,xma[i]=yma[i]=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            scanf("%d",&a[i][j]);
            xmi[a[i][j]]=min(xmi[a[i][j]],i);
            xma[a[i][j]]=max(xma[a[i][j]],i);
            ymi[a[i][j]]=min(ymi[a[i][j]],j);
            yma[a[i][j]]=max(yma[a[i][j]],j);
        }
    int cnt=0;
    for (int i=1; i<=n*n; i++) if (xma[i]) cnt++;
    if (cnt<=t) return printf("%d\n",t-cnt),0;
    for (int len=1; len<=n; len++)
    {
        memset(sum,0,sizeof(sum));
        for (int i=1; i<=n*n; i++) if (xma[i])
        {
            int xl=max(xma[i]-len+1,1),yl=max(yma[i]-len+1,1);
            if (xma[i]<xmi[i]+len&&yma[i]<ymi[i]+len)
                sum[xl][yl]++,sum[xl][ymi[i]+1]--,
                sum[xmi[i]+1][yl]--,sum[xmi[i]+1][ymi[i]+1]++;
        }
        for (int i=1; i<=n-len+1; i++)
            for (int j=1; j<=n-len+1; j++)
            {
                sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                if (sum[i][j]==cnt-t||sum[i][j]==cnt-t+1) return puts("1"),0;
            }
    }
    puts("2");
    return 0;
}