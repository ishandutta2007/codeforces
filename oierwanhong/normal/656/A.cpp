#include<iostream>
#include<cstdio>
typedef long long ll;
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
	ll s[21],top=0;
	while(x)
	{
		s[++top]=x%10;
		x/=10;
	}
	for(ll i=top;i>=1;--i)putchar(s[i]+'0');
	putchar(' ');
}

ll a[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8092,
 16184, 32368, 64736, 129472, 258944, 517888, 1035776, 2071552, 4143104,
  8286208, 16572416, 33144832, 66289664, 132579328, 265158656, 530317312,
   1060634624, 2121269248, 4242538496, 8485076992, 16970153984, 33940307968};
int main()
{
	write(a[read()]);
	return 0;
}