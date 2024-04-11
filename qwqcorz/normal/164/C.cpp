#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int inf=1e9+7;

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
	const int N=::N*2;
	const int M=::N*4;
	const ll infll=1e18;
	int n,S,T;
	struct edge
	{
		int to,nxt,w,p;
	}e[M*2];
	int head[N],cnte;
	int add_edge(int u,int v,int w,int p)
	{
		e[++cnte].to=v;
		e[cnte].w=w;
		e[cnte].p=p;
		e[cnte].nxt=head[u];
		head[u]=cnte;
		return cnte;
	}
	int add(int u,int v,int w,int p)
	{
		int ret=add_edge(u,v,w,p);
		add_edge(v,u,0,-p);
		return ret;
	}
	int ans1,ans2;
	bool vis[N];
	queue<int>q;
	int flow[N],epre[N],vpre[N];
	ll pay[N];
	bool spfa()
	{
		for (int i=0;i<=n;i++) vpre[i]=-1,pay[i]=infll;
		vis[S]=1;
		q.push(S);
		pay[S]=0;
		flow[S]=inf;
		while (!q.empty())
		{
			int now=q.front(); q.pop(),vis[now]=0;
			for (int i=head[now];i;i=e[i].nxt)
			if (e[i].w)
			{
				int to=e[i].to;
				if (pay[to]>pay[now]+e[i].p)
				{
					pay[to]=pay[now]+e[i].p;
					flow[to]=min(flow[now],e[i].w);
					epre[to]=i;
					vpre[to]=now;
					if (!vis[to]) vis[to]=1,q.push(to);
				}
			}
		}
		if (pay[T]==infll) return 0;
		int f=flow[T],x=T;
		ans1+=f,ans2+=f*pay[T];
		while (~vpre[x])
		{
			e[epre[x]].w-=f;
			e[epre[x]^1].w+=f;
			x=vpre[x];
		}
		return 1;
	}
	void solve()
	{
		while (spfa());
	}
	void send(int _n,int _S,int _T)
	{
		n=_n,S=_S,T=_T;
		cnte=1,ans1=ans2=0;
		memset(head,0,sizeof(head));
	}
}
struct node
{
	int l,r,c,id;
	bool operator <(const node &a)const
	{
		return r<a.r;
	}
}a[N];
int id[N],ans[N];

signed main()
{
	int n=read(),k=read();
	for (int i=1;i<=n;i++)
	{
		a[i].l=read();
		a[i].r=a[i].l+read()-1;
		a[i].c=read();
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	int S1=n*2+1,S2=n*2+2,T=0;
	Flow::send(n*2+2,S1,T);
	Flow::add(S1,S2,k,0);
	Flow::add(S2,1,inf,0);
	Flow::add(n+n,T,inf,0);
	for (int i=1;i<=n;i++) id[i]=Flow::add(i,i+n,1,-a[i].c);
	for (int i=1;i<n;i++) Flow::add(i+n,i+1+n,inf,0);
	for (int i=1;i<=n;i++) Flow::add(S2,i,inf,0);
	for (int i=1;i<=n;i++)
	{
		int pos=lower_bound(a+1,a+1+i,(node){0,a[i].l})-a-1;
		if (pos) Flow::add(pos+n,i,inf,0);
	}
	Flow::solve();
	for (int i=1;i<=n;i++) if (!Flow::e[id[i]].w) ans[a[i].id]=1;
	for (int i=1;i<=n;i++) print(ans[i]," \n"[i==n]);
	
	return 0;
}