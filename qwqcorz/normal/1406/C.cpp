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
	int to,nxt;
}e[N*2];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int n,siz[N],Max[N],Min,a[N],cntt,tmp2;
void dfs(int now,int fa)
{
	siz[now]=Max[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	if (e[i].to!=fa)
	{
		int to=e[i].to;
		dfs(to,now);
		siz[now]+=siz[to];
		Max[now]=max(Max[now],siz[to]);
	}
	Max[now]=max(Max[now],n-siz[now]);
	if (Max[now]<Min) Min=Max[now];
}
int find(int now,int fa)
{
	for (int i=head[now];i;i=e[i].nxt)
	if (e[i].to!=fa)
	{
		tmp2=now;
		return find(e[i].to,now);
	}
	return now;
}

signed main()
{
	int T=read();
	while (T--)
	{
		cnt=cntt=0;
		n=read();
		Min=n+1;
		for (int i=1;i<=n;i++) head[i]=0;
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add(u,v);
			add(v,u);
		}
		dfs(1,0);
//		for (int i=1;i<=n;i++) print(siz[i]);
		for (int i=1;i<=n;i++)
		if (Max[i]==Min)
		a[++cntt]=i;
		if (cntt==1) printf("%d %d\n%d %d\n",a[1],e[head[a[1]]].to,a[1],e[head[a[1]]].to);
		else
		{
			int tmp=find(a[2],a[1]);
			print(tmp2,' ');
			print(tmp);
			print(a[1],' ');
			print(tmp);
		}
	}

	return 0;
}