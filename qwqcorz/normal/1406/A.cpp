#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
		int n=read();
		for (int i=0;i<=101;i++) a[i]=0;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			a[x]++;
		}
		int ans=0;
		for (int i=0;i<=101;i++)
		if (a[i]==0)
		{
			ans+=i;
			break;
		}
		for (int i=0;i<=101;i++)
		if (a[i]<=1)
		{
			ans+=i;
			break;
		}
		print(ans);
	}

	return 0;
}