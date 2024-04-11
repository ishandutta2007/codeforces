#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int MAXM=10005;
int a[MAXN],v[MAXN],dp[2][MAXM];
int main()
{
    int n,m,sum=0,now=0,la=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        for(int j=1;j<=p;j++)
        {
            scanf("%d",&a[j]);
            a[j]+=a[j-1];
        }
        for(int j=1;j<=p;j++)v[j]=0;
        for(int j=1;j<=p;j++)
            for(int k=j-1;k<=p;k++)
                v[p-(k-j+1)]=max(v[p-(k-j+1)],a[p]-(a[k]-a[j-1]));
        sum+=p;
        swap(now,la);
        for(int j=0;j<=sum;j++)dp[now][j]=0;
        for(int j=0;j<=p;j++)
            for(int k=0;k+j<=sum;k++)
                dp[now][j+k]=max(dp[now][j+k],dp[la][k]+v[j]);
    }
    return 0*printf("%d",dp[now][m]);
}