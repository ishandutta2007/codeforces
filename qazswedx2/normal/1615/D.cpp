#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,e[1000005][3],f[1000005],g[1000005];
int find(int x)
{
	if(f[x]==x) return x;
	int u=find(f[x]);
	g[x]^=g[f[x]];
	return f[x]=u;
}
void link(int x,int y,int w)
{
	int xx=find(x),yy=find(y);
	if(x==y) return;
	f[xx]=yy;
	g[xx]=w^g[x]^g[y];
}
int check(int x,int y)
{
	int u=find(x),v=find(y);
	if(u!=v) return -1;
	return g[x]^g[y];
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			f[i]=i,g[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e[i][0]=u,e[i][1]=v,e[i][2]=w;
			if(w!=-1)
			{
				int nw=w,q=0;
				while(nw)
				{
					q^=1;
					nw-=nw&(-nw);
				}
				link(u,v,q);
			}
		}
		int fl=1;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			int q=check(u,v);
		//	printf("i=%d,u=%d,v=%d,q=%d\n",i,u,v,q);
			if(q==(w^1)) fl=0;
			else link(u,v,w);
		}
		if(fl==0)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<n;i++)
		{
			if(e[i][2]!=-1) printf("%d %d %d\n",e[i][0],e[i][1],e[i][2]);
			else
			{
				int q=check(e[i][0],e[i][1]);
				if(q==-1)
				{
					q=0;
					link(e[i][0],e[i][1],q);
				}
				printf("%d %d %d\n",e[i][0],e[i][1],q);
			}
		}
	}
}