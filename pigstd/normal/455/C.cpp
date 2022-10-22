#include<bits/stdc++.h>
using namespace std;

const int M=3*1e5+10;
int f[M],c[M],n,m,q,dis[M];
bool vis[M];

struct egde
{
	int to,next;
}e[M*2];int cnt,head[M];
void adde(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

int find(int x)
{
	if (f[x]==x)return x;
	else return f[x]=find(f[x]);
}

int maxp;
void dfs(int u,int fa)// 
{
	if (dis[u]>dis[maxp])maxp=u;
	for (int i=head[u];i;i=e[i].next)
		if (e[i].to!=fa)
			dis[e[i].to]=dis[u]+1,dfs(e[i].to,u);
} 

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
		f[i]=i;
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		f[find(a)]=find(b);
		adde(a,b),adde(b,a);
	}
	for (int i=1;i<=n;i++)
		if (!vis[find(i)])
		{
			maxp=0,dis[0]=-1;dfs(i,0);
			int st=maxp;maxp=0,dis[0]=-1,dfs(st,0);
			int ed=maxp;c[find(i)]=abs(dis[st]-dis[ed]),vis[find(i)]=1;
		}
	while(q--)
	{
		int a;
		scanf("%d",&a);
		if (a==1)
		{
			int b;
			scanf("%d",&b);
			printf("%d\n",c[find(b)]);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (find(x)!=find(y))
			{
				c[find(y)]=max(max(c[find(x)],c[find(y)]),(c[find(x)]+1)/2+(c[find(y)]+1)/2+1);
				f[find(x)]=find(y);
			}
		}
	}
	return 0;
}