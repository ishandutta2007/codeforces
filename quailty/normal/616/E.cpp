#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007LL;
const ll Inv=500000004LL;
ll rat(ll n)
{
    n%=Mod;
    return n*(n+1)%Mod*Inv%Mod;
}
int main()
{
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    ll res=n%Mod*(m%Mod)%Mod,t=0;
    m=min(n,m);
    for(t=1;t<=m && t*t<=n;t++)
        res=(res-(n/t)%Mod*t)%Mod;
    for(ll i=n/t;i>=n/m;i--)
        res=(res-(rat(min(m,n/i))-rat(n/(i+1)))*i)%Mod;
    printf("%I64d\n",(res+Mod)%Mod);
    return 0;
}