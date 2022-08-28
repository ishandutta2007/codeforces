#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int tt,n,m,deg[500005],vis[500005],h[500005],t,d[500005];
int ans1[500005],ans2[500005],at,a[500005],bt,b[500005];
vector<int> val[500005];
void add(int u,int v)
{
//	printf("add:u=%d,v=%d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	vis[u]=1;
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
	return d[x]>d[y];
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			deg[i]=vis[i]=h[i]=0,val[i].clear();
		t=at=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			val[u].push_back(v);
			val[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			if((int)val[i].size()==n-1)
			{
				at++;
				ans1[i]=ans2[i]=at;
				continue;
			}
			if(deg[i]) continue;
			sort(val[i].begin(),val[i].end());
			int nw=1,sz=val[i].size();
			if(nw==i) nw++;
			for(int j=0;j<sz;j++)
			{
				int v=val[i][j];
				if(nw!=v) break;
				nw++;
				if(nw==i) nw++;
			}
			add(i,nw);
			add(nw,i);
			deg[nw]++,deg[i]++;
		}
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				dfs(i,0,1);
			}
		for(int i=1;i<=n;i++)
			a[i]=i;
		sort(a+1,a+n+1,cmp);
	/*	for(int i=1;i<=n;i++)
			printf("%d ",deg[i]);
		printf("\n");*/
		for(int i=1;i<=n;i++)
		{
			int u=a[i];
			bt=0;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].v;
				if(deg[v]==1)
					b[++bt]=v;
			}
			if(!bt) continue;
			deg[u]=0;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].v;
				deg[v]--;
			}
		/*	printf("u=%d\n",u);
			for(int j=1;j<=bt;j++)
				printf("%d ",b[j]);
			printf("\n");*/
			for(int j=1;j<=bt;j++)
			{
				ans1[b[j]]=at+j;
				ans2[b[j]]=at+j+1;
			}
			ans1[u]=at+bt+1;
			ans2[u]=at+1;
			at+=(bt+1);
		}
		for(int i=1;i<=n;i++)
			printf("%d ",ans1[i]);
		printf("\n");
		for(int i=1;i<=n;i++)
			printf("%d ",ans2[i]);
		printf("\n");
	}
	return 0;
}