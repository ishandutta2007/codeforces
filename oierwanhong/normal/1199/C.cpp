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
#define MAXN 400011
struct one
{
	ll v,num,rk;
}a[MAXN];
bool cmp1(one a,one b)
{
	return a.v<b.v;
}
bool cmp2(one a,one b)
{
	return a.num<b.num;
}
ll w[MAXN],s[MAXN];
int main()
{
	ll n=read(),I=read()*8;
	for(ll i=1;i<=n;++i)
	{
		a[i].v=read();
		a[i].num=i;
	}
	std::sort(a+1,a+n+1,cmp1);
	ll cnt=1;
	a[1].rk=1;w[1]=1;
	for(ll i=2;i<=n;++i)
	{
		if(a[i].v!=a[i-1].v)++cnt;
		a[i].rk=cnt;
		++w[cnt];
	}
	for(ll i=1;i<=cnt;++i)
		s[i]=s[i-1]+w[i];
	ll ans=INF,t=I/n,size=(1<<t);
	if(t>=22||size>=cnt)
	{
		printf("0");
		return 0;
	}
	for(ll i=1;i<=cnt&&i+size-1<=cnt;++i)
	{
		ans=min(ans,s[i-1]+(s[cnt]-s[i+size-1]));
	}
	printf("%lld",ans);
	return 0;
}