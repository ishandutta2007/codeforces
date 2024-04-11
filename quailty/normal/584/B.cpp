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
    int n;
    scanf("%d",&n);
    printf("%I64d\n",(fp(27,n)-fp(7,n)+Mod)%Mod);
    return 0;
}