#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
ll a[MAXN],dp[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    int la=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[la-1]+labs(a[i]-a[la]),dp[la]+labs(a[i]-a[la+1]));
        if(i<n)
        {
            if(a[i-1]<=a[i] && a[i]>=a[i+1])la=i;
            if(a[i-1]>=a[i] && a[i]<=a[i+1])la=i;
        }
    }
    printf("%I64d\n",dp[n]);
    return 0;
}