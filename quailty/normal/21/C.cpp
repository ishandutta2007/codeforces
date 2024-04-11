#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        sum+=a[i];
    }
    ll now=0,rhs=0,tot=0;
    for(int i=1;i<n;i++)
    {
        now+=a[i];
        rhs+=(3*now==2*sum);
    }
    now=0;
    for(int i=1;i<=n;i++)
    {
        now+=a[i];
        if(i<n)rhs-=(3*now==2*sum);
        tot+=rhs*(3*now==sum);
    }
    printf("%I64d",tot);
    return 0;
}