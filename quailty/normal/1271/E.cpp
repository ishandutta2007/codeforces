#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll n,ll x)
{
    ll res=0,l=x,r=x+(~x&1);
    while(l<=n)
    {
        res+=min(r,n)-l+1;
        l<<=1,(r<<=1)|=1;
    }
    return res;
}
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll l=0,r=(n-1)/2;
    while(l<r)
    {
        ll m=(l+r+1)/2;
        if(cal(n,2*m+1)>=k)l=m;
        else r=m-1;
    }
    ll res=2*l+1;
    l=0,r=n/2;
    while(l<r)
    {
        ll m=(l+r+1)/2;
        if(cal(n,2*m)>=k)l=m;
        else r=m-1;
    }
    res=max(res,2*l);
    return 0*printf("%lld\n",res);
}