#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
const ll INF=(1LL<<60)-1;
int dp[MAXN];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,s;i<=m;i++)
        scanf("%d",&s),dp[s]=1;
    if(dp[0])
    {
        for(int i=1;i<=k;i++)
            scanf("%*d");
        return 0*printf("-1\n");
    }
    for(int i=0;i<=n;i++)
        dp[i]=(dp[i] ? dp[i-1] : i);
    ll res=INF;
    for(int i=1;i<=k;i++)
    {
        int a;
        scanf("%d",&a);
        int c=1,la=i;
        while(la<n)
        {
            if(dp[la]<=la-i)break;
            la=dp[la]+i,c++;
        }
        if(la>=n)res=min(res,1LL*a*c);
    }
    printf("%lld\n",(res<INF ? res : -1));
    return 0;
}