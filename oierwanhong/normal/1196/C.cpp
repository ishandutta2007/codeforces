//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/

void work()
{
	ll n=read(),minx=-1e5,miny=-1e5,maxx=1e5,maxy=1e5;
	for(ll i=1;i<=n;++i)
	{
		ll x=read(),y=read();
		if(read()!=1ll)minx=max(minx,x);
		if(read()!=1ll)maxy=min(maxy,y);
		if(read()!=1ll)maxx=min(maxx,x);
		if(read()!=1ll)miny=max(miny,y);
	}
	if(maxx<minx||maxy<miny)printf("0\n");
	else printf("1 %lld %lld\n",maxx,maxy);
}
int main()
{
	ll q=read();
	while(q--)work();
	return 0;
}