#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[1000005],g[1000005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
	g[y]=min(g[y],g[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+1;i++)
	{
		g[i]=1e9;
		f[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int op,t,l,r;
		scanf("%d",&op);
		if(op==0)
		{
			scanf("%d%d%d",&l,&r,&t);
			if(t==1)
			{
				int u=find(l);
				g[u]=min(g[u],r);
			}
			else
			{
				int u=find(l);
				while(u<=r)
				{
					link(u,u+1);
					u=find(u);
				}
			}
		}
		else
		{
			int x;
			scanf("%d",&x);
			if(f[x]!=x) printf("NO\n");
			else
			{
				int u=find(x+1);
				if(u>g[x]) printf("YES\n");
				else printf("N/A\n");
			}
		}
	}
	return 0;
}