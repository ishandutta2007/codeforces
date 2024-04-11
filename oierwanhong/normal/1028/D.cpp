//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
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
std::set<ll>buy,sell,unknown;
const ll mod=ll(1e9+7);
char a[10];
int main()
{
    ll t=read(),ans=1;
    while(t--)
    {
        scanf("%s",a);
        ll x=read();
        if(a[1]=='D')
        {
            if(!buy.empty()&&((-*buy.begin())>x))buy.insert(-x);
            else if(!sell.empty()&&(*sell.begin())<x)sell.insert(x);
            else unknown.insert(x);
        }
        else
        {
            if(buy.count(-x))
            {
                if((-*buy.begin())!=x){puts("0");return 0;}
                for(auto y:unknown)sell.insert(y);
                unknown.clear();
                buy.erase(-x);
            }
            else if(unknown.count(x))
            {
                for(auto y:unknown)
                    if(y<x)buy.insert(-y);
                    else if(y>x)sell.insert(y);
                unknown.clear();
                ans=(ans<<1)%mod;
            }
            else if(sell.count(x))
            {
                if((*sell.begin())!=x){puts("0");return 0;}
                for(auto y:unknown)buy.insert(-y);
                unknown.clear();
                sell.erase(x);
            }
            else{puts("0");return 0;}
        }
    }
    if(!unknown.empty())ans=(ans*(unknown.size()+1))%mod;
    printf("%lld",ans);
    return 0;
}