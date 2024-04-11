#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll f(ll n)
{
    ll tn=n,mx=0,mi=9;
    while(n)
    {
        ll t=n%10;
        mx=max(mx,t);
        mi=min(mi,t);
        n/=10;
    }
    return tn+mx*mi;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ll a,k;
        scanf("%lld%lld",&a,&k);
        --k;
        while(k--)
        {
            ll t=f(a);
            if(t==a)break;
            a=t;
        }
        printf("%lld\n",a);
    }
    return 0;
}