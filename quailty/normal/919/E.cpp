#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fp(ll a,ll k,ll m)
{
    ll res=1;
    while(k)
    {
        if(k&1)res=res*a%m;
        a=a*a%m;
        k>>=1;
    }
    return res;
}
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(a==0 && b==0)return -1;
    if(b==0)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
bool solve(ll &m0,ll &a0,ll m,ll a)
{
    ll x,y,g=exgcd(m0,m,x,y);
    if(abs(a-a0)%g)return 0;
    x*=(a-a0)/g;
    x%=m/g;
    a0=(x*m0+a0);
    m0*=m/g;
    a0%=m0;
    if(a0<0)a0+=m0;
    return 1;
}
int main()
{
    ll a,b,p,x,res=0;
    scanf("%lld%lld%lld%lld",&a,&b,&p,&x);
    for(ll i=0,t=1;i<p-1;i++)
    {
        ll d=p-1,r=i;
        solve(d,r,p,b*fp(t,p-2,p)%p);
        res+=(x+d-r)/d;
        t=t*a%p;
    }
    return 0*printf("%lld\n",res);
}