#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const int INF=0x3f3f3f3f;
int a[MAXN],dp[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=n;i++)
            dp[i]=-INF;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[i],dp[i-1]);
            if(i+a[i]<=n+1)dp[i+a[i]-1]=max(dp[i+a[i]-1],dp[i-1]+1);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}