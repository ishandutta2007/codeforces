#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct edge
{
	int v,nxt;
}e[2000005];
int n,a[500005],ra[500005],h[500005],t,f[500005],dfn[500005],ct;
int b[500005],bt,c[500005],cnt,nw,d[500005];
vector<int> val[500005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	f[u]=fa;
	d[u]=dep;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
bool cmp(const int x,const int y)
{
	return dfn[x]<dfn[y];
}
void dfs2(int u,int fa)
{
	sort(val[u].begin(),val[u].end(),cmp);
	int sz=val[u].size();
	for(int i=0;i<sz;i++)
	{
		int v=val[u][i];
		if(v==fa) continue;
		dfs2(v,u);
	}
	if(cnt+1<nw) c[u]=++cnt;
}
void dfs3(int u,int fa)
{
	if(!c[u]) c[u]=++cnt;
	int sz=val[u].size();
	for(int i=0;i<sz;i++)
	{
		int v=val[u][i];
		if(v==fa) continue;
		dfs3(v,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		val[u].push_back(v);
		val[v].push_back(u);
	}
	dfs(1,0,0);
	nw=a[1];
	ll ans=0;
	if(nw!=1&&nw!=n)
	{
		int id=-1;
		for(int i=1;i<=n;i++)
			if(a[i]==nw-1)
			{
				id=i;
				break;
			}
		bt=0;
		int nww=id;
		while(nww)
		{
			b[++bt]=nww;
			nww=f[nww];
		}
		for(int i=bt,j=1;i>1;i--,j++)
			if(a[b[i]]!=nw+j-1)
			{
			//	printf("i=%d,j=%d,nw=%d,b=%d,a=%d,w=%d\n",i,j,nw,b[i],a[b[i]],nw+j-1);
				printf("NO\n");
				return 0;
			}
		while(id!=1)
		{
			swap(a[id],a[f[id]]);
			ans++;
			id=f[id];
		}
	}
	nw=a[1];
	for(int i=1;i<=n;i++)
		ra[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int u=ra[i];
		if(i<nw) ans+=d[u];
		bt=0;
		while(u&&!dfn[u])
		{
			b[++bt]=u;
			u=f[u];
		}
		for(int j=bt;j>=1;j--)
			dfn[b[j]]=++ct;
	}
	dfs2(1,0);
	dfs3(1,0);
	for(int i=1;i<=n;i++)
		if(c[i]!=a[i])
		{
			printf("NO\n");
			return 0;
		}
	printf("YES\n%lld\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d ",dfn[i]);
	printf("\n");
	return 0;
}