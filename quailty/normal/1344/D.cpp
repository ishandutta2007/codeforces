#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
ll a[MAXN],b[MAXN];
ll cal(int n,ll d)
{
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        ll l=0,r=a[i];
        while(l<r)
        {
            ll m=l+(r-l+1)/2;
            if(a[i]-(3*m*m-3*m+1)>=d)l=m;
            else r=m-1;
        }
        sum+=(b[i]=l);
    }
    return sum;
}
int main()
{
    int n;
    ll k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ll l=-4e18,r=4e18;
    while(l<r)
    {
        ll m=l+(r-l+1)/2;
        if(cal(n,m)>=k)l=m;
        else r=m-1;
    }
    k-=cal(n,l);
    for(int i=1;i<=n && k<0;i++)
        if(b[i] && a[i]-(3*b[i]*b[i]-3*b[i]+1)==l)
            b[i]--,k++;
    for(int i=1;i<=n;i++)
        printf("%lld%c",b[i]," \n"[i==n]);
    return 0;
}