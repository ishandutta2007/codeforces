#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int inf=1ll<<60;

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
bool get()
{
	char c=getchar();
	while (c<'0'||'1'<c) c=getchar();
	return c-'0';
}
int a[N],sum[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),p=read(),k=read(),ans=inf;
		for (int i=1;i<=n;i++) a[i]=get();
		for (int i=1;i<=n;i++)
		{
			sum[i]=!a[i];
			if (i>=k) sum[i]+=sum[i-k];
		}
		for (int i=n+1;i<=n*2;i++) sum[i]=sum[i-k];
		int x=read(),y=read(),ed=p;
		while (ed+k<=n) ed+=k;
		for (int i=0;i<=n-p;i++)
		{
			ans=min(ans,x*(sum[ed+i]-sum[max(p+i-k,0ll)])+y*i);
//			print(sum[ed+i]-sum[max(p+i-k,0ll)]);
		}
		print(ans);
	}

	return 0;
}