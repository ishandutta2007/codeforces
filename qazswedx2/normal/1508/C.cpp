#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
struct edge
{
	int u,v,w;
	bool operator<(const edge x) const
	{
		return w<x.w;
	}
}e[500005];
int n,m,f[500005],g[500005],vis[500005],fl=1;
ll ans=0;
vector<int> a[500005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int findg(int x)
{
	if(g[x]==x) return x;
	return g[x]=findg(g[x]);
}
void link(int x,int y)
{
//	printf("link:x=%d,y=%d\n",x,y);
	x=find(x),y=find(y);
	if(x==y)
	{
		fl=0;
		return;
	}
	f[x]=y;
}
void linkg(int x,int y)
{
//	printf("link:x=%d,y=%d\n",x,y);
	x=findg(x),y=findg(y);
	if(x==y) return;
	g[x]=y;
}
int main()
{
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i].u=u,e[i].v=v,e[i].w=w;
		a[u].push_back(v);
		a[v].push_back(u);
		sum^=w;
	}
	for(int i=1;i<=n;i++)
		f[i]=i,g[i]=i;
	int las=-1;
	for(int i=1;i<=n;i++)
		if((int)a[i].size()<n/2-1)
		{
			if(las!=-1) link(las,i);
			las=i;
			vis[i]=1;
		}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			int sz=a[i].size(),nw=0;
			sort(a[i].begin(),a[i].end());
			for(int j=1;j<i;j++)
			{
				if(nw<sz&&a[i][nw]==j)
				{
					nw++;
					continue;
				}
				link(i,j);
			}
		}
//	printf("fl=%d,%d\n",fl,1ll*n*(n-1)/2-m<=n-1);
	if(!(1ll*n*(n-1)/2-m<=n-1&&fl))
		sum=0;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v))
		{
			ans+=w;
			link(u,v);
			linkg(u,v);
		}
		else if(findg(u)!=findg(v))
			sum=min(sum,w);
	}
	ans+=sum;
	printf("%lld\n",ans);
	return 0;
}