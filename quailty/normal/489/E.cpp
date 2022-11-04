#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long double db;
const int MAXN=1005;
const db inf=1e10;
const db eps=1e-9;
int x[MAXN],b[MAXN];
db dp[MAXN];
int pre[MAXN];
void getPath(int u)
{
    if(!u)return;
    getPath(pre[u]);
    printf("%d ",u);
}
void calDp(db r,int n,int l)
{
    for(int i=1;i<=n;i++)dp[i]=inf;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
        {
            db cost=sqrt(abs(x[i]-x[j]-l))-r*b[i];
            if(dp[i]>dp[j]+cost)
            {
                dp[i]=dp[j]+cost;
                pre[i]=j;
            }
        }
}
int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&b[i]);
    db tl=0,tr=1000000;
    for(int _=0;_<100;_++)
    {
        db tm=(tl+tr)/2;
        calDp(tm,n,l);
        if(dp[n]>-eps)tl=tm;
        else tr=tm;
    }
    calDp((tl+tr)/2,n,l);
    getPath(n);
    return 0;
}