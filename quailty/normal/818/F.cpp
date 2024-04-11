#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        ll l=0,r=2LL*(n-1);
        while(l<r)
        {
            ll m=l+(r-l+1)/2,c=(m+1)/2;
            if((n-c)*(n-c-1)/2+c>=m)l=m;
            else r=m-1;
        }
        printf("%lld\n",l);
    }
    return 0;
}