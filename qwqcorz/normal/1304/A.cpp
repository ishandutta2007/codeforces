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

int main()
{
	int T=read();
	while (T--)
	{
		int x=read(),y=read(),a=read(),b=read();
		int ans=(y-x)/(a+b);
		int xx=x+ans*a,yy=y-ans*b;
		if (xx==yy) print(ans);
			   else print(-1);
	}

	return 0;
}