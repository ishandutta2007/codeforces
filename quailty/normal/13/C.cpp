#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5005;
ll a[MAXN],b[MAXN],dp[2][MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    memcpy(b,a,sizeof(a));
    sort(b+1,b+n+1);
    int now=0,la=1;
    for(int i=1;i<=n;i++)
    {
        swap(la,now);
        dp[now][1]=dp[la][1]+abs(a[i]-b[1]);
        for(int j=2;j<=n;j++)
            dp[now][j]=min(dp[now][j-1],dp[la][j]+abs(a[i]-b[j]));
    }
    return 0*printf("%I64d",dp[now][n]);
}