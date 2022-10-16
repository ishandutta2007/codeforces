#include <bits/stdc++.h>

using namespace std;
long long nzd(long long a,long long b)
{
    long long m = max(a,b);
    long long n = min(a,b);
    long long r=1;
    while(r!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
int main()
{
    long long a,b,x,y;
    scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
    long long c=nzd(x,y);
    x/=c;
    y/=c;
    printf("%lld\n",min(a/x,b/y));
    return 0;
}