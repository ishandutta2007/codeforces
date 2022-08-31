#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,vis,nxt;
}e[500005];
int n,m,deg[3005],h[3005],t=1,tans[100005],tt,vis[3005],f[3005],sz[3005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u)
{
	for(int &i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(e[i].vis) continue;
		e[i].vis=e[i^1].vis=1;
		dfs(v); 
	}
	tans[++tt]=u;
}
int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}
int link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return 0;
	if(sz[x]>sz[y]) swap(sz[x],sz[y]);
	f[x]=y;
	sz[y]+=sz[x];
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		deg[u]++,deg[v]++;
	}
	int ct=0;
	for(int i=1;i<=n;i++)
		if(deg[i]%2) ct++;
	for(int i=1;i<=n;i++)
	{
		int nw=0;
		for(int j=h[i];j;j=e[j].nxt)
		{
			int v=e[j].v;
			if(deg[v]%2) nw++;
		}
		if((deg[i]%2==0&&nw>=ct-1)||(deg[i]%2==1&&nw>=ct-2))
		{
			int s=i;
			for(int j=h[i];j;j=e[j].nxt)
			{
				int v=e[j].v;
				if(deg[v]%2)
				{
					vis[v]=1,e[j].vis=e[j^1].vis=1;
					tans[++tt]=i;
					tans[++tt]=v;
				}
			}
			tans[++tt]=-1;
			for(int j=1;j<=n;j++)
				if(!vis[j]&&deg[j]%2&&j!=i)
					s=j;
		//	printf("i=%d,s=%d\n",i,s);
			int fl=1;
			if(s==i)
			{
				for(int j=1;j<=n;j++)
					f[j]=j,sz[j]=1;
				int ct=0;
				for(int j=2;j<=t;j+=2)
					if(!e[j].vis) ct+=link(e[j].v,e[j^1].v);
			//	printf("ct=%d\n",ct);
				for(int j=h[i];j;j=e[j].nxt)
				{
					int v=e[j].v;
			//		printf("v=%d,sz=%d\n",v,sz[find(v)]);
					if(deg[v]%2&&sz[find(v)]==1) ct++;
				}
			//	printf("ct=%d\n",ct);
				if(ct<n-2) fl=0;
				else if(ct==n-2)
				{
					for(int j=2;j<=t;j++)
						if(e[j].vis&&e[j].v!=i&&find(e[j].v)!=find(e[j^1].v)&&sz[find(e[j].v)]!=1)
						{
							s=e[j].v;
							e[j].vis=e[j^1].vis=0;
							for(int k=1;k<=tt;k++)
								if(tans[k]==s)
								{
									for(int l=k+1;l<=tt;l++)
										tans[l-2]=tans[l];
									tt-=2;
									break;
								}
						//	printf("j=%d,s=%d\n",j,s);
							break;
						}
					if(s==i) fl=0;
				}
			}
			if(!fl)
			{
				tt=0;
				for(int j=2;j<=t;j++)
					e[j].vis=0;
				continue;
			}
			dfs(s);
			if(s!=i)
			{
				for(int j=2;j<=t;j++)
					if(!e[j].vis) fl=0;
			}
			if(!fl)
			{
				tt=0;
				continue;
			}
			printf("%d\n",tt);
			for(int i=tt;i;i--)
				printf("%d ",tans[i]);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}