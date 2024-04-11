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
int n;
inline int nxt(int x)
{
	if (n&1)
	{
		if (x==n+2) return 2;
			   else return 1;
	}
	else
	{
		if (x==n+2) return 1;
			   else return 2;
	}
}

signed main()
{
	n=read();
	int x1=1,y1=1;
	int x2=1,y2=2;
	while (x1<=n&&x2<=n)
	{
		int a=read();
		if (a>1)
		{
			print(1,' ');
			print(x1,' ');
			print(y1);
			fflush(stdout);
			y1+=2;
			if (y1>n) y1=nxt(y1),x1++;
		}
		else
		{
			print(2,' ');
			print(x2,' ');
			print(y2);
			fflush(stdout);
			y2+=2;
			if (y2>n) y2=nxt(y2),x2++;
		}
	}
	while (x1<=n)
	{
		int a=read();
		print(a==1?3:1,' ');
		print(x1,' ');
		print(y1);
		fflush(stdout);
		y1+=2;
		if (y1>n) y1=nxt(y1),x1++;
	}
	while (x2<=n)
	{
		int a=read();
		print(a==2?3:2,' ');
		print(x2,' ');
		print(y2);
		fflush(stdout);
		y2+=2;
		if (y2>n) y2=nxt(y2),x2++;
	}
	
	return 0;
}