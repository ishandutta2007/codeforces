#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int n;
    ll x,y;
    scanf("%d%I64d%I64d",&n,&x,&y);
    ll t=lcm(x,y);
    x=t/x,y=t/y;
    while(n--)
    {
        ll a;
        scanf("%I64d",&a);
        ll l=0,r=1000000000000000000LL;
        while(l<r)
        {
            ll m=(l+r)/2;
            if(a-m/x-m/y<=0)r=m;
            else l=m+1;
        }
        int ok=0;
        if(l%x==0)ok|=1;
        if(l%y==0)ok|=2;
        if(ok==1)printf("Vanya\n");
        else if(ok==2)printf("Vova\n");
        else printf("Both\n");
    }
    return 0;
}