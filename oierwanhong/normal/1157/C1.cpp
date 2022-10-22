//Wan Hong 2.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
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

#define maxn 200011
char ans[maxn];
ll n,a[maxn],len=0,t=0;
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	ll l=1,r=n;
	while(l<=r)
	{
		if((a[r]<=t||a[l]<=a[r])&&t<a[l])ans[len++]='L',t=a[l++];
		else if((a[l]<=t||a[r]<=a[l])&&t<a[r])ans[len++]='R',t=a[r--];
		else break;
	}
	std::cout<<len<<std::endl<<ans;
	return 0;
}