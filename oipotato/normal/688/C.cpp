#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,u,v,du[100010],head[100010],next[200010],to[200010],que[100010],t,w,num,a[100010],b[100010],len1,len2;
bool vis[100010],color[100010];
void add(int u,int v){next[++num]=head[u];to[head[u]=num]=v;}
void bfs(int x)
{
	que[w=1]=x;vis[x]=1;t=0;
	for(;t<w;)
	{
		int u=que[++t];
		for(int i=head[u];i;i=next[i])
		if(!vis[to[i]])
		{
			que[++w]=to[i];
			color[to[i]]=color[u]^1;
			vis[to[i]]=1;
		}
		else if(color[u]==color[to[i]]){printf("-1");exit(0);}
	}
}
int main()
{
	//freopen("3.in","r",stdin);
	//freopen("3.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){scanf("%d%d",&u,&v);add(u,v);add(v,u);du[u]++;du[v]++;}
	for(int i=1;i<=n;i++)if(!vis[i]&&du[i])bfs(i);
	for(int i=1;i<=n;i++)if(vis[i]){if(color[i])a[++len1]=i;else b[++len2]=i;}
	printf("%d\n",len1);for(int i=1;i<=len1;i++)printf("%d ",a[i]);printf("\n");
	printf("%d\n",len2);for(int i=1;i<=len2;i++)printf("%d ",b[i]);
	return 0;
}