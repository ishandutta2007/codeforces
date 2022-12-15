#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;
vector<pair<int,int> > v[110];
struct spaceship{int x,a,f; long long p;}s[100010];
int n,m,p[110],f[110][110],x,y,id[100010],d,g,S,B,K,D[100010],e[100010][2];

bool cmp(const int &a,const int &b) {return s[a].a<s[b].a;}

namespace MaxFlow
{
	struct node{int to,next; long long c;}e[100010];
	int hd[10010],cnt,n,cur[10010],dis[10010],q[10010],l,r,x;
	void addedge(int x,int y,long long c)
	{
		e[++cnt]=(node){y,hd[x],c},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y],0},hd[y]=cnt;
	}
	bool bfs()
	{
		for (int i=1; i<=n; i++) dis[i]=0;
		dis[1]=1,q[l=r=1]=1;
		while (l<=r)
		{
			x=q[l++];
			for (int i=hd[x]; i; i=e[i].next)
				if (e[i].c>0&&!dis[e[i].to]) dis[e[i].to]=dis[x]+1,q[++r]=e[i].to;
		}
		return (dis[n]>0);
	}
	long long dinic(int x,long long f)
	{
		if (x==n) return f;
		for (int &i=cur[x]; i; i=e[i].next)
			if (e[i].c>0&&dis[e[i].to]==dis[x]+1)
			{
				long long nw=dinic(e[i].to,min(f,e[i].c));
				if (nw>0) return e[i].c-=nw,e[i^1].c+=nw,nw;
			}
		return 0;
	}
	long long solve()
	{
		long long ans=0,nw;
		while (bfs())
		{
			for (int i=1; i<=n; i++) cur[i]=hd[i];
			while (nw=dinic(1,inf)) ans+=nw;
		}
		return ans;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) f[i][j]=100000;
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),f[x][y]=f[y][x]=1;
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	scanf("%d%d%d",&S,&B,&K);
	for (int i=1; i<=S; i++) id[i]=i,scanf("%d%d%d%d",&s[i].x,&s[i].a,&s[i].f,&s[i].p);
	sort(id+1,id+1+S,cmp);
	for (int i=1; i<=B; i++) scanf("%d%d%d",&x,&d,&g),v[x].push_back(make_pair(d,g));
	for (int i=1 ;i<=n; i++) 
	{
		sort(v[i].begin(),v[i].end()),p[i]=0;
		for (int j=1,sz=v[i].size(); j<sz; j++)
			v[i][j].second=max(v[i][j].second,v[i][j-1].second);
	}
	long long ans=0;
	for (int I=1; I<=S; I++)
	{
		int i=id[I];
		long long ma=-inf;
		for (int j=1; j<=n; j++)
			if (f[s[i].x][j]<=s[i].f)
			{
				int sz=v[j].size();
				if (!sz) continue;
				while (p[j]<sz-1&&v[j][p[j]+1].first<=s[i].a) p[j]++;
				if (v[j][p[j]].first<=s[i].a) ma=max(ma,(long long)v[j][p[j]].second);
			}
		s[i].p=ma-s[i].p;
		if (s[i].p>0) ans+=s[i].p;
	}
	MaxFlow::n=2,MaxFlow::cnt=1;
	for (int i=1; i<=K; i++) scanf("%d%d",&e[i][0],&e[i][1]),D[e[i][0]]++,D[e[i][1]]++;
	for (int i=1; i<=S; i++) if (D[i]) id[i]=(MaxFlow::n++);
	for (int i=1; i<=K; i++) MaxFlow::addedge(id[e[i][0]],id[e[i][1]],inf);
	for (int i=1; i<=S; i++) if (D[i])
	{
		if (s[i].p>0) MaxFlow::addedge(1,id[i],s[i].p);
		else MaxFlow::addedge(id[i],MaxFlow::n,-s[i].p);
	}
	ans-=MaxFlow::solve();
	printf("%I64d\n",ans);
	return 0;
}