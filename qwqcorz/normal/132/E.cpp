#include<bits/stdc++.h>
using namespace std;
const int N=255;

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
namespace Flow
{
	const int N=5e3+5;
	const int M=5e4+5;
	const int inf=2147483647;
	int n,m,S,T,head[N],cnt=-1,ans1,ans2,f[N];
	struct edge
	{
		int nxt,to,v,p;
	}e[2*M];
	void add(int u,int v,int w,int p)
	{
		e[++cnt].to=v;
		e[cnt].v=w;
		e[cnt].p=p;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add_edge(int u,int v,int w,int p)
	{
		add(u,v,w,p);
		add(v,u,0,-p);
	}
	struct Queue
	{
		int now,v,nxt,w,p;
	}q[2*M];
	bool spfa()
	{
		for (int i=1;i<=n;i++) f[i]=inf;
		int Min=-114514,h=1,t=1;
		q[1].now=S;
		q[1].v=inf;
		q[1].nxt=0;
		q[1].w=-1;
		q[1].p=0;
		f[S]=0;
		while (h<=t)
		{
			int now=q[h].now,v=q[h].v,p=q[h++].p;
			if (p==f[now])
			for (int i=head[now];~i;i=e[i].nxt)
			if (e[i].v)
			{
				int to=e[i].to;
				if (f[to]>p+e[i].p&&to!=S)
				{
					f[to]=p+e[i].p;
					q[++t].v=min(v,e[i].v);
					q[t].now=to;
					q[t].nxt=h-1;
					q[t].w=i;
					q[t].p=p+e[i].p;
					if (to==T) Min=t;
				}
			}
		}
		if (Min==-114514) return 0;
		ans1+=q[Min].v;
		ans2+=q[Min].v*q[Min].p;
		int now=Min;
		while (q[now].nxt)
		{
			e[q[now].w].v-=q[Min].v;
			e[q[now].w^1].v+=q[Min].v;
			now=q[now].nxt;
		}
		return 1;
	}
	void send(int _n,int _S,int _T)
	{
		n=_n;
		S=_S;
		T=_T;
		for (int i=0;i<=n;i++) head[i]=-1;
	}
}
int popcount(int x)
{
	int ret=0;
	while (x)
	{
		ret++;
		x&=x-1;
	}
	return ret;
}
map<int,bool>vis;
char c[N];
int var[N],v1[N],v2[N],a[N];
struct Operator
{
	char var;
	int val;
}opt[N*2];

int main()
{
	vis.clear();
	///////////////////////build vertex///////////////////////
	int n=read(),m=read(),S=0,T,cnt=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) v1[i]=++cnt;
	for (int i=1;i<=n;i++) v2[i]=++cnt;
	for (int i=1;i<=m;i++) var[i]=++cnt;
	T=++cnt;
	Flow::send(cnt,S,T);
	///////////////////////build edge///////////////////////
	for (int i=1;i<=m;i++) Flow::add_edge(S,var[i],1,0);
	for (int i=1;i<=n;i++) Flow::add_edge(S,v1[i],1,0);
	for (int i=1;i<=n;i++) Flow::add_edge(v2[i],T,1,0);
	for (int i=1,j=0;i<=n&&j<m;i++)
	if (!vis.count(a[i]))
	{
		vis[a[i]]=1;
		Flow::add_edge(var[++j],v2[i],1,popcount(a[i]));
	}
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	if (a[i]==a[j]) Flow::add_edge(v1[i],v2[j],1,0);
			   else Flow::add_edge(v1[i],v2[j],1,popcount(a[j]));
	///////////////////////Network flow///////////////////////
	while (Flow::spfa());
	///////////////////////output///////////////////////
	cnt=0;
	for (int i=1;i<=n;i++)
	for (int j=Flow::head[v2[i]];~j;j=Flow::e[j].nxt)
	if (Flow::e[j].v)
	{
		int pre=Flow::e[j].to;
		if (pre<=n)
		{
			c[i]=c[pre];
			if (a[i]!=a[pre])
			{
				opt[++cnt].var=c[i];
				opt[cnt].val=a[i];
			}
		}
		else
		{
			c[i]=pre-n*2-1+'a';
			opt[++cnt].var=c[i];
			opt[cnt].val=a[i];
		}
		opt[++cnt].var=c[i];
		opt[cnt].val=-1;
	}
	print(cnt,' ');
	print(Flow::ans2);
	for (int i=1;i<=cnt;i++)
	if (~opt[i].val)
	{
		putchar(opt[i].var);
		putchar('=');
		print(opt[i].val);
	}
	else printf("print(%c)\n",opt[i].var);

	return 0;
}