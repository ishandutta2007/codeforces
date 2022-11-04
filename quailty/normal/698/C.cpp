#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
const db eps=1e-9;
db p[20],dp[1<<20],res[20];
int main()
{
    int n,k,r=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&p[i]);
        r+=(p[i]>eps);
    }
    k=min(k,r);
    dp[0]=1;
    for(int i=0;i<(1<<n);i++)
    {
        int c=0;
        db sum=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
            {
                c++;
                sum+=p[j];
            }
        if(c==k)
        {
            for(int j=0;j<n;j++)
                if(i&(1<<j))res[j]+=dp[i];
            continue;
        }
        if(sum<1-eps)for(int j=0;j<n;j++)
        {
            if(i&(1<<j))continue;
            dp[i|(1<<j)]+=dp[i]*p[j]/(1-sum);
        }
    }
    for(int i=0;i<n;i++)
        printf("%.12f ",res[i]);
    return 0;
}