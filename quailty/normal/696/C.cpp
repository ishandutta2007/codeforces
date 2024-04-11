#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
ll fp(ll a,ll k)
{
    ll res=1;
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
    int k;
    scanf("%d",&k);
    ll n=1;
    for(int i=1;i<=k;i++)
    {
        ll a;
        scanf("%I64d",&a);
        (n*=(a%(Mod-1)))%=Mod-1;
    }
    n=(n+Mod-2)%(Mod-1);
    ll p=(fp(2,n)-fp(-1,n)+Mod)%Mod*fp(3,Mod-2)%Mod;
    ll q=fp(2,n);
    printf("%I64d/%I64d",p,q);
    return 0;
}