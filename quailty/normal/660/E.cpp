#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
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
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    ll res=(m==1 ? n+1 : ((m*fp(2*m-1,n)-fp(m,n))%Mod+Mod)*fp(m-1,Mod-2)%Mod);
    printf("%I64d",res);
    return 0;
}