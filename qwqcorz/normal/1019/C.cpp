#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

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
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
bool vis[N],ans[N];

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	int tot=0;
	for (int i=1;i<=n;i++)
	if (!vis[i])
	{
		tot++;
		vis[i]=ans[i]=1;
		for (int j=head[i];j;j=e[j].nxt)
		vis[e[j].to]=1;
	}
	for (int i=n;i>=1;i--)
	if (ans[i])
	for (int j=head[i];j;j=e[j].nxt)
	{
		int to=e[j].to;
		tot-=ans[to];
		ans[to]=0;
	}
	print(tot);
	for (int i=1;i<=n;i++)
	if (ans[i])
	print(i,' ');

	return 0;
}