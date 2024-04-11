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
	int to,next,id;
}e[2*N];
bool is[N];
int head[N],cnt=0,siz[N],u[N],v[N];
void add(int u,int v,int id)
{
	e[++cnt].to=v;
	e[cnt].id=id;
	e[cnt].next=head[u];
	head[u]=cnt;
	siz[v]++;
}
bool dfs(int now,int fa,int end)
{
	if (now==end) return 1;
	for (int i=head[now];i;i=e[i].next)
	if (e[i].to!=fa)
	if (dfs(e[i].to,now,end))
	{
		is[e[i].id]=1;
		return 1;
	}
	return 0;
}

int main()
{
	memset(is,0,sizeof(is));
	memset(siz,0,sizeof(siz));
	int n=read(),tot=0,x,y,xx,yy;
	for (int i=1;i<n;i++)
	{
		u[i]=read();
		v[i]=read();
		add(u[i],v[i],i);
		add(v[i],u[i],i);
	}
	for (int i=1;i<=n;i++) tot+=siz[i]==1;
	if (tot==2)
	{
		for (int i=1;i<n;i++) print(i-1);
		return 0;
	}
	for (int i=1;i<n;i++)
	if (siz[u[i]]==1||siz[v[i]]==1)
	{
		x=i;
		break;
	}
	for (int i=x+1;i<n;i++)
	if (siz[u[i]]==1||siz[v[i]]==1)
	{
		y=i;
		break;
	}
	if (siz[u[x]]==1) xx=u[x];
				 else xx=v[x];
	if (siz[u[y]]==1) yy=u[y];
				 else yy=v[y];
	dfs(xx,0,yy);
	tot=3;
	bool tmp=0;
	for (int i=1;i<n;i++)
	if (i==x) print(0);
	else if (i==y) print(1);
	else if (!is[i]&&!tmp) print(2),tmp=1;
	else print(tot++);

	return 0;
}