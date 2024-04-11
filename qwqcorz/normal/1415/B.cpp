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
int a[N];

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),k=read(),ans=n;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=100;i++)
		{
			int now=0;
			for (int j=1;j<=n;j++)
			if (a[j]!=i)
			{
				j+=k-1;
				now++;
			}
			ans=min(ans,now);
		}
		print(ans);
	}

	return 0;
}