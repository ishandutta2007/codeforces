#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+1;
int head[N],cnt,n,m,d[N],dep[N],ans[N],fa[N],ans1[N],pre[N],ret[N];
struct nd{int ne,to;}e[N*2];
void in(int x,int y){e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;}
bool vis[N];
bool check()
{
	int cnt1=0;
	for(int i=1;i<=n;++i)if(d[i]==1)cnt1++;
	for(int i=1;i<=n;++i)
	if(d[i]==-1)
	{
		d[i]=(cnt1%2?1:-1);
		return 1;
	}
	return !(cnt1%2);
}

void dfs(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].ne)
	if(!vis[e[i].to])
	{
		fa[e[i].to]=x;
		dep[e[i].to]=dep[x]+1;
		pre[e[i].to]=(i+1)/2;
		dfs(e[i].to);
	}
}
void dfs1(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].ne)
	if(!vis[e[i].to]&&(fa[e[i].to]==x))
	{
		dfs1(e[i].to);
		ans[x]+=ans[e[i].to];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",d+i);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),in(x,y),in(y,x);
	if(check())
	{
		dep[1]=1;
		dfs(1);
		for(int i=1;i<=n;++i)if(d[i]==1)ans[i]++;
		memset(vis,0,sizeof(vis));
		dfs1(1);
		for(int i=1;i<=n;++i)ans1[pre[i]]=ans[i];
		for(int i=1;i<=m;++i)if(ans1[i]%2==1)ret[++ret[0]]=i;
		for(int i=0;i<=ret[0];++i)printf("%d\n",ret[i]);
	}
	else printf("-1");
}