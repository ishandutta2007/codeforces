#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=5e5+5;

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
struct edge
{
	int to,nxt,val;
}e[M*2];
int head[N],cnte=0;
void add_edge(int u,int v,int w)
{
	e[++cnte].to=v;
	e[cnte].val=w;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int c[N],ans,t[2];
void clear(int n)
{
	ans=cnte=0;
	for (int i=1;i<=n;i++) c[i]=-1,head[i]=0;
}
bool dfs(int now,int col)
{
	if (c[now]<0) t[c[now]=col]++;
	else return c[now]==col;
	for (int i=head[now];i;i=e[i].nxt)
	if (!dfs(e[i].to,col^e[i].val))
	return 0;
	return 1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		clear(n);
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			char c; cin>>c;
			add_edge(u,v,c=='i');
			add_edge(v,u,c=='i');
		}
		bool flag=1;
		for (int i=1;i<=n;i++)
		if (c[i]<0)
		{
			t[0]=t[1]=0;
			flag&=dfs(i,0);
			ans+=max(t[0],t[1]);
		}
		print(flag?ans:-1);
	}
	
	return 0;
}