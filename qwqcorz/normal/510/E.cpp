#include<bits/stdc++.h>
using namespace std;
const int N=205;

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
	const int N=205;
	const int M=2e4+5;
	const int inf=1<<30;
	int n,S,T;
	struct edge
	{
		int to,nxt,w;
	}e[M*2];
	int head[N],cnt,cur[N];
	inline int add_edge(int u,int v,int w)
	{
		e[++cnt].to=v;
		e[cnt].w=w;
		e[cnt].nxt=head[u];
		return head[u]=cnt;
	}
	inline int add(int u,int v,int w)
	{
		int ret=add_edge(u,v,w);
		add_edge(v,u,0);
		return ret;
	}
	int q[N],dis[N];
	inline bool bfs()
	{
		for (int i=0;i<=n;i++) cur[i]=head[i];
		for (int i=0;i<=n;i++) dis[i]=-1;
		int h=1,t=1;
		q[1]=S;
		dis[S]=0;
		while (h<=t)
		{
			int now=q[h++];
			#define to e[i].to
			for (int i=head[now];~i;i=e[i].nxt)
			if (e[i].w)
			if (dis[to]<0)
			{
				dis[to]=dis[now]+1;
				q[++t]=to;
			}
			#undef to
		}
		return dis[T]>=0;
	}
	int dfs(int now,int flow)
	{
		if (!flow) return 0;
		if (now==T) return flow;
		int ret=0,tmp;
		#define to e[i].to
		for (int i=cur[now];~i;cur[now]=i=e[i].nxt)
		if (dis[to]==dis[now]+1)
		if ((tmp=dfs(to,min(flow,e[i].w))))
		{
			ret+=tmp;
			flow-=tmp;
			e[i].w-=tmp;
			e[i^1].w+=tmp;
			if (!flow) return ret;
		}
		#undef to
		return ret;
	}
	inline int Dinic()
	{
		int ans=0;
		while (bfs()) ans+=dfs(S,inf);
		return ans;
	}
	inline void send(int _n,int _S,int _T)
	{
		cnt=-1;
		n=_n;
		S=_S;
		T=_T;
		memset(head,-1,sizeof(head));
	}
}
inline bool check(int n)
{
	for (int i=2;i*i<=n;i++) if (n%i==0) return 0;
	return 1;
}
int a[N],b[N],v[N],e[N][N];
int n,cnt1=0,cnt2=0;
bool vis[N];
vector<int>tmp,g[N];
vector<vector<int>>ans;
void dfs(int now,int father)
{
	if (vis[now])
	{
		ans.push_back(tmp);
		tmp.clear();
		return;
	}
	vis[now]=1;
	tmp.push_back(now);
	for (int i:g[now]) if (i!=father&&(!vis[i]||i==tmp[0])) dfs(i,now);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read();
	for (int i=1;i<=n;i++)
	{
		v[i]=read();
		if (v[i]&1) a[++cnt1]=i;
			   else b[++cnt2]=i;
	}
	if (cnt1!=cnt2) return puts("Impossible"),0;
	int S=0,T=n+1;
	Flow::send(T,S,T);
	n/=2;
	for (int i=1;i<=n;i++) Flow::add(S,a[i],2);
	for (int i=1;i<=n;i++) Flow::add(b[i],T,2);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (check(v[a[i]]+v[b[j]])) e[i][j]=Flow::add(a[i],b[j],1);
	if (Flow::Dinic()<n*2) return puts("Impossible"),0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (e[i][j]&&!Flow::e[e[i][j]].w)
		g[a[i]].push_back(b[j]),
		g[b[j]].push_back(a[i]);
	for (int i=1;i<=n*2;i++) if (!vis[i]) dfs(i,0);
	print(ans.size());
	for (auto i:ans)
	{
		print(i.size(),' ');
		for (int j:i) print(j,' ');
		puts("");
	}
	
	return 0;
}