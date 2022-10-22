//LG send again
//Wan Hong 2.1
//notebook
#include<iostream>
#include<cstdio>
typedef long long ll;
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

ll a,b,c,ans=0,t=0;
ll fa[8]={1,0,0,1,0,0,1},fb[8]={0,1,0,0,0,1,0},fc[8]={0,0,1,0,1,0,0};
ll sa=3,sb=2,sc=2;
int main()
{
	a=read(),b=read(),c=read();
	ans=min(a/sa,min(b/sb,c/sc));
	for(ll i=0;i<7;++i)
	{
		ll tmp=0,ta=a-sa*ans,tb=b-sb*ans,tc=c-sc*ans,it=i;
		while(1)
		{
			if(fa[it])
			{
				if(ta)--ta;
				else break;
			}
			else if(fb[it])
			{
				if(tb)--tb;
				else break;
			}
			else if(fc[it])
			{
				if(tc)--tc;
				else break;
			}
			it=(it+1)%7;++tmp;
		}
		t=max(t,tmp);
	}
	std::cout<<ans*7+t;
	return 0;
}