#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int p[N];
bool vis[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		int now=i;
		while (!vis[now])
		{
			vis[now]=1;
			now=p[now];
		}
		print(now,' ');
	}

	return 0;
}