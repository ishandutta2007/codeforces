#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int a[MAXN],dp[MAXN],cnt[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=n+1;i++)
        dp[i]=-MAXN*(i>0);
    for(int l=1;l<=n+1;l++)
    {
        if(l==1 || l==n+1 || a[l]==a[l-1])
            dp[l]=max(dp[l],dp[l-1]+1);
        int mx=0;
        for(int i=1;i<=n;i++)cnt[i]=0;
        for(int r=l;r<=n;r++)
        {
            mx=max(mx,++cnt[a[r]]);
            if((r-l+1)%2==0 && mx<=(r-l+1)/2
                && (l==1 || r==n || a[l-1]==a[r+1]))
                dp[r+1]=max(dp[r+1],dp[l-1]+1);
        }
    }
    return 0*printf("%d\n",dp[n+1]-1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}