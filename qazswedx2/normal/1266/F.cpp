#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return id>x.id;
	}
}b[500005];
int n,h[500005],t=1,tans[500005],d[500005],tmp[500005],dg[500005];
int bt;
vector<int> a[500005];
multiset<int> st;
map<int,int> mp[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa)
{
	d[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		a[u].push_back(d[v]+1);
		d[u]=max(d[u],d[v]+1);
	}
}
void dfs2(int u,int fa,int dep)
{
	if(dep) a[u].push_back(dep);
	st.clear();
	st.insert(dep+1);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		st.insert(d[v]+2);
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		st.erase(st.lower_bound(d[v]+2));
		tmp[v]=*--st.end();
	//	printf("v=%d,tmp=%d\n",v,tmp[v]);
		st.insert(d[v]+2);
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u,tmp[v]);
	}
}
bool cmp(const int x,const int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		dg[u]++,dg[v]++;
	}
	for(int i=1;i<=n;i++)
		tans[i]=1;
	for(int i=1;i<=n;i++)
		if(dg[i]+1>tans[1])
			tans[1]=dg[i]+1;
	dfs(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;i++)
	{
		int u=i;
		sort(a[u].begin(),a[u].end(),cmp);
		int nw=0,val=1e9,ct=0;
		for(int j=0;j<(int)a[u].size();j++)
		{
			int x=a[u][j];
			if(x) mp[u][x]++;
			//nw++;
			if(val>x) nw+=ct,val=x,ct=1;
			else ct++;
			//printf("u=%d,nw=%d,val=%d,ct=%d,x=%d\n",u,nw,val,ct,x);
			if(x) tans[2*x+1]=max(tans[2*x+1],nw+1);
			if(x>1) tans[2*x-1]=max(tans[2*x-1],nw+ct);
			if(x) tans[2*x]=max(tans[2*x],nw+ct);
		}
	}
	for(int i=2;i<=t;i+=2)
	{
		int u=e[i].v,v=e[i^1].v;
		bt=0;
		for(map<int,int>::iterator it=mp[u].begin();it!=mp[u].end();it++)
		{
			b[++bt].id=it->first;
			b[bt].val=it->second;
		}
		for(map<int,int>::iterator it=mp[v].begin();it!=mp[v].end();it++)
		{
			b[++bt].id=it->first;
			b[bt].val=it->second;
		}
		sort(b+1,b+bt+1);
		//printf("u=%d,v=%d\n",u,v);
		int pre=0;
		for(int j=1;j<=bt;j++)
		{
			pre+=b[j].val;
			//printf("val=%d,id=%d\n",b[j].val,b[j].id);
			tans[b[j].id*2]=max(tans[b[j].id*2],pre-2);
		}
	}
	for(int i=n-n%2;i;i-=2)
		tans[i]=max(tans[i],tans[i+2]);
	for(int i=n-((n%2)^1);i>1;i-=2)
		tans[i]=max(tans[i],tans[i+2]);
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}