#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[1005],b[2005];
bool dp[2005][1005];
inline ll cal(int i,int j,int p)
{
    return abs(b[i]-a[j])+abs(p-b[i]);
}
bool check(int n,int k,int p,ll m)
{
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=k;i++)
        for(int j=0;j<=n;j++)
        {
            dp[i][j]|=dp[i-1][j];
            if(j)dp[i][j]|=(dp[i-1][j-1] && cal(i,j,p)<=m);
        }
    return dp[k][n];
}
int main()
{
    int n,k,p;
    scanf("%d%d%d",&n,&k,&p);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=k;i++)
        scanf("%lld",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    ll l=0,r=(1LL<<60)-1;
    while(l<r)
    {
        ll m=(l+r)/2;
        if(check(n,k,p,m))r=m;
        else l=m+1;
    }
    return 0*printf("%lld",l);
}