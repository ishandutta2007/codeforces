#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<62)-1;
char s[105];
ll dp[105];
int main()
{
    int n;
    scanf("%d%s",&n,s+1);
    int len=strlen(s+1);
    for(int i=0;i<=len;i++)
        dp[i]=INF;
    dp[0]=0;
    for(int i=1;i<=len;i++)
    {
        ll now=0;
        for(int j=i;j<=len;j++)
        {
            now=now*10+s[j]-'0';
            if(now>=n)break;
            if(s[i]=='0' && j>i)break;
            if(1.0*dp[i-1]*n+now>2e18)continue;
            dp[j]=min(dp[j],dp[i-1]*n+now);
        }
    }
    return 0*printf("%lld",dp[len]);
}