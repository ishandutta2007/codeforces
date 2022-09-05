#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000000ll;

struct Dinic
{
	int s,t,n,hd[210010],cnt,q[210010],dis[210010],l,r,cur[210010],x;
	struct node{int to,next; long long c;}e[1010010];
	void init(int N,int S,int T) 
	{
		n=N,s=S,t=T,cnt=1;
		for (int i=1; i<=n; i++) hd[i]=0;
	}
	void addedge(int x,int y,long long c) {e[++cnt]=(node){y,hd[x],c},hd[x]=cnt;}
	bool bfs()
	{
		for (int i=1; i<=n; i++) dis[i]=-1;
		dis[q[l=r=1]=s]=0;
		while (l<=r)
		{
			x=q[l++];
			for (int i=hd[x]; i; i=e[i].next)
				if (e[i].c&&dis[e[i].to]==-1) dis[q[++r]=e[i].to]=dis[x]+1;
		}
		return dis[t]!=-1;
	}
	long long dinic(int x,long long f)
	{
		if (x==t) return f;
		for (int &i=cur[x]; i; i=e[i].next)
			if (e[i].c&&dis[e[i].to]==dis[x]+1)
			{
				long long nw=dinic(e[i].to,min(f,e[i].c));
				if (nw) return e[i].c-=nw,e[i^1].c+=nw,nw;
			}
		return 0;
	}
	long long solve()
	{
		long long ans=0,nw;
		while (bfs())
		{
			for (int i=1; i<=n; i++) cur[i]=hd[i];
			while (nw=dinic(s,inf)) ans+=nw;
		}
		return ans;
	}
}t1,t2;

long long ans,d[210010];
int n,b,r,x,y,m,col[100010],lx[100010],rx[100010],ly[100010],ry[100010],sx[100010],sy[100010],ord;
map<pair<int,int>,vector<int> > po;
map<pair<int,int>,vector<int> >::iterator it;
map<int,int> mx,my;

int main()
{
	scanf("%d%d%d%d",&n,&m,&r,&b);
	int cntx=0,cnty=0;
	for (int i=1; i<=n; i++) 
	{
		scanf("%d%d",&x,&y);
		if (!mx[x]) mx[x]=(++cntx);
		if (!my[y]) my[y]=(++cnty);
		x=mx[x],y=my[y];
		po[make_pair(x,y)].push_back(i);
	}
	t1.init(cntx+cnty+4,cntx+cnty+3,cntx+cnty+4);
	t2.init(cntx+cnty+2,cntx+cnty+1,cntx+cnty+2);
	for (it=po.begin(); it!=po.end(); it++)
	{
		sx[(*it).first.first]+=(*it).second.size();
		sy[(*it).first.second]+=(*it).second.size();
		for (int i=0,sz=(*it).second.size(); i<sz; i++)
			t1.addedge((*it).first.first,(*it).first.second+cntx,1),
			t1.addedge((*it).first.second+cntx,(*it).first.first,0);
	}
	for (int i=1; i<=cntx; i++) lx[i]=0,rx[i]=sx[i];
	for (int i=1; i<=cnty; i++) ly[i]=0,ry[i]=sy[i];
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&ord,&x,&y);
		if (ord==1)
		{
			x=mx[x];
			if (!x) continue;
			lx[x]=max(lx[x],(sx[x]-y+1)/2);
			rx[x]=min(rx[x],(sx[x]+y)/2);
		} else
		{
			x=my[x];
			if (!x) continue;
			ly[x]=max(ly[x],(sy[x]-y+1)/2);
			ry[x]=min(ry[x],(sy[x]+y)/2);
		}
	}
	for (int i=1; i<=cntx; i++)
	{
		if (lx[i]>rx[i]) return puts("-1"),0;
		d[i]-=lx[i],d[t2.s]+=lx[i];
		t1.addedge(t2.s,i,rx[i]-lx[i]);
		t1.addedge(i,t2.s,0);
	}
	for (int i=1; i<=cnty; i++)
	{
		if (ly[i]>ry[i]) return puts("-1"),0;
		d[i+cntx]+=ly[i],d[t2.t]-=ly[i];
		t1.addedge(i+cntx,t2.t,ry[i]-ly[i]);
		t1.addedge(t2.t,i+cntx,0);
	}
	t1.addedge(t2.t,t2.s,inf);
	t1.addedge(t2.s,t2.t,0);
	long long f=0;
	for (int i=1; i<=t2.n; i++)
		if (d[i]>0) t1.addedge(i,t1.t,d[i]),t1.addedge(t1.t,i,0),f+=d[i];
		else t1.addedge(t1.s,i,-d[i]),t1.addedge(i,t1.s,0);
	if (t1.solve()!=f) return puts("-1"),0;
	for (int i=2; i<=t1.cnt; i+=2)
		if (t1.e[i].to<=t2.n&&t1.e[i^1].to<=t2.n&&!(t1.e[i].to>cntx+cnty&&t1.e[i^1].to>cntx+cnty))
			t2.addedge(t1.e[i^1].to,t1.e[i].to,t1.e[i].c),t2.addedge(t1.e[i].to,t1.e[i^1].to,t1.e[i^1].c);
	t2.solve();
	ans=1ll*n*max(b,r);
	for (int j=1; j<=cntx; j++)
		for (int i=t2.hd[j]; i; i=t2.e[i].next)
			if (t2.e[i].to<=cntx+cnty&&!t2.e[i].c)
			{
				it=po.find(make_pair(j,t2.e[i].to-cntx));
				col[(*it).second[(*it).second.size()-1]]=1;
				ans-=(max(b,r)-min(b,r));
				po[make_pair(j,t2.e[i].to-cntx)].pop_back();
			}
	printf("%I64d\n",ans);
	for (int i=1; i<=n; i++)
		if (col[i]) putchar(r<b?'r':'b');
		else putchar(r<b?'b':'r');
	return 0;
}