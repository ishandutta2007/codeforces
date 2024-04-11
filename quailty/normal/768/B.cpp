#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll cal(ll x,ll p)
{
    ll c=1,t=x/2;
    while(t)c<<=1,t>>=1;
    return (p==c ? x%2 : cal(x/2,p%c));
}
int main()
{
    ll n,l,r,res=0;
    scanf("%lld%lld%lld",&n,&l,&r);
    for(ll i=l;i<=r;i++)
        res+=cal(n,i);
    return 0*printf("%lld",res);
}