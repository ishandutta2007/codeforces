#include<bits/stdc++.h>
#define int long long
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
		int x=read(),y=read(),ans=0;
		if (x%y>0) print(x);
		else
		{
			int s=sqrt(y),tmpy=y,tmpx;
			for (int i=2;i<=s;i++)
			if (tmpy%i==0)
			{
				while (tmpy%i==0) tmpy/=i;
				tmpx=x;
				while (tmpx%y==0) tmpx/=i;
				ans=max(ans,tmpx);
			}
			if (tmpy>1)
			{
				tmpx=x;
				while (tmpx%y==0) tmpx/=tmpy;
				ans=max(ans,tmpx);
			}
			print(ans);
		}
	}

	return 0;
}