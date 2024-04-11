//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 200011
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read(),p=(n-1)/3,s=1,all=0;
        while(p>=s)
        {
            p-=s;s<<=2;
        }
        if(n%3==1)printf("%lld\n",s+p);
        else if(n%3==2)
        {
            ll ans=s<<1,c=1;
            while(p)
            {
                ll x=p%4;
                if(x==1)ans+=c*2;
                else if(x==2)ans+=c*3;
                else if(x==3)ans+=c;
                p>>=2,c<<=2;
            }
            printf("%lld\n",ans);
        }
        else
        {
            ll ans=s*3,c=1;
            while(p)
            {
                ll x=p%4;
                if(x==1)ans+=c*3;
                else if(x==2)ans+=c*1;
                else if(x==3)ans+=c*2;
                p>>=2,c<<=2;
            }
            printf("%lld\n",ans);
        }
        
    }
    return 0;
}