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
	int n=read(),m=read(),x1=0,y1=0,x2=0,y2=0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		char c;
		cin>>c;
		if (c=='B')
		{
			if (!x1) x1=i,y1=j;
			x2=i,y2=j;
		}
	}
	print((x1+x2)/2,' ');
	print((y1+y2)/2);
	
	return 0;
}