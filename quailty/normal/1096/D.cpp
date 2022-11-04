#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
int a[MAXN];
char s[MAXN];
ll dp[MAXN][4];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<4;j++)
            dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='h')
        {
            dp[i][1]=max({dp[i][1],dp[i-1][1],dp[i-1][0]+a[i]});
            dp[i][0]=max(dp[i][0],dp[i-1][0]);
        }
        else dp[i][0]=max(dp[i][0],dp[i-1][0]+a[i]);
        if(s[i]=='a')
        {
            dp[i][2]=max({dp[i][2],dp[i-1][2],dp[i-1][1]+a[i]});
            dp[i][1]=max(dp[i][1],dp[i-1][1]);
        }
        else dp[i][1]=max(dp[i][1],dp[i-1][1]+a[i]);
        if(s[i]=='r')
        {
            dp[i][3]=max({dp[i][3],dp[i-1][3],dp[i-1][2]+a[i]});
            dp[i][2]=max(dp[i][2],dp[i-1][2]);
        }
        else dp[i][2]=max(dp[i][2],dp[i-1][2]+a[i]);
        if(s[i]=='d')dp[i][3]=max(dp[i][3],dp[i-1][3]);
        else dp[i][3]=max(dp[i][3],dp[i-1][3]+a[i]);
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    printf("%lld\n",sum-max({dp[n][0],dp[n][1],dp[n][2],dp[n][3]}));
    return 0;
}