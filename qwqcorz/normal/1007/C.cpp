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
int Q(int x,int y)
{
	print(x,' ');
	print(y);
	fflush(stdout);
	return read();
}

signed main()
{
	int n=read();
	for (int x=0,y=0,dx=1,dy=1;;)
	{
		int _=Q(x+dx,y+dy);
		if (_==0) return 0;
		if (_==1) x+=dx,dx=min(n-x,2ll*dx);
		if (_==2) y+=dy,dy=min(n-y,2ll*dy);
		if (_==3) dx=max(dx/2,1ll),dy=max(dy/2,1ll);
	}

	return 0;
}