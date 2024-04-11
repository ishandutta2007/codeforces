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
void write(ll x)
{
	if(x==0)
	{
		putchar('0');
		putchar(' ');
		return;
	}
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	ll a[21],top=0;
	while(x)
	{
		a[++top]=x%10;
		x/=10;
	}
	for(ll i=top;i>=1;--i)putchar(a[i]+'0');
	putchar(' ');
}

#define maxn 100001
struct node
{
	ll x,y;
	node(ll _x=0,ll _y=0)
	{
		x=_x,y=_y;
	}
	node operator +(const node &t)
	{
		node tmp;
		tmp.x=x+t.x;
		tmp.y=y+t.y;
		return tmp;
	}
	node operator *(const ll n)
	{
		return node(x*n,y*n);
	} 
	void in()
	{
		x=read();y=read();
	}
}a[maxn],s,t,sum[maxn];
ll n;

bool check(unsigned long long k)//arrive in k days
{
	node tmp=sum[n]*(k/n)+sum[k%n]+s;
	tmp.x=t.x-tmp.x;
	tmp.y=t.y-tmp.y;
	if(tmp.x<0)tmp.x=-tmp.x;
	if(tmp.y<0)tmp.y=-tmp.y;
	return tmp.x+tmp.y<=k;
}
int main()
{
	s.in();t.in();
	n=read();
	sum[0]=node(0,0);
	for(ll i=1;i<=n;++i)
	{
		char c=getchar();
		switch(c)
		{
			case 'U':sum[i]=node(0,1)+sum[i-1];break;
			case 'D':sum[i]=node(0,-1)+sum[i-1];break;
			case 'L':sum[i]=node(-1,0)+sum[i-1];break;
			case 'R':sum[i]=node(1,0)+sum[i-1];break;
		}
	}
	unsigned long long l=1,r=(1ull<<63),mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(r==(1ull<<63))write(-1);
	else write(r);
	return 0;
}