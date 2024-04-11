#include<bits/stdc++.h>
#define eps 1e-8
using namespace std;
int n,k,m;
double p[20],dp[2000000],ans[20];
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%lf",&p[i]);
        if (p[i]>eps) m++;
    }
    k=min(k,m);
    dp[0]=1;
    for (int i=1;i<(1<<n);i++)
    {
        int tmp=0;
        double sum=0;
        for (int j=0;j<n;j++)
        if (i&(1<<j))
        {
            sum+=p[j];
            tmp++;
        }
        if (tmp>k) continue;
        for (int j=0;j<n;j++)
        if (i&(1<<j)) dp[i]+=dp[i^(1<<j)]*p[j]/(1-sum+p[j]);
        if (tmp==k)
        {
            for (int j=0;j<n;j++)
            if (i&(1<<j)) ans[j]+=dp[i];
        }
    }
    for (int i=0;i<n;i++) printf("%.8lf ",ans[i]);
    return 0;
}