#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct edge
{
	int v,nxt;
}e[1000005],e2[1000005];
struct pt
{
	int l,r;
	pt(int l=0,int r=0):l(l),r(r){}
	bool operator<(const pt x) const
	{
		return r<x.r;
	}
};
int T,n,a[500005][2],h[500005],t,h2[500005],t2,dfn[500005],sz[500005],ans,ct;
//int lazy[17000005],ls[17000005],rs[17000005];
set<pt> st;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void add2(int u,int v)
{
	e2[++t2].v=v;
	e2[t2].nxt=h2[u];
	h2[u]=t2;
}
/*int modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return x;
	int y=++ct;
	lazy[y]=lazy[x],ls[y]=ls[x],rs[y]=rs[x];
	if(ql<=l&&r<=qr)
	{
		lazy[y]=v;
		return y;
	}
	
}*/
void dfs(int u,int fa)
{
	dfn[u]=++ct;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int fa)
{
	pt las,p;
	int fl=0;
	p=pt(dfn[u],dfn[u]+sz[u]-1);
	set<pt>::iterator it=st.lower_bound(pt(0,dfn[u]));
	if(it!=st.end()&&it->l<=dfn[u])
	{
		las=*it;
		st.erase(it);
		fl=1;
		st.insert(p);
	}
	else if(it!=st.end()&&it->r<dfn[u]+sz[u])
		fl=-1;
	else st.insert(p);
	ans=max(ans,(int)st.size());
	for(int i=h2[u];i;i=e2[i].nxt)
	{
		int v=e2[i].v;
		if(v==fa) continue;
		dfs2(v,u);
	}
	if(fl!=-1) st.erase(p);
	if(fl==1) st.insert(las);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		st.clear();
		ans=0;
		t=t2=0;
		for(int i=1;i<=n;i++)
			h[i]=h2[i]=0;
		for(int i=2;i<=n;i++)
		{
			int v;
			scanf("%d",&v);
			add2(v,i);
			add2(i,v);
		}
		for(int i=2;i<=n;i++)
		{
			int v;
			scanf("%d",&v);
			add(v,i);
			add(i,v);
		}
		dfs(1,0);
		dfs2(1,0);
		printf("%d\n",ans);
	}
	return 0;
}