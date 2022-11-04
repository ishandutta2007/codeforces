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
    scanf("%lld%lld",&n,&k);
    vector<ll>fac;
    for(ll i=1;i*i<=n;i++)
        if(n%i==0)
        {
            fac.push_back(i);
            if(i*i!=n)fac.push_back(n/i);
        }
    sort(fac.begin(),fac.end());
    if((ll)fac.size()<k)printf("-1");
    else printf("%lld",fac[k-1]);
    return 0;
}