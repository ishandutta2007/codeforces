#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cal(ll t)
{
    ll res=0;
    for(ll i=2;i*i*i<=t;i++)
        res+=t/(i*i*i);
    return res;
}
int main()
{
    ll t;
    scanf("%I64d",&t);
    ll l=0LL,r=9000000000000000000LL;
    while(l<r)
    {
        ll m=l+(r-l)/2;
        if(cal(m)<t)l=m+1;
        else r=m;
    }
    printf("%I64d",(cal(l)==t ? l : -1));
    return 0;
}