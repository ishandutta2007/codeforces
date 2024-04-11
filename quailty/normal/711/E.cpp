#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000003;
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
pair<ll,ll> cal(ll k,ll n)
{
    if(!k)return make_pair(0,1);
    ll p=0,r=1,t=fp(2,n);
    for(int i=1;i<2*Mod;i+=2)
        r=1LL*r*(t-i+2*Mod)%Mod;
    r=fp(r,k/(2*Mod));
    for(int i=1;i<=k%(2*Mod);i+=2)
        r=1LL*r*(t-i+2*Mod)%Mod;
    pair<ll,ll>tmp=cal(k/2,n-1);
    p=(k/2+tmp.first)%(Mod-1);
    r=1LL*r*tmp.second%Mod;
    return make_pair(p,r);
}
int main()
{
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    ll lk=0;
    while((1LL<<lk)<k)lk++;
    if(lk>n)return 0*printf("1 1\n");
    pair<ll,ll>res=cal(k-1,n);
    ll p=((n%(Mod-1))*((k-1)%(Mod-1))%(Mod-1)-res.first+(Mod-1))%(Mod-1);
    ll A=res.second,B=fp(2,p);
    printf("%I64d %I64d\n",(B-A+Mod)%Mod,B);
    return 0;
}