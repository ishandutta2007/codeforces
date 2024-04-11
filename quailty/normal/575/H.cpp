#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007LL;
ll f[2000010];
void build()
{
    f[0]=1LL;
    for(int i=1;i<=2000005;i++)
        f[i]=i*f[i-1]%Mod;
}
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
ll C(int n,int k)
{
    if(k>n)return 0LL;
    return f[n]*fp(f[k],Mod-2)%Mod*fp(f[n-k],Mod-2)%Mod;
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    n++;
    ll ans=(2*C(2*n-1,n)+Mod-1)%Mod;
    printf("%I64d\n",ans);
}