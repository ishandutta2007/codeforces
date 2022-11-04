#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1000005;
int L[MAXN];
vector<ll> len[MAXN],sum[MAXN];
ll cal(int u,ll t)
{
    int loc=upper_bound(len[u].begin(),len[u].end(),t)-len[u].begin();
    return (loc ? t*loc-sum[u][loc-1] : 0);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
        scanf("%lld",&L[i]);
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int u=i;u;u>>=1)
        {
            len[u].push_back(now);
            now+=L[u];
        }
    }
    for(int i=1;i<=n;i++)
    {
        sort(len[i].begin(),len[i].end());
        sum[i]=len[i];
        for(int j=1;j<(int)sum[i].size();j++)
            sum[i][j]+=sum[i][j-1];
    }
    while(m--)
    {
        int A,H;
        scanf("%d%d",&A,&H);
        ll res=cal(A,H);
        for(int u=A,f=u>>1;f;u>>=1,f>>=1)
            H-=L[u],res+=cal(f,H)-cal(u,H-L[u]);
        printf("%lld\n",res);
    }
    return 0;
}