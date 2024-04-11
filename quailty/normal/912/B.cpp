#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(k==1)printf("%lld\n",n);
    else
    {
        ll r=0;
        while(n)n>>=1,r=r<<1|1;
        printf("%lld\n",r);
    }
    return 0;
}