#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cal(ll d,ll k,ll a,ll b,ll t,ll x)
{
    return a*k*x+t*(x-1)+b*(d-k*x);
}
int main()
{
    ll d,k,a,b,t;
    scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t);
    if(d<k)printf("%I64d",a*d);
    else
    {
        ll l=1,r=d/k;
        while(l<r)
        {
            ll m1=(2*l+r)/3;
            ll m2=(l+2*r+2)/3;
            if(cal(d,k,a,b,t,m1)<cal(d,k,a,b,t,m2))r=m2-1;
            else l=m1+1;
        }
        ll res=cal(d,k,a,b,t,l);
        res=min(res,a*d+(d-1)/k*t);
        printf("%I64d",res);
    }
    return 0;
}