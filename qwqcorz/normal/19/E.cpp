#include<bits/stdc++.h>
using namespace std;
const int N=114514;

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
	bool is;
	int to,nxt,id;
}e[N];
int head[N],cnt=0;
void add(int u,int v,int id)
{
	e[++cnt].to=v;
	e[cnt].id=id;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int tot=0,dep[N],a[N],ans[N],answer=0;
void dfs0(int now,int fa)
{
//	print(now);
	dep[now]=dep[fa]+1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==fa) continue;
		if (dep[to]&&dep[to]<dep[now])
		{
			if ((dep[to]-dep[now])&1)
			{
				a[now]--;
				a[to]++;
			}
			else
			{
				tot++;
//				print(now,' ');
//				print(to);
				a[now]++;
				a[to]--;
			}
		}
		if (!dep[to])
		{
			e[i].is=1;
			dfs0(to,now);
		}
	}
}
void dfs1(int now,int fa)
{
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==fa) continue;
		if (dep[to]<dep[now])
		{
			if (tot==1&&((dep[to]-dep[now])%2==0)) ans[++answer]=e[i].id;
			continue;
		}
		if (!e[i].is) continue;
		dfs1(to,now);
		if (a[to]==tot) ans[++answer]=e[i].id;
		a[now]+=a[to];
	}
}

signed main()
{
	memset(a,0,sizeof(a));
	memset(dep,0,sizeof(dep));
	memset(head,0,sizeof(head));
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v,i);
		add(v,u,i);
	}
	for (int i=1;i<=n;i++)
	if (!dep[i])
	{
		dfs0(i,0);
		dfs1(i,0);
	}
	if (tot==0)
	{
		print(m);
		for (int i=1;i<=m;i++) print(i,' ');
		return 0;
	}
	print(answer);
	sort(ans+1,ans+1+answer);
	for (int i=1;i<=answer;i++) print(ans[i],' ');
//	print(tot);

	return 0;
}