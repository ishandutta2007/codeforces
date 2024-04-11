//Wan Hong 2.1
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

#define maxn 200011
ll l[maxn],r[maxn],vis[maxn];
struct one
{
	ll v,num;
	bool operator <(const one &t)
	const
	{
		return v<t.v;
	}
}a[maxn];
int main()
{
	ll n=read(),k=read();
	for(ll i=1;i<=n;++i)
	{
		a[i].v=read(),a[i].num=i;
		l[i]=i-1,r[i]=i+1;
	}
	l[0]=r[n]=0;
	std::sort(a+1,a+n+1);
	ll it=n;
	bool p=0;
	for(;it>0;--it)
	{
		if(vis[a[it].num])continue;
		ll tmp=k,pos=l[a[it].num];
		while(tmp)
		{
			if(!pos)break;
			vis[pos]=p+1;
			if(l[pos])r[l[pos]]=r[pos];
			if(r[pos])l[r[pos]]=l[pos];
			pos=l[pos];
			--tmp;
		}
		tmp=k,pos=r[a[it].num];
		while(tmp)
		{
			if(!pos)break;
			vis[pos]=p+1;
			if(l[pos])r[l[pos]]=r[pos];
			if(r[pos])l[r[pos]]=l[pos];
			pos=r[pos];
			--tmp;
		}
		pos=a[it].num;
		vis[pos]=p+1;
		if(l[pos])r[l[pos]]=r[pos];
		if(r[pos])l[r[pos]]=l[pos];
		p=!p;
	}
	for(ll i=1;i<=n;++i)
		putchar(vis[i]+'0');
	return 0; 
}