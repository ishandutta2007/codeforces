#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007LL;
int a[1000005];
int b[1000005];
ll dp[2][1000005];
int main()
{
    int n,k;
    ll L;
    scanf("%d%I64d%d",&n,&L,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        b[i]=a[i];
    sort(b,b+n);
    int cnt=unique(b,b+n)-b;
    for(int i=0;i<n;i++)
        a[i]=lower_bound(b,b+cnt,a[i])-b;
    int la=0,now=1;
    ll seg=L/n,ans=0;
    dp[now][0]=1LL;
    for(int i=1;i<=k && i<=seg+1;i++)
    {
        swap(la,now);
        for(int j=0;j<cnt;j++)
            dp[now][j]=0;
        for(int j=1;j<cnt;j++)
            dp[la][j]=(dp[la][j]+dp[la][j-1])%Mod;
        for(int j=0;j<n;j++)
            dp[now][a[j]]=(dp[now][a[j]]+dp[la][a[j]])%Mod;
        for(int j=0;j<cnt;j++)
            ans=(ans+(seg-i+1)%Mod*dp[now][j]%Mod)%Mod;
        for(int j=0;j<L-seg*n;j++)
            ans=(ans+dp[la][a[j]])%Mod;
    }
    printf("%I64d\n",ans);
    return 0;
}