#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll n,ll k)
{
    ll res=0;
    while(n)
    {
        res+=min(n,k);
        n-=min(n,k);
        n-=n/10;
    }
    return res;
}
int main()
{
    ll n;
    scanf("%lld",&n);
    ll tl=1,tr=n;
    while(tl<tr)
    {
        ll tm=(tl+tr)/2;
        if(cal(n,tm)>=(n+1)/2)tr=tm;
        else tl=tm+1;
    }
    return 0*printf("%lld\n",tl);
}