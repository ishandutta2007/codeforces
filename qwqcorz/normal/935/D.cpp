#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int p=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=ret*a%p;
		a=a*a%p;
		b/=2;
	}
	return ret;
}
int a[N],b[N],sum[N];

signed main()
{
	memset(sum,0,sizeof(sum));
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	for (int i=n;i>=1;i--)
	{
		sum[i]=sum[i+1];
		sum[i]+=!a[i];
		sum[i]+=!b[i];
	}
	int mul=1;
	for (int i=1;i<=n;i++)
	{
		int tot=0;
		if (a[i]&&b[i]) tot=a[i]>b[i];
		if (a[i]&&!b[i]) tot=a[i]-1;
		if (!a[i]&&b[i]) tot=m-b[i];
		if (!a[i]&&!b[i]) tot=m*(m-1)/2%p;
		ans+=tot*power(m,sum[i+1])%p*mul%p;
		if (ans>=p) ans-=p;
		if (!a[i]&&!b[i]) mul=mul*m%p;
		if (a[i]&&b[i]&&a[i]!=b[i]) break;
	}
	print(ans*power(power(m,sum[1]),p-2)%p);

	return 0;
}