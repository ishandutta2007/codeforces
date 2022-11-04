#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007LL;
ll fp(ll a,ll k)
{
    ll res=1LL;
    while(k)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
int main()
{
    int p,k;
    scanf("%d%d",&p,&k);
    if(k==0)
        printf("%I64d\n",fp(p,p-1));
    else if(k==1)
        printf("%I64d\n",fp(p,p));
    else
    {
        int r=0;
        ll now=1LL;
        for(r=1;r<=p;r++)
        {
            now=now*k%p;
            if(now==1)break;
        }
        printf("%I64d\n",fp(p,(p-1)/r));
    }
    return 0;
}