#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll a[MAXN];
int solve()
{
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        a[i]+=a[i-1];
    ll res=0,day=0;
    for(int i=n;i>=1;i--)
    {
        if(x<a[i]+i*day)continue;
        ll c=(x-a[i])/i-day+1;
        res+=i*c,day+=c;
    }
    return 0*printf("%lld\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}