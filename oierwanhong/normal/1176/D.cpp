//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<algorithm>
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
#define MAXN 2750131+11
ll p[MAXN],t[MAXN],a[MAXN],c[MAXN];
bool vis[MAXN];
void o_prime()
{
	ll cnt=0;
	for(ll i=2;i<MAXN;++i)
	{
		if(!vis[i])p[++cnt]=i,t[i]=cnt;
		for(ll j=1;j<=cnt;++j)
		{
			if(i*p[j]>=MAXN)break;
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	o_prime();
	/*
	for(ll i=2;i<=100;++i)
		if(!vis[i])std::cout<<i<<" ";
	*/
	ll n=read();
	for(ll i=1;i<=(n<<1);++i)
	{
		a[i]=read();
		++c[a[i]];
	}
	std::sort(a+1,a+(n<<1)+1,cmp);
	for(ll i=1;i<=(n<<1);++i)
	{
		if(!c[a[i]])continue;
		if(!vis[a[i]])
		{
			if(!c[t[a[i]]])continue;
			std::cout<<t[a[i]]<<" ";
			--c[a[i]];--c[t[a[i]]];
		}
		else
		{
			ll k=-1;
			for(ll j=1;p[j]*p[j]<=a[i];++j)
				if(a[i]%p[j]==0)
				{
					k=a[i]/p[j];break;
				}
			if(k==-1||!c[k])continue;
			std::cout<<a[i]<<" ";
			--c[a[i]];--c[k];
		}
	}
	return 0;
}
/*
hack:3
5 5 10 11 22 11
*/