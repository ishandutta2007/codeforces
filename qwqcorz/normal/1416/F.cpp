#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=N*5;
const int inf=1e9+7;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
const string s="RLDU";

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

namespace Flow
{
	struct edge
	{
		int to,nxt,val;
	}e[M*2];
	int head[N],cnte,cur[N];
	void add_edge(int u,int v,int w)
	{
		e[++cnte].to=v;
		e[cnte].val=w;
		e[cnte].nxt=head[u];
		head[u]=cnte;
	}
	int add(int u,int v,int w)
	{
		add_edge(u,v,w);
		int ret=cnte;
		add_edge(v,u,0);
		return ret;
	}
	int S,T,n;
	void send(int _n,int _S,int _T)
	{
		n=_n,S=_S,T=_T,cnte=1;
		memset(head,0,sizeof(int)*(n+1));
	}
	int deep[N];
	bool bfs()
	{
		queue<int>q;
		q.push(S);
		for (int i=0;i<=n;i++) deep[i]=cur[i]=0;
		deep[S]=1,cur[S]=head[S];
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			for (int i=head[now];i;i=e[i].nxt)
			{
				int to=e[i].to;
				if (!e[i].val) continue;
				if (!deep[to]) deep[to]=deep[now]+1,q.push(to),cur[to]=head[to];
				if (to==T) return 1;
			}
		}
		return deep[T];
	}
	int dfs(int now,int flow)
	{
		int ret=0;
		if (!flow) return 0;
		if (now==T) return flow;
		for (int i=cur[now];i;cur[now]=i=e[i].nxt)
		{
			int to=e[i].to,val=e[i].val,tmp;
			if (!val||deep[to]!=deep[now]+1) continue;
			if ((tmp=dfs(to,min(flow,val))))
			{
				ret+=tmp;
				flow-=tmp;
				e[i].val-=tmp;
				e[i^1].val+=tmp;
				if (!flow) return ret;
			}
			else deep[to]=0;
		}
		return ret;
	}
	int ans;
	int solve()
	{
		ans=0;
		while (bfs()) ans+=dfs(S,inf);
		return ans;
	}
}
namespace lrFlow
{
	int s,t,n,S,T;
	int u[M],v[M],l[M],r[M];
	int id[M],m,is[M];
	void send(int _n,int _S,int _T)
	{
		n=_n+2,s=_S,t=_T,S=n-1,T=n,m=0;
		Flow::send(n,S,T);
	}
	int add(int _u,int _v,int _l,int _r)
	{
		m++;
		u[m]=_u,v[m]=_v,l[m]=_l,r[m]=_r;
		id[m]=Flow::add(u[m],v[m],r[m]-l[m]);
		return m;
	}
	int d[N];
	bool solve()
	{
		int tot=0;
		Flow::add(t,s,inf);
		for (int i=0;i<=n;i++) d[i]=0;
		for (int i=1;i<=m;i++) d[u[i]]-=l[i],d[v[i]]+=l[i];
		for (int i=0;i<=n;i++)
		{
			tot+=abs(d[i]);
			if (d[i]>0) Flow::add(S,i,d[i]);
			if (d[i]<0) Flow::add(i,T,-d[i]);
		}
		int f=Flow::solve();
		if (f<tot/2) return 0;
		for (int i=1;i<=m;i++) is[i]=Flow::e[id[i]].val<r[i]-l[i];
		return 1;
	}
}
int d[N][4],can[N];
int ans1[N],ans2[N];
#define id(x,y) (x*m+y)

void ACDC()
{
	int n=read(),m=read(),S=n*m,T=n*m+1;
	for (int i=0;i<n*m;i++) memset(d[i],0,sizeof(d[i])),can[i]=ans1[i]=ans2[i]=0;
	lrFlow::send(T,S,T);
	vector<vector<int>>a(n);
	for (int i=0;i<n;i++) a[i].resize(m);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) a[i][j]=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	for (int k=0;k<4;k++)
	{
		int x=i+dx[k],y=j+dy[k];
		if (x<0||x>=n||y<0||y>=m) continue;
		can[id(i,j)]|=a[i][j]>a[x][y];
		if (((i^j)&1)&&a[i][j]==a[x][y]) d[id(i,j)][k]=lrFlow::add(id(i,j),id(x,y),0,1);
	}
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	if ((i^j)&1)
	{
		lrFlow::add(S,id(i,j),1,1);
		if (can[id(i,j)]) lrFlow::add(id(i,j),T,0,1);
	}
	else
	{
		lrFlow::add(id(i,j),T,1,1);
		if (can[id(i,j)]) lrFlow::add(S,id(i,j),0,1);
	}
	if (!lrFlow::solve()) return puts("NO"),void();
	puts("YES");
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		bool flag=0;
		for (int k=0;k<4;k++)
		{
			int x=i+dx[k],y=j+dy[k];
			if (x<0||x>=n||y<0||y>=m) continue;
			if (lrFlow::is[d[id(i,j)][k]]||lrFlow::is[d[id(x,y)][k^1]])
			{
				flag=1;
				ans1[id(i,j)]=k%2?1:a[i][j]-1;
				ans2[id(i,j)]=k;
				break;
			}
		}
		if (flag) continue;
		for (int k=0;k<4;k++)
		{
			int x=i+dx[k],y=j+dy[k];
			if (x<0||x>=n||y<0||y>=m||a[i][j]<=a[x][y]) continue;
			flag=1;
			ans1[id(i,j)]=a[i][j]-a[x][y];
			ans2[id(i,j)]=k;
			break;
		}
		if (flag) continue;
		assert(false);
	}
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) print(ans1[id(i,j)]," \n"[j+1==m]);
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++) putchar(s[ans2[id(i,j)]]),putchar(" \n"[j+1==m]);
}

signed main()
{
	int T=read();
	while (T--) ACDC();
	
	return 0;
}