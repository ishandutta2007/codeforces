#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2005;
const int Mod=1000000007;
int a[MAXN],dp[2][MAXN];
inline void add(int &x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
    if(x<0)x+=Mod;
}
int main()
{
    int n,h;
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=h;
    memset(dp,0,sizeof(dp));
    int now=1,la=0;
    dp[now][0]=1;
    for(int i=1;i<=n+1;i++)
    {
        swap(now,la);
        memset(dp[now],0,sizeof(dp[now]));
        for(int j=0;j<=n;j++)
        {
            if(a[i]+j==h)
            {
                add(dp[now][j],dp[la][j]);
                if(j)add(dp[now][j-1],1LL*j*dp[la][j]%Mod);
            }
            if(a[i]+j+1==h)
            {
                add(dp[now][j+1],dp[la][j]);
                add(dp[now][j],1LL*(j+1)*dp[la][j]%Mod);
            }
        }
    }
    return 0*printf("%d",dp[now][0]);
}