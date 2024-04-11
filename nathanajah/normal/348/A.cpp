#include <stdio.h>
#define LL long long
using namespace std;


LL n;
LL arr[1000005];
LL i;
LL l,mid,r;


bool cek(LL x)
{
    LL total=0;
    LL i;
    for (i=0;i<n;++i)
    {
        if (x<arr[i])
            return false;
        total+=(x-arr[i]);
    }
    if (total>=x)
        return true;
    return false;
}
int main()
{
    scanf("%I64d",&n);
    for (i=0;i<n;++i)
        scanf("%I64d",&arr[i]);
    l=0;
    r=1000000000000LL;
    mid=(l+r)/2;
    while (l<r)
    {
        if (cek(mid))
        {
            r=mid;
            mid=(l+r)/2;
        }
        else
        {
            l=mid+1;
            mid=(l+r+1)/2;
        }
    }
    printf("%I64d\n",l);
}