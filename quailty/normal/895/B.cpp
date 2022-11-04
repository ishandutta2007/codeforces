#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN];
int main()
{
    int n;
    ll x,k;
    scanf("%d%lld%lld",&n,&x,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll d=max(a[i],((a[i]-1)/x+k)*x),u=((a[i]-1)/x+k+1)*x-1;
//        printf("%lld %lld\n",d,u);
        res+=max(0,upper_bound(a+1,a+n+1,u)-lower_bound(a+1,a+n+1,d));
    }
    printf("%lld\n",res);
    return 0;
}