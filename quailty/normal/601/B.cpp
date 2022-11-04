#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],l[MAXN],r[MAXN];
ll dp[MAXN][20];
int mm[MAXN];
void initRMQ(int n,ll b[])
{
    mm[0]=-1;
    for(int i=1;i<=n;i++)
    {
        mm[i]=((i&(i-1))==0) ? mm[i-1]+1 : mm[i-1];
        dp[i][0]=b[i];
    }
    for(int j=1;j<=mm[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int x,int y)
{
    int k=mm[y-x+1];
    return max(dp[x][k],dp[y-(1<<k)+1][k]);
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i=n-1;i>0;i--)
        a[i]-=a[i-1];
    for(int i=1;i<n;i++)
        if(a[i]<0)
            a[i]=-a[i];
    //for(int i=1;i<n;i++)
    //    printf("%I64d ",a[i]);
    //printf("\n");
    n--;
    initRMQ(n,a);
    for(int i=1;i<=n;i++)
    {
        int tl=1,tr=i;
        while(tl<tr)
        {
            int tm=(tl+tr)>>1;
            if(rmq(tm,i-1)>=a[i])tl=tm+1;
            else tr=tm;
        }
        l[i]=tl;
        tl=i,tr=n;
        while(tl<tr)
        {
            int tm=(tl+tr+1)>>1;
            if(rmq(i,tm)>a[i])tr=tm-1;
            else tl=tm;
        }
        r[i]=tl;
    }
    //for(int i=1;i<=n;i++)
    //    printf("%I64d %I64d\n",l[i],r[i]);
    while(q--)
    {
        ll x,y;
        scanf("%I64d%I64d",&x,&y);
        y--;
        ll res=0;
        for(int i=x;i<=y;i++)
            res+=(i-max(x,l[i])+1)*(min(y,r[i])-i+1)*a[i];
        printf("%I64d\n",res);
    }
    return 0;
}