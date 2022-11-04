#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
int x[MAXN],a[MAXN],b[MAXN],c[MAXN],d[MAXN],h[MAXN];
vector<pair<int,int>> lad[MAXN];
ll dp[MAXN];
void solve()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        lad[i].clear();
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d%d%d",&a[i],&b[i],&c[i],&d[i],&h[i]);
        lad[a[i]].emplace_back(b[i],i);
        lad[c[i]].emplace_back(d[i],-i);
        dp[i]=INF;
    }
    for(int i=1;i<=n;i++)
        sort(lad[i].begin(),lad[i].end());
    // first floor
    for(auto& [j,idx] : lad[1])
    {
        assert(idx>0);
        dp[idx]=min(dp[idx],1LL*abs(j-1)*x[1]);
    }
    // go up
    for(int i=2;i<=n;i++)
    {
        // left to right
        ll now=INF;
        for(auto& [j,idx] : lad[i])
        {
            if(idx>0)
            {
                if(now<INF)dp[idx]=min(dp[idx],now+1LL*j*x[i]);
            }
            else
            {
                if(dp[-idx]<INF)now=min(now,dp[-idx]-h[-idx]-1LL*j*x[i]);
            }
        }
        reverse(lad[i].begin(),lad[i].end());
        // right to left
        now=INF;
        for(auto& [j,idx] : lad[i])
        {
            if(idx>0)
            {
                if(now<INF)dp[idx]=min(dp[idx],now-1LL*j*x[i]);
            }
            else
            {
                if(dp[-idx]<INF)now=min(now,dp[-idx]-h[-idx]+1LL*j*x[i]);
            }
        }
        reverse(lad[i].begin(),lad[i].end());
    }
    // escape
    ll res=INF;
    for(auto& [j,idx] : lad[n])
    {
        assert(idx<0);
        if(dp[-idx]<INF)
            res=min(res,dp[-idx]-h[-idx]+1LL*abs(m-j)*x[n]);
    }
    if(res==INF)printf("NO ESCAPE\n");
    else printf("%lld\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}