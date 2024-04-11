#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
ll phi(ll x)
{
    ll t=x;
    for(ll i=2;i*i<=t;i++)
        if(t%i==0)
        {
            x=x/i*(i-1);
            while(t%i==0)t/=i;
        }
    if(t>1)x=x/t*(t-1);
    return x;
}
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    while(n>1 && k>0)
    {
        if(k&1)n=phi(n);
        k--;
    }
    return 0*printf("%lld",n%Mod);
}