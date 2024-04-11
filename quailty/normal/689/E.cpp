#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll Mod=1000000007;
ll fp(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1)(res*=a)%=Mod;
        (a*=a)%=Mod;
        k>>=1;
    }
    return res;
}
ll f[MAXN];
ll C(ll n,ll k)
{
    if(k>n)return 0;
    return f[n]*fp(f[k],Mod-2)%Mod*fp(f[n-k],Mod-2)%Mod;
}
struct Event
{
    ll x,v;
    Event(){}
    Event(ll _x,ll _v):x(_x),v(_v){}
    bool operator < (const Event &t)const
    {
        return x<t.x;
    }
}e[MAXN<<1];
int main()
{
    for(int i=(f[0]=1);i<MAXN;i++)
        f[i]=i*f[i-1]%Mod;
    int n,k,tot=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        ll l,r;
        scanf("%I64d%I64d",&l,&r);
        e[tot++]=Event(l-1,1);
        e[tot++]=Event(r,-1);
    }
    sort(e,e+tot);
    ll res=0,cnt=0,la=-2000000000;
    for(int i=0;i<tot;i++)
    {
        res=(res+C(cnt,k)*(e[i].x-la))%Mod;
        la=e[i].x;
        cnt+=e[i].v;
    }
    return 0*printf("%I64d\n",res);
}