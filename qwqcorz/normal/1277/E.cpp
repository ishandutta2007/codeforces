#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1e3;
const int M=5e5+1e3;

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
}e[2*M];
int head[N],cnt;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int n,m,x,y,ans1,ans2;
bool b1,b2,b[N];
int dfs(int now)
{
	if (now==x) b1=1;
	if (now==y) b2=1;
	if (b[now]) return 0;
	int ret=b[now]=1;
	for (int i=head[now];i;i=e[i].next) ret+=dfs(e[i].to);
	return ret;
}

signed main()
{
	int T=read();
	while (T--)
	{
		n=read();
		m=read();
		x=read();
		y=read();
		ans1=ans2=cnt=0;
		for (int i=1;i<=n;i++) head[i]=b[i]=0;
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			add(u,v);
			add(v,u);
		}
		b[x]=b[y]=1;
		for (int i=1;i<=n;i++)
		if (!b[i])
		{
			b1=0;
			b2=0;
			int tot=dfs(i);
			if (!(b1&&b2))
			{
				if (b1) ans1+=tot;
				if (b2) ans2+=tot;
			}
		}
		print(ans1*ans2);
	}

	return 0;
}