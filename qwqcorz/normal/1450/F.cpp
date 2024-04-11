#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
int a[N],f[N],tot[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),cnt=0,Max=0,ck=0;
		for (int i=1;i<=n;i++) f[i]=tot[i]=0;
		for (int i=1;i<=n;i++) tot[a[i]=read()]++;
		for (int i=1;i<=n;i++) ck=max(ck,tot[i]);
		for (int i=2;i<=n;i++)
		if (a[i]==a[i-1])
		{
			cnt++;
			f[a[i-1]]++;
			f[a[i]]++;
		}
		f[a[1]]++;
		f[a[n]]++;
		for (int i=1;i<=n;i++) Max=max(Max,f[i]);
		if (ck>(n+1)/2) puts("-1");
				   else print(cnt+max(Max-cnt-2,0));
	}

	return 0;
}