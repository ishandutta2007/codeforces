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
#define MAXN 100011
ll c[MAXN];
void work()
{
	memset(c,0,sizeof c);
	ll n=read(),s=0;
	for(ll i=1;i<=n;++i)++c[read()];
	for(ll i=MAXN-1;i;--i)
	{
		s+=c[i];
		if(s>=2)
		{
			std::cout<<min(i-1,n-2)<<std::endl;
			return;
		}
	}
}
int main()
{
	ll t=read();
	while(t--)work();
	return 0;
}