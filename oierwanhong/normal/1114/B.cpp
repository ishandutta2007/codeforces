#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
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
void write(ll x)
{
	if(x==0)
	{
		putchar('0');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	ll s[21],top=0;
	while(x)
	{
		s[++top]=x%10;
		x/=10;
	}
	for(ll i=top;i>=1;--i)putchar(s[i]+'0');
}


#define maxn 200010
struct one
{
	ll v,dex;
	bool flag;
	bool operator <(const one &t)
	const
	{
		return v>t.v;
	}
}a[maxn];
ll n,m,k;


bool cmp(one a,one b)
{
	return a.dex<b.dex;
}
int main()
{
	n=read(),m=read(),k=read();
	for(ll i=1;i<=n;++i)
	{
		a[i].v=read();
		a[i].dex=i;
		a[i].flag=0;
	}
	std::sort(a+1,a+n+1);
	ll sum=0;
	for(ll i=1;i<=m*k;++i)
		sum+=a[i].v,a[i].flag=1;
	write(sum);putchar('\n');
	
	std::sort(a+1,a+n+1,cmp);
	ll cnt1=0,cnt2=0;
	for(ll i=1;i<=n;++i)
	{
		if(a[i].flag&&cnt2<k-1)
		{
			++cnt1;
			if(cnt1==m)
			{
				write(i);putchar(' ');
				cnt1=0;
				++cnt2;
			}
		}
	}
	
	return 0;
}