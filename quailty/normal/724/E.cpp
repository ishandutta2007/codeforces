#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=10005;
const ll INF=(1LL<<60)-1;
int p[MAXN],s[MAXN];
ll dp[2][MAXN];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    int now=0,la=1;
    for(int j=0;j<=n;j++)
        dp[now][j]=(j>0)*INF;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        for(int j=0;j<=n;j++)
            dp[now][j]=INF;
        for(int j=0;j<=i;j++)
        {
            dp[now][j]=min(dp[now][j],dp[la][j]+p[i]+1LL*c*j);
            if(j)dp[now][j]=min(dp[now][j],dp[la][j-1]+s[i]);
        }
    }
    ll res=INF;
    for(int i=0;i<=n;i++)
        res=min(res,dp[now][i]);
    printf("%I64d\n",res);
    return 0;
}