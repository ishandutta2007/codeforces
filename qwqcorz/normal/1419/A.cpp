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

signed main()
{
	int T=read();
	while (T--)
	{
		bool flag=0;
		int n=read();
		for (int i=1;i<=n;i++)
		{
			char c=getchar();
			while (c<'0'||'9'<c) c=getchar();
			int x=c-'0';
			if (n&1)
			{
				if (i%2==1) flag|=x&1;
			} 
			else
			{
				if (i%2==0) flag|=!(x&1);
			} 
		}
		if (n&1)
		{
			if (flag) puts("1");
				 else puts("2");
		}
		else
		{
			if (flag) puts("2");
				 else puts("1");
		}
	}

	return 0;
}