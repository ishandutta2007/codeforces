#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[105],dp[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    dp[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=i-1;j>=0;j--)
            if(a[i]-a[j]==1)
                dp[i]+=dp[j];
    printf("%I64d\n",dp[n]);
    return 0;
}