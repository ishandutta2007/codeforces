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
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    n--,k--;
    ll l=0,r=k+1;
    while(l<r)
    {
        ll m=(l+r+1)/2;
        if((k+1)*k/2-m*(m-1)/2>=n)l=m;
        else r=m-1;
    }
    printf("%I64d",(l ? k-l+1 : -1));
    return 0;
}