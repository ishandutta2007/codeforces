#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
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
    ll A,B,n,x;
    scanf("%I64d%I64d%I64d%I64d",&A,&B,&n,&x);
    if(A==1)printf("%I64d",(x+n%Mod*B)%Mod);
    else
    {
        ll res=fp(A,n)*x%Mod;
        res+=(fp(A,n)-1)*fp(A-1,Mod-2)%Mod*B;
        printf("%I64d",(res%Mod+Mod)%Mod);
    }
    return 0;
}