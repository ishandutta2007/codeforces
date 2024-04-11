//Wan Hong 3.1
//Online IDE
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::pair<ll,ll> pll;
#define INF (1ll<<58)
ll read()
{
    ll f=1,x=0;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
ll max(ll a,ll b)
{
    return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}
bool umax(ll& a,ll b)
{
    if(b>a)return a=b,1;
    return 0;
}
bool umin(ll& a,ll b)
{
    if(b<a)return a=b,1;
    return 0;
}
ll abs(ll x)
{
    return x>0?x:-x;
}

/**********/
#define MAXN 200011
ll c[5];
const ll mx[4]={-1,0,1,0},my[4]={0,-1,0,1};
int main()
{
    ll n=read(),sx=read(),sy=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read(),y=read();
        if(x<sx)++c[0];
        if(x>sx)++c[2];
        if(y<sy)++c[1];
        if(y>sy)++c[3];
    }
    ll res=0;
    for(ll op=0;op<4;++op)umax(res,c[op]);
    for(ll op=0;op<4;++op)
        if(res==c[op])
        {
            printf("%lld\n",res);
            printf("%lld %lld",sx+mx[op],sy+my[op]);
            return 0;
        }
    return 0;
}