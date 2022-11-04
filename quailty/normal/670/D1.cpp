#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef double db;
typedef long long ll;
ll a[100005],b[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&b[i]);
    ll l=0,r=2000000000;
    while(l<r)
    {
        ll m=(l+r+1)>>1,tot=0;
        for(int i=1;i<=n && tot<=k;i++)
            tot+=max(0LL,a[i]*m-b[i]);
        if(tot>k)r=m-1;
        else l=m;
    }
    printf("%I64d",l);
    return 0;
}