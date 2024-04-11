#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
db p[5005],dp[2][5005];
int t[5005];
int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    for(int i=1,tp;i<=n;i++)
    {
        scanf("%d%d",&tp,&t[i]);
        p[i]=tp/100.0;
    }
    db res=0;
    int now=0,la=1;
    dp[now][0]=1;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        db cof=pow(1-p[i],t[i]-1),tmp=0;
        for(int j=t[i];j<=T;j++)
            dp[now][j]+=dp[la][j-t[i]]*cof;
        cof=pow(1-p[i],t[i]-2)*p[i];
        if(t[i]>1)for(int j=0;j<=T;j++)
        {
            dp[now][j]+=tmp;
            if(j>=t[i]-1)tmp-=dp[la][j-t[i]+1]*cof;
            tmp=tmp*(1-p[i])+dp[la][j]*p[i];
        }
        for(int j=0;j<=T;j++)
            res+=dp[now][j];
    }
    return 0*printf("%.9f",res);
}