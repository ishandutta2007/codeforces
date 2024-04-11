#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<60)-1;
int a[MAXN];
int solve()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    ll dp[2][2],tmp[2][2];
    dp[0][0]=0,dp[0][1]=dp[1][0]=dp[1][1]=INF;
    for(int i=0;i<=n;i++)
    {
        tmp[0][0]=tmp[0][1]=tmp[1][0]=tmp[1][1]=INF;

        /// not add
        ll cost=(i>0 && i<n ? abs(a[i]-a[i+1]) : 0);
        tmp[0][0]=min(tmp[0][0],dp[0][0]+cost);
        tmp[0][1]=min(tmp[0][1],dp[0][1]+cost);
        tmp[1][0]=min(tmp[1][0],dp[1][0]+cost);
        tmp[1][1]=min(tmp[1][1],dp[1][1]+cost);

        /// add 1
        if(i==0)cost=abs(1-a[1]);
        else if(i==n)cost=abs(a[n]-1);
        else cost=abs(a[i]-1)+abs(1-a[i+1]);
        tmp[1][0]=min(tmp[1][0],dp[0][0]+cost);
        tmp[1][1]=min(tmp[1][1],dp[0][1]+cost);

        /// add x
        if(i==0)cost=abs(x-a[1]);
        else if(i==n)cost=abs(a[n]-x);
        else cost=abs(a[i]-x)+abs(x-a[i+1]);
        tmp[0][1]=min(tmp[0][1],dp[0][0]+cost);
        tmp[1][1]=min(tmp[1][1],dp[1][0]+cost);

        /// both add
        if(i==0)cost=min(abs(x-1)+abs(1-a[1]),abs(1-x)+abs(x-a[1]));
        else if(i==n)cost=min(abs(a[n]-1)+abs(1-x),abs(a[n]-x)+abs(x-1));
        else cost=min(abs(a[i]-x)+abs(x-1)+abs(1-a[i+1]),abs(a[i]-1)+abs(1-x)+abs(x-a[i+1]));
        tmp[1][1]=min(tmp[1][1],dp[0][0]+cost);

        memcpy(dp,tmp,sizeof(tmp));
    }
    return 0*printf("%lld\n",dp[1][1]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}