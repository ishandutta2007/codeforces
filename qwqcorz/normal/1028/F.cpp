#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
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
inline int gcd(int x,int y)
{
	return !y?x:gcd(y,x%y);
}
map<pair<int,int>,int>ans,d;
map<int,set<pair<int,int>>>p;

signed main()
{
	int Q=read(),siz=0;
	while (Q--)
	{
		int opt=read(),x=read(),y=read();
		if (opt==2) siz--,p[x*x+y*y].erase(mk(x,y));
		if (opt<=2)
		{
			auto a=p[x*x+y*y];
			for (auto i:a)
			{
				int tx=x+i.fi,ty=y+i.se,g=gcd(tx,ty);
				tx/=g,ty/=g;
				ans[mk(tx,ty)]+=opt==1?1:-1;
			}
		}
		if (opt==1) siz++,p[x*x+y*y].insert(mk(x,y));
		if (opt==3)
		{
			int g=gcd(x,y);
			x/=g,y/=g;
			print(siz-2*ans[mk(x,y)]-d[mk(x,y)]);
		}
		else
		{
			int g=gcd(x,y);
			x/=g,y/=g;
			d[mk(x,y)]+=opt==1?1:-1;
		}
	}
	
	return 0;
}