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
	int n=read(),h=read(),a=read(),b=read(),q=read();
	for (int i=1;i<=q;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (x1==x2) print(abs(y1-y2));
		else if (y1>b&&y2>b) print(y1-b+y2-b+abs(x1-x2));
		else if (y1<a&&y2<a) print(a-y1+a-y2+abs(x1-x2));
		else print(abs(y1-y2)+abs(x1-x2));
	}

	return 0;
}