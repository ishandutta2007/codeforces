//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
str s,a,b;
int main()
{
    ll t=read();
    while(t--)
    {
        ll n=read();std::cin>>s;
        bool flag=0;
        a="",b="";
        for(ll i=0;i<n;++i)
            if(s[i]=='2')a+="1",b+="1";
            else if(s[i]=='1')
            {
                std::cout<<a<<"1";for(ll j=i+1;j<n;++j)std::cout<<"0";
                std::cout<<'\n'<<b<<"0";
                if(i+1<n)std::cout<<s.substr(i+1);
                flag=1;
                break;
            }
            else a+="0",b+="0";
        if(flag)putchar('\n');
        else std::cout<<a<<'\n'<<b<<'\n';
    }
    return 0;
}