#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int dp[MAXN],cnt[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1,a;i<=n;i++)
            scanf("%d",&a),cnt[a]++;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<MAXN;i++)
        {
            dp[i]=max(dp[i],cnt[i]);
            for(int j=i+i;j<MAXN;j+=i)
                dp[j]=max(dp[j],dp[i]+cnt[j]);
        }
        int res=0;
        for(int i=1;i<MAXN;i++)
            res=max(res,dp[i]);
        printf("%d\n",n-res);
    }
    return 0;
}