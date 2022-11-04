#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),sum+=a[i];
    sort(a+1,a+n+1);
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        int idx=lower_bound(a+1,a+n+1,x)-a;
        ll res=(1LL<<60)-1;
        for(int j=max(1,idx-1);j<=min(n,idx);j++)
            res=min(res,max(x-a[j],0LL)+max(y-(sum-a[j]),0LL));
        printf("%lld\n",res);
    }
    return 0;
}