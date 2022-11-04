#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int MAXK=15;
int c[MAXN],f[MAXN],h[MAXK],dp[MAXN],fp[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n*k;i++)
    {
        int t;
        scanf("%d",&t);
        c[t]++;
    }
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        f[t]++;
    }
    for(int i=1;i<=k;i++)
        scanf("%d",&h[i]);
    int res=0;
    for(int _=0;_<MAXN;_++)
    {
        for(int j=0;j<=c[_];j++)
            dp[j]=0;
        for(int i=0;i<f[_];i++)
            for(int j=c[_];j>=0;j--)
                for(int t=1;j+t<=c[_] && t<=k;t++)
                    dp[j+t]=max(dp[j+t],dp[j]+h[t]);
        res+=dp[c[_]];
    }
    printf("%d\n",res);
    return 0;
}