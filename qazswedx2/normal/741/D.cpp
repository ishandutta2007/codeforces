#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[1000005];
int n,a[500005],vis[8000005],tans[500005],h[500005],size[500005],d[500005],cnt;
int son[500005],dfn[500005],udfn[500005],t;
multiset<int> st[4200005];
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int nw,int dep)
{
	a[u]=nw;
	size[u]=1;
	son[u]=0;
	dfn[u]=++cnt;
	udfn[cnt]=u;
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(v==fa) continue;
		dfs(v,u,nw^w,dep+1);
		size[u]+=size[v];
		if(size[son[u]]<size[v]) son[u]=v;
	}
}
void dfs2(int u,int fa,int fl)
{
	//printf("u=%d,fa=%d,fl=%d\n",u,fa,fl);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||v==son[u]) continue;
		dfs2(v,u,0);
		tans[u]=max(tans[u],tans[v]);
	}
	if(son[u]) dfs2(son[u],u,1),tans[u]=max(tans[u],tans[son[u]]);
	for(int k=0;k<=22;k++)
	{
		int nw=a[u]^(1<<k);
		if(k==22) nw=a[u];
		//printf("k=%d,nw=%d\n",k,nw);
		if(vis[nw])
		{
			multiset<int>::iterator it=st[nw].end();
			//printf("%u\n",st[nw].size());
			tans[u]=max(tans[u],(int)(*--it)-d[u]);
		}
	}
	vis[a[u]]++;
	st[a[u]].insert(d[u]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa||v==son[u]) continue;
		for(int j=dfn[v];j<=dfn[v]+size[v]-1;j++)
			for(int k=0;k<=22;k++)
			{
				int nw=a[udfn[j]]^(1<<k);
				if(k==22) nw=a[udfn[j]];
				if(vis[nw])
				{
					multiset<int>::iterator it=st[nw].end();
					tans[u]=max(tans[u],(int)(*--it)+d[udfn[j]]-2*d[u]);
				}
			}
		for(int j=dfn[v];j<=dfn[v]+size[v]-1;j++)
			vis[a[udfn[j]]]++,st[a[udfn[j]]].insert(d[udfn[j]]);
	}
	if(!fl)
	{
		for(int i=dfn[u];i<=dfn[u]+size[u]-1;i++)
			vis[a[udfn[i]]]--,st[a[udfn[i]]].erase(st[a[udfn[i]]].lower_bound(d[udfn[i]]));
		return;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int v;
		char w;
		scanf("%d %c",&v,&w);
		add(i,v,1<<(int)(w-'a'));
		add(v,i,1<<(int)(w-'a'));
	}
	dfs(1,0,0,0);
	//for(int i=1;i<=n;i++)
	//	printf("i=%d,a=%d,udfn=%d,dfn=%d,son=%d,size=%d,d=%d\n",i,a[i],
	//			udfn[i],dfn[i],son[i],size[i],d[i]);
	dfs2(1,1,1);
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	return 0;
}