#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
	int to,next;
}e[2*N];
int head[N],cnt=0,siz[N];
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	siz[v]++;
}
bool dfs(int now,int fa,int deep)
{
	if (siz[now]==1&&deep%2) return 1;
	for (int i=head[now];i;i=e[i].next)
	if (e[i].to!=fa)
	if (dfs(e[i].to,now,deep+1)) return 1;
	return 0;
}

int main()
{
	memset(siz,0,sizeof(siz));
	int n=read(),root,ans=n-1;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for (int i=1;i<=n;i++)
	if (siz[i]==1)
	{
		root=i;
		break;
	}
	if (dfs(root,0,0)) print(3,' ');
				  else print(1,' ');
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		for (int j=head[i];j;j=e[j].next) cnt+=siz[e[j].to]==1;
		ans-=cnt;
		if (cnt) ans++;
	}
	print(ans);

	return 0;
}