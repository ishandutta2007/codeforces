//Wan Hong 2.1
//notebook
#include<iostream>
#include<cstdio>
typedef long long ll;
typedef unsigned un;
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

ll n,a[111],ans=1;
void dfs(un l,un r)
{
	if(l==r)return;
	ll mid=(l+r)>>1;
	for(un i=l;i<r;++i)
	{
		if(a[i]>a[i+1])
		{
			dfs(l,mid);dfs(mid+1,r);
			return;
		}
	}
	if(r-l+1>ans)ans=r-l+1;
}
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	dfs(1,n);
	std::cout<<ans;
	return 0;
}