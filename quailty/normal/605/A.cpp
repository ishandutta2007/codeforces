#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int a[MAXN],dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int res=0;
    for(int i=1;i<=n;i++)
    {
        dp[a[i]]=max(dp[a[i]],dp[a[i]-1]+1);
        res=max(res,dp[a[i]]);
    }
    printf("%d\n",n-res);
    return 0;
}