#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k,m,d,res=0;
    scanf("%lld%lld%lld%lld",&n,&k,&m,&d);
    for(ll i=1;i<=d;i++)
    {
        ll tl=1,tr=m;
        while(tl<tr)
        {
            ll tm=(tl+tr+1)/2;
            if(((n/tm)+k-1)/k<i)tr=tm-1;
            else tl=tm;
        }
        if(((n/tl)+k-1)/k==i)
            res=max(res,((n/tl)+k-1)/k*tl);
    }
    printf("%lld\n",res);
    return 0;
}