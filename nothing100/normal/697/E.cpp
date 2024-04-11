#include<cstdio>
#include<algorithm>
#include<cstring>
#define mo 1000000007
using namespace std;
int n,bo;
long long m,tmp,tmpp;
long long ksm(long long x,long long y)
{
    long long a,b;
    a=1;
    b=x;
    while (y)
    {
        if (y&1==1) a=(a*b)%mo;
        b=(b*b)%mo;
        y=y/2;
    }
    return a;
}
int main()
{
    scanf("%d",&n);
    tmp=2;
    for (int i=0;i<n;i++)
    {
        scanf("%I64d",&m);
        if (m%2==0) bo=1;
        tmp=ksm(tmp,m);
    }
    tmp=(tmp*ksm(2,mo-2))%mo;
    if (bo) tmpp=(tmp+1)%mo;
    else tmpp=(tmp-1)%mo;
    tmpp=(tmpp*ksm(3,mo-2))%mo;
    printf("%I64d/%I64d",tmpp,tmp);
    return 0;
}