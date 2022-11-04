#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
int a[105];
db dp[2][100005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(m==1)printf("%.15f\n",1.0);
    else
    {
        for(int i=1;i<=n;i++)
            sum+=a[i];
        int la=0,now=1;
        dp[now][0]=1.0;
        for(int i=1;i<=n;i++)
        {
            swap(la,now);
            memset(dp[now],0,sizeof(dp[now]));
            db t=0.0;
            for(int j=1;j<=n*m;j++)
            {
                t+=dp[la][j-1];
                if(j>=m+1)t-=dp[la][j-m-1];
                dp[now][j]=(t-(j>=a[i] ? dp[la][j-a[i]] : 0.0))/(m-1);
            }
        }
        db res=0.0;
        for(int i=0;i<sum;i++)
            res+=dp[now][i];
        printf("%.15f\n",1+(m-1)*res);
    }
    return 0;
}