#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[100005],mp[2005][2005],in[2005],vis[2005],q[200005],dis[200005],head=0,tail=0,cnt=0;
char a[1005][1005];
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
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf(" %c",&a[i][j]);
	for(int i=1;i<=n+m;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]=='=')
				link(i,n+j);
	for(int i=1;i<=n+m;i++)
		vis[find(i)]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x=find(i),y=find(n+j);
			if(x==y&&a[i][j]!='=')
			{
				printf("No");
				return 0;
			}
			if(a[i][j]=='<')
			{
				if(mp[x][y]==0) in[y]++;
				mp[x][y]=1;
			} 
			else if(a[i][j]=='>')
			{
				if(mp[y][x]==0) in[x]++;
				mp[y][x]=1;
			}
		}
	/*for(int i=1;i<=n+m;i++)
	{
		for(int j=1;j<=n+m;j++)
			printf("%d",mp[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n+m;i++)
	{
		if(vis[i]&&in[i]==0)
		{
			q[++tail]=i;
			dis[i]=1;
		}
		if(vis[i])
		{
			cnt++;
			//printf("i=%d\n",i);
		}
	}
	while(head<tail)
	{
		head++;
		int u=q[head];
		//printf("u=%d\n",u);
		for(int i=1;i<=n+m;i++)
			if(mp[u][i])
			{
				in[i]--;
				dis[i]=max(dis[i],dis[u]+1);
				if(in[i]==0)
					q[++tail]=i;
			}
	}
	if(tail<cnt)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(int i=1;i<=n;i++)
		printf("%d ",dis[find(i)]);
	printf("\n");
	for(int i=1;i<=m;i++)
		printf("%d ",dis[find(i+n)]);
	return 0;
}