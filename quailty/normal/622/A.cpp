#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    scanf("%I64d",&n);
    ll l=1,r=1000000000;
    while(l<r)
    {
        ll m=(l+r+1)>>1;
        if(m*(m-1)/2>=n)r=m-1;
        else l=m;
    }
    printf("%I64d\n",n-l*(l-1)/2);
    return 0;
}