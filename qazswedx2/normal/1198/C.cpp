#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[1000005];
int t,n,m,h[500005],tot,f[500005],a[500005],vis[500005],tans[500005],b[1000005][2];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
bool cmp(const int x,const int y)
{
	return f[x]<f[y];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=3*n;i++)
			h[i]=f[i]=vis[i]=0,a[i]=i;
		tot=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			b[i][0]=u,b[i][1]=v;
			f[u]++,f[v]++;
		}
		sort(a+1,a+3*n+1,cmp);
		int cnt=0;
		for(int i=1;i<=3*n;i++)
		{
			int u=a[i];
			if(vis[u]) continue;
			//printf("u=%d\n",u);
			cnt++;
			tans[cnt]=u;
			vis[u]=1;
			for(int j=h[u];j;j=e[j].nxt)
			{
				int v=e[j].v;
				vis[v]=1;
			}
		}
		if(cnt>=n)
		{
			printf("IndSet\n");
			for(int i=1;i<=n;i++)
				printf("%d ",tans[i]);
			printf("\n");
			continue;
		}
		int tt=10;
		while(tt--)
		{
			for(int i=1;i<=m;i++)
				a[i]=i;
			for(int i=1;i<=3*n;i++)
				vis[i]=0;
			random_shuffle(a+1,a+m+1);
			cnt=0;
			for(int i=1;i<=m;i++)
			{
				int u=b[a[i]][0],v=b[a[i]][1];
				if(vis[u]||vis[v]) continue;
				cnt++;
				tans[cnt]=a[i];
				vis[u]=vis[v]=1;
			}
			if(cnt>=n)
			{
				printf("Matching\n");
				for(int i=1;i<=n;i++)
					printf("%d ",tans[i]);
				printf("\n");
				break;
			}
		}
		if(tt==-1)
		{
			printf("Impossible\n");
		}
	}
	return 0;
}