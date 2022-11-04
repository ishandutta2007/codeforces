#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e7+5;
ll dp[MAXN<<1];
int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    memset(dp,0x3f,sizeof(dp));
    dp[1]=x;
    for(int i=1;i<n;i++)
    {
        dp[2*i]=min(dp[2*i],dp[i]+y);
        dp[i+1]=min(dp[i+1],dp[i]+x);
        dp[2*i-1]=min(dp[2*i-1],dp[i]+x+y);
    }
    return 0*printf("%I64d",dp[n]);
}