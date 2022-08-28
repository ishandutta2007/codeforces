#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[5000005];
int T,n,m,f[100005],g[100005],vis[100005],h[100005],cnt[100005],pn=1e5,t,at;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	for(int i=1;i<=pn;i++)
		cnt[i]=cnt[i/2]+i%2;
	scanf("%d",&T);
	while(T--)
	{
		t=at=0;
		scanf("%d",&n);
		m=n;
		n=(1<<n);
		for(int i=0;i<=n;i++)
			h[i]=0,vis[i]=f[i]=0;
		for(int i=1;i<=m*n/2;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		f[0]=0;
		vis[0]=1;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(vis[j]) continue;
				int ct=0,q=0;
				for(int k=h[j];k;k=e[k].nxt)
				{
					int v=e[k].v;
					ct+=(vis[v]==i);
					q|=f[v];
				}
				if(ct==i)
				{
					vis[j]=i+1;
					if(i==1) q=(1<<(at++));
					f[j]=q;
				}
			}
		}
		for(int i=0;i<n;i++)
			g[f[i]]=i;
		for(int i=0;i<n;i++)
			printf("%d ",g[i]);
		printf("\n");
		if((m&-m)!=m)
		{
			printf("-1\n");
			continue;
		}
		for(int i=0;i<n;i++)
		{
			int ans=0;
			for(int j=0;j<m;j++)
				if(f[i]&(1<<j))
					ans^=j;
			printf("%d ",ans);
		}
		printf("\n");
	}
	return 0;
}