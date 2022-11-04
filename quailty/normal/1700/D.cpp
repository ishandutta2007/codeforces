#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll v[MAXN],t[MAXN];
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&v[i]),v[i]+=v[i-1];
    ll mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,(v[i]+i-1)/i);
        t[i]=max(mx,(v[n]+i-1)/i);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        ll qt;
        scanf("%lld",&qt);
        int res=lower_bound(t+1,t+n+1,qt,greater<ll>())-t;
        printf("%d\n",(res>n ? -1 : res));
    }
    return 0;
}
int main()
{
    int T=1;
    while(T--)solve();
    return 0;
}