#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,m,k,a[500005],dis[2][500005],vis[500005],q[500005],head,tail;
int b[500005],c[500005],h[500005],t;
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
bool cmp1(const int x,const int y)
{
	return dis[0][x]<dis[0][y];
}
bool cmp2(const int x,const int y)
{
	return dis[1][x]<dis[1][y];
}
void bfs(int s,int fl)
{
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	dis[fl][s]=0;
	head=0;
	tail=1;
	q[1]=s;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]) continue;
			vis[v]=1;
			dis[fl][v]=dis[fl][u]+1;
			q[++tail]=v;
		}
	}
}
bool check(int x)
{
	for(int i=1;i<=k;i++)
	{
		int nw=lower_bound(b+1,b+k+1,x-c[i]-1)-b;
		if(nw==i) nw++;
		if(nw==k+1) continue;
		//printf("x=%d,i=%d,nw=%d,b=%d,%d,c=%d,%d\n",x,i,nw,b[i],b[nw],c[i],c[nw]);
		if(c[nw]+b[i]+1>=x) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	bfs(1,0);
	bfs(n,1);
	sort(a+1,a+k+1,cmp1);
	for(int i=1;i<=k;i++)
		b[i]=dis[0][a[i]],c[i]=dis[1][a[i]];
	for(int i=k-1;i>=1;i--)
		c[i]=max(c[i],c[i+1]);
	int l=0,r=dis[0][n];
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d",r);
	return 0;
}