#include<bits/stdc++.h>
#define mk make_pair
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
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
map<pair<int,int>,bool>m;

signed main()
{
	m.clear();
	int n=read(),x0=read(),y0=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read()-x0,y=read()-y0;
		if (x<0) x=-x,y=-y;
		if (x==0) y=abs(y);
		if (y==0) x=abs(x);
		int g=gcd(abs(x),abs(y));
		if (g)
		{
			x/=g;
			y/=g;
		}
		if (!m[mk(x,y)]) ans+=m[mk(x,y)]=1;
	}
	if (ans>1&&n>1&&m[mk(0,0)]) ans--;
	print(ans);

	return 0;
}