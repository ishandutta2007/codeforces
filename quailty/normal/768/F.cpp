#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int Mod=1000000007;
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
ll fac[MAXN],inv[MAXN];
void build()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=fac[i-1]*i%Mod;
    inv[MAXN-1]=fp(fac[MAXN-1],Mod-2);
    for(int i=MAXN-2;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%Mod;
}
ll C(ll n,ll m)
{
    if(n<m)return 0;
    return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main()
{
    build();
    ll f,w,h;
    scanf("%lld%lld%lld",&f,&w,&h);
    if(w==0)return 0*printf("1");
    ll p=0,q=0;
    for(int i=1;i<=w;i++)
    {
        q=(q+C(w-1,i-1)*C(f+1,i))%Mod;
        p=(p+C(w-1-i*h,i-1)*C(f+1,i))%Mod;
    }
    return 0*printf("%lld",p*fp(q,Mod-2)%Mod);
}