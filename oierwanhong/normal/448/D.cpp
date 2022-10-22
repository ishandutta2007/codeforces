#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll INF=0x7fffffff;
ll a[1000001];
ll n,m,k;
bool check(ll p)
{
    ll s=1,e=m,sum=0;
    while(s<=n&&e>=1)
    {
        if(s*e>p)
        {
            e--;
        }
        else
        {
            sum+=e;
            s++;
        }
    }
    return sum>=k;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    ll l=1,r=n*m,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld",r);
    return 0;
}