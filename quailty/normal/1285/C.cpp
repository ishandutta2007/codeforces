#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x)
{
    ll t=sqrt(x);
    while(t*t<x)t++;
    while(t*t>x)t--;
    return t;
}
int main()
{
    ll x;
    scanf("%lld",&x);
    for(ll i=f(x);i>=1;i--)if(x%i==0)
    {
        ll a=i,b=x/i;
        if(__gcd(a,b)==1)
            return 0*printf("%lld %lld\n",a,b);
    }
    return 0;
}