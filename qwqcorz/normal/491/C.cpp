#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int M=55;

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
namespace Flow
{
	const int N=110;
	const int M=N*N;
	const int inf=2147483647;
	int n,S,T;
	struct edge
	{
		int to,nxt,w,p;
	}e[M*2];
	int head[N],cnt;
	inline int add_edge(int u,int v,int w,int p)
	{
		e[++cnt].to=v;
		e[cnt].w=w;
		e[cnt].p=p;
		e[cnt].nxt=head[u];
		return head[u]=cnt;
	}
	inline int add(int u,int v,int w,int p)
	{
		int ret=add_edge(u,v,w,p);
		add_edge(v,u,0,-p);
		return ret;
	}
	struct Queue
	{
		int now,flow,pre,id,pay;
	}q[M*N];
	int pay[N],ans1,ans2;
	inline bool spfa()
	{
		for (int i=0;i<=n;i++) pay[i]=inf;
		int h=1,t=1,x=-114514;
		q[1]=(Queue){S,inf,0,0,0};
		pay[S]=0;
		while (h<=t)
		{
			int now=q[h].now,flow=q[h].flow,p=q[h++].pay;
			#define to e[i].to
			if (pay[now]==p)
			for (int i=head[now];~i;i=e[i].nxt)
			if (e[i].w&&pay[to]>p+e[i].p&&to!=S)
			{
				pay[to]=p+e[i].p;
				q[++t]=(Queue){to,min(flow,e[i].w),h-1,i,pay[to]};
				if (to==T) x=t;
			}
			#undef to
		}
		if (x<0) return 0;
		int f=q[x].flow;
		ans1+=f;
		ans2+=f*q[x].pay;
		while (q[x].pre)
		{
			e[q[x].id].w-=f;
			e[q[x].id^1].w+=f;
			x=q[x].pre;
		}
		return 1;
	}
	inline void send(int _n,int _S,int _T)
	{
		cnt=-1;
		memset(head,-1,sizeof(head));
		n=_n;
		S=_S;
		T=_T;
		ans1=ans2=0;
	}
	inline void solve()
	{
		while (spfa());
	}
}
char a[N],b[N];
int e[M][M],id[M][M];
inline int get(char x)
{
	if ('a'<=x&&x<='z') return x-'a'+1;
	return x-'A'+27;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int len=read(),n=read();
	scanf("%s%s",a+1,b+1);
	for (int i=1;i<=len;i++)
	{
		int x=get(a[i]),y=get(b[i]);
		e[x][y]++;
	}
	int S=0,T=n*2+1;
	Flow::send(T,0,T);
	for (int i=1;i<=n;i++) Flow::add(S,i,1,0);
	for (int i=1;i<=n;i++) Flow::add(n+i,T,1,0);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) id[i][j]=Flow::add(i,n+j,1,-e[i][j]);
	Flow::solve();
	assert(Flow::ans1==n);
	print(-Flow::ans2);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (!Flow::e[id[i][j]].w)
	putchar(j<=26?'a'+j-1:'A'+j-27);
	
	return 0;
}