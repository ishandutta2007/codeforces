//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
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
#define MAXN 400011
char a[MAXN];
ll sr[MAXN],sc[MAXN];
void work()
{
	ll n=read(),m=read();
	for(ll i=1;i<=n;++i)
	{
		sr[i]=0;
		char c=getchar();
		while(c!='.'&&c!='*')c=getchar();
		for(ll j=1;j<=m;++j)
		{
			if(c=='*')++sr[i];
			a[i*m+j]=c;
			c=getchar();
		}
		sr[i]=m-sr[i];
	}
	for(ll j=1;j<=m;++j)
	{
		sc[j]=0;
		for(ll i=1;i<=n;++i)
		{
			if(a[i*m+j]=='*')++sc[j];
		}
		sc[j]=n-sc[j];
	}
	ll ans=n*m;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
		{
			ll k=sr[i]+sc[j];
			if(a[i*m+j]=='.')--k;
			ans=min(ans,k);
		}
	std::cout<<ans<<std::endl;
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}