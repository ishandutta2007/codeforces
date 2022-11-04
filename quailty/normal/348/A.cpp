#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
ll a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    ll tot=0,ma=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64u",&a[i]);
        tot+=a[i];
        ma=max(ma,a[i]);
    }
    ll l=ma,r=tot;
    while(l<r)
    {
        ll m=(l+r)>>1;
        if(m<=n*m-tot)r=m;
        else l=m+1;
    }
    printf("%I64u\n",l);
    return 0;
}