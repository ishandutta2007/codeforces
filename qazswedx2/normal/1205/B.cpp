#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,cnt[105],g[105][105],dis[105],vis[105],ans=100000000,q[100005],head,tail;
ll a[100005];
void bfs(int s,int t,int c)
{
	if(dis[s]+1<ans) ans=dis[s]+1;
	dis[s]=1;
	vis[s]=c;
	head=0,tail=1;
	q[1]=s;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=1;i<=n;i++)
		{
			if(!g[u][i]) continue;
			int v=i;
			if(vis[v]==c||v==t) continue;
			if(dis[v]+dis[u]+1<ans) ans=dis[v]+dis[u]+1;
			vis[v]=c;
			if(dis[v]>dis[u]+1)
			{
				dis[v]=dis[u]+1;
				q[++tail]=v;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		for(ll j=0;j<=62;j++)
			if(a[i]&(1ll<<j))
				cnt[j]++;
	}
	for(int j=0;j<=62;j++)
		if(cnt[j]>2)
		{
			printf("3\n");
			return 0;
		}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j!=i&&(a[i]&a[j]))
				g[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0x3f,sizeof(vis));
		dis[i]=0;
		int nw=0;
		for(int j=1;j<=n;j++)
			if(g[i][j])
			{
				nw++;
				bfs(j,i,nw);
			}
	}
	if(ans!=100000000) printf("%d",ans);
	else printf("-1");
	return 0;
}