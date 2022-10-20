#include<bits/stdc++.h>
#define fi first
#define se second
#define mk make_pair
using namespace std;

char get()
{
	char c=getchar();
	while (c!='+'&&c!='-'&&c!='?'&&(c<'a'||'z'<c)) c=getchar();
	return c;
}
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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
map<pair<int,int>,char>a;
int x=0,y=0;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	(void)n;
	for (int i=1;i<=m;i++)
	{
		char opt=get();
		if (opt=='+')
		{
			int u=read(),v=read();
			char c=get();
			if (a.count(mk(v,u)))
			{
				char cc=a[mk(v,u)];
				if (cc==c) y++;
					  else x++;
			}
			a[mk(u,v)]=c;
		}
		if (opt=='-')
		{
			int u=read(),v=read();
			if (a.count(mk(v,u)))
			{
				char cc=a[mk(v,u)];
				if (cc==a[mk(u,v)]) y--;
							   else x--;
			}
			a.erase(mk(u,v));
		}
		if (opt=='?')
		{
			int k=read();
			if (k&1) puts(x||y?"YES":"NO");
				else puts(y?"YES":"NO");
		}
	}
	
	return 0;
}