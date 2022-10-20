#include<bits/stdc++.h>
using namespace std;

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
	while (c!='0'&&c!='1') c=getchar();
	return c-'0';
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),c0=read(),c1=read(),h=read(),ans=0;
		for (int i=1;i<=n;i++)
		{
			bool x=get();
			if (x==0) ans+=min(c0,c1+h);
			if (x==1) ans+=min(c1,c0+h);
		}
		print(ans);
	}

	return 0;
}