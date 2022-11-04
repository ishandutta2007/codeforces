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
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    ll tl=1,tr=n*m;
    while(tl<tr)
    {
        ll tm=(tl+tr)/2,cnt=0;
        for(int i=1;i<=n;i++)
            cnt+=min(tm/i,m);
        if(cnt<k)tl=tm+1;
        else tr=tm;
    }
    return 0*printf("%lld",tl);
}