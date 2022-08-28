#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int tt,n,m,h[500005],t,e2[1000005][3],et,q[1000005],f[1000005],head,tail,c[1000005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
	f[v]++;
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		t=et=0;
		for(int i=1;i<=n;i++)
			h[i]=f[i]=0;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&w,&u,&v);
			et++;
			e2[et][0]=u,e2[et][1]=v,e2[et][2]=w;
			if(w) add(u,v);
		}
		head=tail=0;
		for(int i=1;i<=n;i++)
			if(!f[i]) q[++tail]=i;
		while(head<tail)
		{
			head++;
			int u=q[head];
		//	printf("u=%d,head=%d\n",u,head);
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].v;
				f[v]--;
				if(!f[v])
				{
					q[++tail]=v;
				}
			}
		}
		if(tail!=n)
		{
			printf("NO\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			c[q[i]]=i;
		printf("YES\n");
		for(int i=1;i<=m;i++)
		{
			if(e2[i][2]) printf("%d %d\n",e2[i][0],e2[i][1]);
			else
			{
				int u=e2[i][0],v=e2[i][1];
				if(c[u]<c[v]) printf("%d %d\n",u,v);
				else printf("%d %d\n",v,u);
			}
		}
	}
	return 0;
}