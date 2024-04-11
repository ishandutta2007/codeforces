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

#define maxe 10000011
ll vis[maxe];
int main()
{
	ll n=read(),ans=INF,l=0,r=0;
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		if(vis[x]&&x<ans)
		{
			ans=x,l=vis[x],r=i;
		}
		vis[x]=i;
	}
	for(ll i=1;i<maxe;++i)//each gcd
	{
		if(i>=ans)break;
		ll flag=0;
		for(ll j=i;j<maxe;j+=i)//i,j
		{
			if(!vis[j])continue;
			if(!flag)flag=j;
			else
			{
				ll tmp=flag*j/i;
				if(tmp<ans)
				{
					ans=tmp,l=vis[flag],r=vis[j];
				}
			}
		}
	}
	
	if(l<r)std::cout<<l<<" "<<r;
	else std::cout<<r<<" "<<l;
	return 0;
}