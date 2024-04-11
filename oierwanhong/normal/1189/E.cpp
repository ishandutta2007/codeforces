//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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

/**********/
#define MAXN 300011
ll n,p,k;
struct moder
{
	ll v;
	moder(ll x=0)
	{
		v=x;
	}
	void operator =(ll x)
	{
		v=x;
	}
	ll operator -(ll x)
	{
		return (v-x+p)%p;
	}
	ll operator *(ll x)
	{
		return v*x%p;
	}
	ll operator ^(ll x)
	{
		ll res=1,t=v;
		while(x)
		{
			if(x&1)res=(res*t)%p;
			t=(t*t)%p;
			x>>=1;
		}
		return res;
	}
}x;
/*(ai+aj)*(ai*ai+aj*aj)==k(mod p)
	(ai*ai-aj*aj)*(ai*ai+aj*aj)==k*(ai-aj)
	ai^4-aj^4==k(ai-aj)
	ai^4-kai=aj^4-kaj
*/
std::map<ll,ll>r;
int main()
{
	n=read(),p=read(),k=read();
	ll ans=0;
	for(ll i=1;i<=n;++i)
	{
		x=read();
		ll v=moder(x^4)-x*k;
		ans+=r[v];
		++r[v];
	}
	std::cout<<ans;
	return 0;
}